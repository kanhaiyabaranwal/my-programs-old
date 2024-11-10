#include<iostream>
#include<queue>
#include<functional>
using namespace std;

namespace PriorityQueue_NS79
{
	template<typename T>
	struct less
	{
		inline bool operator()(const T& a, const T& b) { return a < b; }
	};
	template<typename T>
	struct greater
	{
		inline bool operator()(const T& a, const T& b) { return a > b; }
	};

	template<typename T, typename compareOp = less<T> >
	class PriorityQueue
	{
	public:
		PriorityQueue(int _capacity) : capacity(_capacity), length(0), arr(NULL) { arr = new T[capacity]; }
		~PriorityQueue() { if (arr) delete[] arr; }
		int size() { return length; }
		void push(const T& data);
		void pop();
		T top() { return length > 0 ? arr[0] : T(); }
	private:
		compareOp compare;
		int capacity;
		int length;
		T* arr;
		void heapify(int i);
		void swap(T& a, T&b) { T t = a; a = b; b = t; }
		int parent(int i) { return (i - 1) / 2; }
		int left(int i) { return 2 * i + 1; }
		int right(int i) { return 2 * i + 2; }
	};


	template<typename T, typename compareOp>
	void PriorityQueue<T, compareOp>::heapify(int index)
	{
		int l = left(index);
		int r = right(index);
		int top = index;
		top = l < length && compare(arr[top], arr[l]) ? l : top;
		top = r < length && compare(arr[top], arr[r]) ? r : top;
		if (top != index)
		{
			swap(arr[top], arr[index]);
			heapify(top);
		}
	}

	template<typename T, typename compareOp>
	void PriorityQueue<T, compareOp>::push(const T& data)
	{
		if (length == capacity) // todo we should resize
			return;
		int i = length; length++;
		arr[i] = data;
		while (i != 0 && compare(arr[parent(i)], arr[i]))
		{
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}
	}

	template<typename T, typename compareOp>
	void PriorityQueue<T, compareOp>::pop()
	{
		if (length <= 0) return;
		length--;
		if (length == 0) return;
		swap(arr[length], arr[0]);
		heapify(0);
	}


	void testPriorityQueue()
	{
		//PriorityQueue<int, greater<int> > pq(100);
		//PriorityQueue<int, less<int> > pq(100);

		//PriorityQueue<int, std::greater<int> > pq(100);
		PriorityQueue<int, std::less<int> > pq(100);

		//std::priority_queue<int,vector<int>, std::greater<int> > pq;
		//std::priority_queue<int,vector<int>, std::less<int> > pq;

		pq.push(1);
		pq.push(5);
		pq.push(2);
		pq.push(4);
		pq.push(8);

		int z = int();
		while(pq.size())
		{
			z = pq.top(); pq.pop();
			cout<<z<<",";	
		}
		
		
		/*z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		z = pq.top(); pq.pop();
		*/
	}
}

int main()
{
	PriorityQueue_NS79::testPriorityQueue();
	return 0;
}
