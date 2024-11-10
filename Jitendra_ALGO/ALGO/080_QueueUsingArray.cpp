#include<iostream>
using namespace std;
namespace Queue_NS80
{
	template<typename T>
	class  Queue
	{
	public:
		Queue(int capacity) :_capacity(capacity), _arr(NULL), _front(-1), _back(-1), _size(0) { _arr = new T[_capacity]; };
		~Queue() { if (_arr) delete[] _arr; }
		T front() { return _front != -1 ? _arr[_front] : T(); }
		int size() { return _size; }
		void push(const T& data); //push_back
		void pop(); //pop_front
	private:
		int _capacity;
		T* _arr;
		int _front, _back;
		int _size;
	};

	template<typename T>
	void Queue<T>::push(const T & data)
	{
		if (_size == _capacity) return; // overflow
		_size++;
		_back = (_back + 1) % _capacity;
		_arr[_back] = data;
		if (_front == -1)
			_front = _back;
	}

	template<typename T>
	void Queue_NS80::Queue<T>::pop()
	{
		if (_size == 0) return; //underflow
		_size--;
		if (_size == 0) { _front = _back = -1; }
		else { _front = (_front + 1) % _capacity; }
	}


	void testQueue()
	{

		Queue<int> q(5);

		int f = q.front();
		q.push(1);
		q.push(2);
		f = q.front(); q.pop();
		q.push(3);
		q.push(4);
		f = q.front(); q.pop();
		q.push(5);

		q.push(11);
		q.push(22);
		f = q.front(); q.pop();
		f = q.front(); q.pop();
		f = q.front(); q.pop();
		f = q.front(); q.pop();
		f = q.front(); q.pop();
		f = q.front(); q.pop();
	}

}

int main_80()
{
	Queue_NS80::testQueue();
	return 0;
}