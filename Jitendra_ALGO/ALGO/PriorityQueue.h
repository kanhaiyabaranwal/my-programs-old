#ifndef __SAMAL_PRIORITY_QUEUE__
#define __SAMAL_PRIORITY_QUEUE__
#include<algorithm>
#include<functional>
namespace samal
{
	/*
	TODO :- Need add resize logic
	Algo: creat a heap tree via array and add remove element and heapity it
	*/
	static const size_t DEFAULT_PRIORITY_QUEUE_SIZE = 100; 
	template<class T, class compare = std::less_equal<T> >
	class PriorityQueue
	{
	public:
		PriorityQueue(size_t capacity=DEFAULT_PRIORITY_QUEUE_SIZE):
		  _capacity(capacity),_length(0){ /*_array = new T[_capacity]; */	}
		  ~PriorityQueue(){/*delete _array;*/}
		  T peek() { return _array[0]; }
		  void add(T v);
		  size_t find(T v);
		  void remove(T v);
		  void removeAt(size_t pos);		

	private:
		size_t _capacity;
		size_t _length;
		//T* _array;
		T _array[100];
		//void addUtil(T v, size_t pos);
		void heapify(size_t pos);
		inline void swap(size_t i, size_t j)
		{
			if(i==j) return;
			T tmp = _array[i];
			_array[i] = _array[j];
			_array[j] = tmp;
		}

		size_t parent(size_t i)
		{
			if(i <= 0) 	return -1;
			return ( i-1) /2;
		}
		size_t left(size_t i)  
		{ 
			return (2*i +1); 
		}
		size_t right(size_t i) 
		{ 
			return 2*(i+1);  
		}
	};
	template<class T, class compare>
	void PriorityQueue<T,compare>::heapify(size_t pos)
	{
		size_t newHead = pos;
		size_t l = left(pos);
		size_t r = right(pos);
		if( l <_length && !compare()(_array[pos],_array[l]) )
			newHead = l;
		if( r <_length && !compare()(_array[pos],_array[r]) )
			newHead = r;
		if(pos != newHead)
		{
			swap(pos,newHead);
			heapify(newHead);
		}
	}
	template<class T, class compare>
	void PriorityQueue<T,compare>::add(T v)
	{
		if(_length >= _capacity)
			return ; //TODO resize
		_array[_length++] = v;
		size_t p = parent(_length-1);
		while(p != -1)
		{
			heapify(p);
			p = parent(p);
		}
	}

	template<class T, class compare>
	size_t PriorityQueue<T,compare>::find(T v)
	{
		for(size_t i = 0; i<_length; i++)
		{
			if(_array[i] == v)
				return i;
		}
		return -1;
	}

	template<class T, class compare>
	void PriorityQueue<T,compare>::remove(T v)
	{
		removeAt(find(v));
	}

	template<class T, class compare>
	void PriorityQueue<T,compare>::removeAt(size_t pos)
	{
		if(_length < 0 || pos < 0 || pos >= _length)
			return ; 
		swap(pos,--_length);
		heapify(pos);
	}
}
#endif
