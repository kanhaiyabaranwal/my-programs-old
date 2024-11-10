//Topoligcal sorting of a Directed Acyclic Graph using Adjacency list
//The algo uses stack to put nodes from last node to the start node
//The algo uses backtrack to visit all nodes in the adjacency list
//For convenience of user, graph uses fixed no. of edges and vertices
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;
#define NBR_OF_VERTICES 6
static stack<int> sint;

struct Node{
	int NodeNbr;
	int IsVisited;
	Node* next;
	Node(int nbr, Node* n=0):NodeNbr(nbr),next(n),IsVisited(0) {}
	
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
		//directed graph has one direction only, for list with node1 as head to node2
		Node *newNode=new Node(node2,arr[node1].head->next);
		arr[node1].head->next=newNode;
	}
};
void top_sort(Graph &g,Node *head)
{
	
	Node *curHeadNode=head;
	Node* curNode=curHeadNode;
	int nodenum;
	while( curNode)
	{
		if(curNode->IsVisited==1)
			return;
		else
		{
			if(curNode->next==NULL)			// no more node, reached last
			{
				g.arr[curNode->NodeNbr].head->IsVisited=1;	//mark list as visited
				//cout<<"Next Node visited-"<<curHeadNode->NodeNbr<<endl;
				sint.push(curHeadNode->NodeNbr);
				return;
			}
		}
		curNode=curNode->next;
		nodenum=curNode->NodeNbr;
		top_sort(g,g.arr[nodenum].head);	//visit head which corresponds to next node
		g.arr[curNode->NodeNbr].head->IsVisited=1;	//mark list as visited
	}	
	g.arr[curHeadNode->NodeNbr].head->IsVisited=1;
	//cout<<"Next Node visited-"<<curHeadNode->NodeNbr<<endl;
	sint.push(curHeadNode->NodeNbr);
}

void topoligcal_sort(Graph &g)
{
	for(int i=0;i<NBR_OF_VERTICES;i++)
	{
		Node* nextListHead=g.arr[i].head;
		if(nextListHead->IsVisited==0)
			top_sort(g,nextListHead);
			//g.arr[i].head->IsVisited=1;
			//cout<<"arr["<<i<<"]="<<g.arr[i].head->IsVisited<<endl;
	}
	cout<<"traversing in topological order"<<endl;
	while(!sint.empty())
	{
		cout<<sint.top()<<" ";
		sint.pop();
	}
}
int main()
{
	cout<<"Grapth with Nbr of vertices="<<NBR_OF_VERTICES<<endl<<endl;
	cout<<"Graph Representation through adjacency list\n";
	int nbr=NBR_OF_VERTICES;
	Graph g(nbr);
	//add edge statically
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(3,2);
	g.addEdge(3,1);
	g.addEdge(3,4);
	g.addEdge(2,1);
	g.addEdge(4,5);
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
	cout<<endl<<endl;
	topoligcal_sort(g);
	return 0;
}


