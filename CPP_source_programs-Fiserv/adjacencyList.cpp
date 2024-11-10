//Graph using Adjacency list
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define NBR_OF_VERTICES 5

struct Node{
	int NodeNbr;
	Node* next;
	Node(int nbr, Node* n=0):NodeNbr(nbr),next(n) {}
	
};
struct List{
	Node* head;		//each list is a pointer of nodes
	List(Node *n):head(n) {}
};

struct Graph{
	int V;
	List *arr;		//list is really the pointer to pointers of nodes, each adjacency list corresponds to a vertex. So it shows all vertices merging to it.
	Graph(int NbrOfVertices):V(NbrOfVertices) {
		arr=(List*)malloc(V*sizeof(List));
		for(int i=0;i<V;i++)
		{
			arr[i].head=new Node(i);
		}
	}
	void addEdge(int node1, int node2){
		//one direction, for list with node1 as head to node2
		Node *newNode=new Node(node2,arr[node1].head->next);
		arr[node1].head->next=newNode;
		//reverse direction, for list with node2 as head to node1
		newNode=new Node(node1,arr[node2].head->next);
		arr[node2].head->next=newNode;
	}
};

int main()
{
	cout<<"It's adjacency list\n";
	cout<<"Grapth with Nbr of vertices="<<NBR_OF_VERTICES<<endl;
	int nbr=NBR_OF_VERTICES;
	Graph g(nbr);
	//traverses through the newly built graph
	//add edge statically
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	for(int i=0;i<g.V;i++)
	{
		cout<<i+1<<"th header is "<<g.arr[i].head->NodeNbr<<" and adjacency list is ";
		Node* tempnode = g.arr[i].head;
		cout<<tempnode->NodeNbr;
		while(tempnode->next)
		{
			cout<<"->"<<tempnode->next->NodeNbr;
			tempnode=tempnode->next;
		}
		cout<<endl;
	}
	//g.addEdge()
	return 0;
}