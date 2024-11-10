/*
http://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
http://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
http://www.geeksforgeeks.org/branch-bound-set-5-traveling-salesman-problem/
https://www.youtube.com/watch?v=-JjA4BLQyqE

Traveling Salesman Problem Dynamic Programming Held-Karp
Branch And Bound | Set 6 (Traveling Salesman Problem)
Travelling Salesman Problem | Set 1 (Naive and Dynamic Programming)
Travelling Salesman Problem | Set 2 (Approximate using MST)
*/
#if 0
#include<iostream>
using namespace std;
namespace NS13
{
	const int INF = 9999;
	struct Node;
	struct NodeList
	{
		Node* data;
		NodeList* next;
		NodeList():data(NULL),next(NULL){}
		NodeList(Node* n) {}
		void append(Node* n){}
	};
	struct Node
	{
		int key;
		int hashKey;
		int cost;
		int parent;
		NodeList* path; 
		Node(int _key, NodeList* _path)
		{
			key = _key; path = _path;
			hashKey = key; cost = INF;
			NodeList* tmp = path;
			int mul = 10;
			while(tmp)
			{
				Node* p = tmp->data;
				if(p) 
				{
					hashKey = hashKey + mul * p->key;
					mul *= 10;
				}
				tmp = tmp->next;
			}
		}
	};

	//key= int, value = struct node, primeNumber = 7919
	class HashMap{
	public:
		HashMap(int _capacity=7919):capacity(_capacity)
		{
			valueArray = new NodeList*[capacity];
			for(int i=0; i<capacity;i++)
				valueArray[i] = NULL;
		}
		~HashMap()
		{
			if(valueArray != NULL) delete[] valueArray;
		}
		void insert(int key, Node* data)
		{
			int index = key % capacity;
			if(valueArray[index] != NULL)
			{
				valueArray[index]->append(data);
			}
			{
				valueArray[index] = new NodeList(data);
			}
		}
		Node* get(int key)
		{
			int index = key % capacity;
			NodeList* list = valueArray[index];
			while(list)
			{
				if(list->data && list->data->hashKey == key)
					return list->data;
				list = list->next;
			}
			return NULL;
		}
	private:
		int capacity;
		NodeList** valueArray;

	};

}

int main_13()
{

}
#endif
