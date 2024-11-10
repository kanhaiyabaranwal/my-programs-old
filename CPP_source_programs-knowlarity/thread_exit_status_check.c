#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * main_thread(void * param) {
  while (1) {
	printf("I'm inside main_thread,pid=%d\n",getpid());
	sleep(5);
  }
}

int main(int argc, char *argv[]) {

int result = 0;

pthread_attr_t attr;
pthread_t thread;
result = pthread_attr_init(&attr);
printf ("attr init : %d\n", result);

result = pthread_attr_setstacksize(&attr, 1024);
printf ("attr set stack: %d\n", result);

result = pthread_create (&thread, &attr, main_thread, NULL);
printf ("create new thread: %d\n", result);

result = pthread_detach(pthread_self());
printf ("detach main thread: %d\n", result);

pthread_exit (NULL);


return 0;

}
