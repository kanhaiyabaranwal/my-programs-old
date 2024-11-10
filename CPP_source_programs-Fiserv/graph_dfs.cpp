#include<iostream>
#include<list>
using namespace std;

class Graph{
	int v;
	list<int> *larray;
	int *visited;
	public:
	Graph(int v):v(v) {
		larray=new list<int>[v];
		visited=new int[v];
		for(int i=0;i<v;i++)
		{
			larray[i].push_back(i);
			visited[i]=0;
		}
	}
	void addEdge(int v,int w)
	{
		larray[v].push_back(w);
	}
	void DFS(int head);
	void visitV(int n)
	{
		cout<<"Visiting Adjacency list of vertex "<<n<<" : ";
		list<int>::const_iterator iter=larray[n].begin();
		while(iter!=larray[n].end())
			cout<<*(iter++)<<" ";
		cout<<endl;
	}
			
	~Graph() { delete []larray; delete []visited; }
};
void Graph::DFS(int head)
{
	static int start=head;
	if(visited[head])
	{
		if(head==start)
			cout<<"start="<<start<<"and cycle exists"<<endl;
		return;
	}
	list<int>::const_iterator iter=larray[head].begin();
	cout<<"next node is "<<*iter<<endl;	
	visited[head]=1;
	while(++iter!=larray[head].end())
	{
		DFS(*iter);
	}
	return;
}
int main()
{
	Graph g(4);
	g.addEdge(0,1);
	//g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.visitV(0);	
	g.visitV(1);	
	g.visitV(2);	
	g.visitV(3);	
	cout << "Following is Depth First Traversal (starting from vertex 0) \n"; 
	g.DFS(3);
	cout<<endl;
	return 0;
}
	
