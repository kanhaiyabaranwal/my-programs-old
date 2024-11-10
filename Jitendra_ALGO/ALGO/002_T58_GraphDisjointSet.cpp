#ifndef __GraphDisjointSet__
#define __GraphDisjointSet__

#include<map>

using namespace std;

template<typename T>
class DisjointSet
{
public:
	struct Node
	{
		T obj;
		//This will point to the parent/leader of the set, and will
		//point to it self if the current node is representing leader
		Node *leader;
		// Rank will useful to chose next leader when we join two set
		int rank; 
		Node(T obj1) : obj(obj1),rank(0){leader = this;}
	};
	//This method will create a new set with only one element in it
	void makeSet(T obj)	{_map[obj] = new Node(obj);}
	//this returns the top leader of the node and compress it
	// so that next time we dont need to travel long path to find leader
	Node* findSet(T obj) 
	{ 
		Node* result = _map[obj];
		while(result->leader != result)
			result = result->leader;
		_map[obj]->leader = result; // compressing
		return result;
	}
	//This method takes two nodes and return if they represented by same set
	bool isInSameSet(T obj1, T obj2)
	{
		Node* leader1 = findSet(obj1);
		Node* leader2 = findSet(obj2);
		return (leader1->obj == leader2->obj);
	}
	/*
	This method join sets of two node, commonly known as Union operation
	Algo:
		1) Find the top leader of both set
		2) If both nodes are already in same set, then do nothing
		3) Else join the leaders
		3) When both leaders are of same rank then increase the rank and join
	*/
	void join(T obj1, T obj2)
	{
		Node* leader1 = findSet(obj1);
		Node* leader2 = findSet(obj2);

		if(leader1->obj == leader2->obj)
			return;
		if(leader1->rank >= leader2->rank)
		{
			if(leader1->rank == leader2->rank)
				leader1->rank++;
			leader2->leader = leader1;
		}
		else
		{
			leader1->leader = leader2;
		}
	}

private:
	//map key is the node and value is the immidate leader of current node
	map<T,Node*> _map;
};


#endif