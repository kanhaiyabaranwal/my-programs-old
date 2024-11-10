/*
http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
http://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/
http://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/

Clone a linked list with next and random pointer 
Clone a linked list with next and random pointer in O(1) space
Clone a linked list with next and random pointer | Set 2
---------------------------------------------------------
Given a linked list having two pointers in each node. 
The first one points to the next node of the list, however the other pointer 
is random and can point to any node of the list. 
Write a program that clones the given list in O(1) space, i.e., without any extra space.
*/

#include <iostream>
using namespace std;
namespace NS70
{
	struct Node
	{
		int data;
		Node *next,*random;
		Node(int x)
		{
			data = x;
			next = random = NULL;
		}
	};
	void print(Node *start)
	{
		Node *ptr = start;
		while (ptr)
		{
			cout << "Data = " << ptr->data << ", Random  = ";
			if(ptr->random)
				cout << ptr->random->data ;
			else
				cout << "NULL";
			cout << endl;
			ptr = ptr->next;
		}
	}
	Node* clone(Node *start)
	{
		if(!start) return NULL;
		Node* curr = start; Node* tmp;
		//Create new node and point current next to new node
		//and new node's next pointer to current next ptr
		//i.e. inserting new node in the middle of org list
		while(curr)
		{
			tmp = curr->next;
			curr->next = new Node(curr->data);
			curr->next->next = tmp;
			curr = tmp;
		}
		//Adjust the random pointer of new list
		curr = start;
		while(curr)
		{
			curr->next->random = curr->random ? curr->random->next : NULL;
			curr = curr->next->next;
		}
		//save start of new list and split two lists
		curr = start;
		Node* newList = curr->next;
		while(curr)
		{
			tmp = curr->next; // newly created ptr
			curr->next = tmp->next; // revert back org list
			tmp->next = curr->next ? curr->next->next : NULL; // adjust next ptr of new node
			curr = curr->next; //increment current ptr
		}
		return newList;
	}
	void test()
	{
		Node* start = new Node(1);
		start->next = new Node(2);
		start->next->next = new Node(3);
		start->next->next->next = new Node(4);
		start->next->next->next->next = new Node(5);
		// 1's random points to 3
		start->random = start->next->next;
		// 2's random points to 1
		start->next->random = start;
		// 3's and 4's random points to 5
		start->next->next->random = start->next->next->next->next;
		start->next->next->next->random = start->next->next->next->next;
		// 5's random points to 2
		start->next->next->next->next->random = start->next;
		cout << "Original list : \n";
		print(start);
		cout << "\nCloned list : \n";
		Node *cloned_list = clone(start);
		print(cloned_list);
		cout << "\nOriginal list after processing clone finction : \n";
		print(start);
	}
}
int main_70()
{
	NS70::test();
	return 0;
}