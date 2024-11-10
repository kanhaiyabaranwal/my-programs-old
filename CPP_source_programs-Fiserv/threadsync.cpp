#include<iostream>
#include<pthread.h>
#include<errno.h>
#include<memory>
using namespace std;
class Thread;
void assert(Thread *t)
{
	if(!t)
		std::cout<<"Problem creating thread"<<endl;
	exit (-1);
}
void PrintError(char* msg, int status, char* fileName, int lineNumber) 
{
	std::cout << msg << ' ' << fileName << ":" << lineNumber << "- " << strerror(status) << std::endl;
}

class Runnable {
public:
virtual void* run() = 0;
virtual~Runnable() = 0;
};
// a function body is required for pure virtual destructors
Runnable::~Runnable() {}
class Thread {
public:
	Thread(auto_ptr<Runnable> runnable_, bool isDetached = false);
	Thread(bool isDetached = false);
	virtual~Thread();
	void start();
	void* join();
private:
	pthread_t PthreadThreadID; // thread ID
	bool detached; // true if thread created in detached state; false otherwise
	pthread_attr_t threadAttribute;
	auto_ptr<Runnable> runnable;
	Thread(const Thread&);
	const Thread& operator= (const Thread&);
	void setCompleted();
	void* result; // stores return value of run()
	virtual void* run() {return 0;}
	static void* startThreadRunnable(void* pVoid);
	static void* startThread(void* pVoid);
	void PrintError(char* msg, int status, char* fileName, int lineNumber);
};
Thread::Thread(auto_ptr<Runnable> runnable_, bool isDetached) : runnable(runnable_),detached(isDetached){
	if (runnable.get() == NULL) 
	{
		std::cout << "Thread::Thread(auto_ptr<Runnable> runnable_, bool isDetached) failed at " << ' ' << __FILE__ << ":" << __LINE__ << "- " << "runnable is NULL " << std::endl; exit(-1);
	}
}
Thread::Thread(bool isDetached) : runnable(NULL), detached(isDetached){ }
void* Thread::startThreadRunnable(void* pVoid)
{
	// thread start function when a Runnable is involved
	Thread* runnableThread = static_cast<Thread*> (pVoid);
	//assert(runnableThread);
	runnableThread->result = runnableThread->runnable->run();
	runnableThread->setCompleted();
	return runnableThread->result;
}
void* Thread::startThread(void* pVoid) 
{
	cout<<"startThread running\n";
	// thread start function when no Runnable is involved
	Thread* aThread = static_cast<Thread*> (pVoid);
	//assert(aThread);
	aThread->result = aThread->run();
	cout<<"from startThread, run call finished\n";
	aThread->setCompleted();
	return aThread->result;
}
Thread::~Thread() { }
void Thread::start() 
{
	cout<<"starting thread"<<endl;
	int status = pthread_attr_init(&threadAttribute); // initialize attribute object
	if (status != 0) 
	{ PrintError("pthread_attr_init failed at", status, __FILE__, __LINE__); exit(status);}

	status = pthread_attr_setscope(&threadAttribute, PTHREAD_SCOPE_SYSTEM);
	if (status != 0) 
	{ 
		PrintError("pthread_attr_setscope failed at", status, __FILE__, __LINE__); exit(status);
	}
	cout<<"attribute initialized and scope attr set to PTHREAD_SCOPE_SYSTEM\n";
	if (!detached) 
	{
		cout<<"thread attr is non-detachable"<<endl;
		if (runnable.get() == NULL) 
		{
			int status = pthread_create(&PthreadThreadID,&threadAttribute, Thread::startThread,(void*) this);
			if (status != 0) { PrintError("pthread_create failed at", status, __FILE__, __LINE__); exit(status);}
		}
		else 
		{
		int status = pthread_create(&PthreadThreadID,&threadAttribute, Thread::startThreadRunnable, (void*)this);
		if (status != 0) {PrintError("pthread_create failed at", status, __FILE__, __LINE__); exit(status);}
		}
	}
	else 
	{
		// set the detachstate attribute to detached
		status = pthread_attr_setdetachstate(&threadAttribute, PTHREAD_CREATE_DETACHED);
		if (status != 0){
		PrintError("pthread_attr_setdetachstate failed at", status,__FILE__,__LINE__);exit(status);
		}
		if (runnable.get() == NULL) 
		{
			status = pthread_create(&PthreadThreadID,&threadAttribute, Thread::startThread, (void*) this);
			if (status != 0) {PrintError("pthread_create failed at", status, __FILE__, __LINE__);exit(status);}
		}
		else 		
		{
			status = pthread_create(&PthreadThreadID,&threadAttribute, Thread::startThreadRunnable, (void*) this);
			if (status != 0) {PrintError("pthread_create failed at", status, __FILE__, __LINE__); exit(status);}
		}
	}
	cout<<"thread created\n";
	status = pthread_attr_destroy(&threadAttribute);
	if (status != 0) { PrintError("pthread_attr_destroy failed at", status, __FILE__, __LINE__); exit(status);}
	cout<<"thread started\n";
}

void* Thread::join() 
{
	int status = pthread_join(PthreadThreadID,NULL);
	// result was already saved by thread start functions
	if (status != 0) 
		{ PrintError("pthread_join failed at", status, __FILE__, __LINE__); exit(status);}
	return result;
}
void Thread::setCompleted() {/* completion was handled by pthread_join() */}
void Thread::PrintError(char* msg, int status, char* fileName, int lineNumber)
{/*see Listing 1.4 */}




int s=0; // shared variable s
class communicatingThread: public Thread 
{
public:
	communicatingThread (int ID) : myID(ID) {}
	virtual void* run();
private:
	int myID;
};
void* communicatingThread::run() 
{
	std::cout << "Thread " << myID << "is running" << std::endl;
	for (int i=0; i<10000000; i++) // increment s 10 million times
		s = s + 1;
	return 0;
}
int main() {
	std::cout<<"kanhaiya"<<endl;
	std::auto_ptr<communicatingThread> thread1(new communicatingThread (1));
	std::auto_ptr<communicatingThread> thread2(new communicatingThread (2));
	std::cout<<"kanhaiya1"<<endl;
	thread1->start(); 
	thread2->start();
	cout<<"kanhaiya after starting 2 threads\n";
	thread1->join(); 
	cout<<"kanhaiya joined from thread1\n";
	thread2->join();
	std::cout<<"kanhaiya2"<<endl;
	
	std::cout << "s: " << s << std::endl; // expected final value of s is 20000000
	return 0;
}
