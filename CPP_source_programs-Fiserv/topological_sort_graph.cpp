#include<iostream>
#include<list>
#include<stack>
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
			larray[i].push_back(i+1);
			visited[i]=0;
		}
	}
	void addEdge(int v,int w)
	{
		int i;
		for(i=0;i<v;i++)
			if(larray[i].front()==v)
				break;
		if(i<v)
			larray[i].push_back(w);
		else
			cout<<"vertex "<<v<<" not found"<<endl;
	}
	void DFS(int head);
	void topological_sort(stack<int>& stk) const;
	void topological_sort_util(int head,stack<int>& stk,bool *visited) const;
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
	if(visited[head-1])
	{
		if(head==start)
			cout<<"start="<<start<<"and cycle exists"<<endl;
		return;
	}
	list<int>::const_iterator iter=larray[head-1].begin();
	cout<<"next node is "<<*iter<<endl;	
	visited[head-1]=1;
	while(++iter!=larray[head-1].end())
	{
		DFS(*iter);
	}
	return;
}
void Graph::topological_sort_util(int head,stack<int>& stk,bool *visited) const
{
	if(visited[head])
		return;
	list<int>::const_iterator iter=larray[head].begin();
	list<int>::const_iterator iter1=iter;
	cout<<"Value visited is "<<*iter<<endl;
	++iter;
	int count=head+1;
	while(iter!=larray[head].end())
	{
		topological_sort_util(count,stk,visited);
		++iter;
		++count;
	}
	cout<<"Pushing value:"<<*iter1<<endl;
	stk.push(*iter1);
	visited[head]=1;
}
void Graph::topological_sort(stack<int>& stk) const
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=0;
	for(int i=0;i<v;i++)
	{
		cout<<"sorting node "<<i<<endl;
		if(!visited[i])
			topological_sort_util(i,stk,visited);
	}
}
	

int main()
{
	Graph g(6);
	g.addEdge(1,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(4,6);
	g.addEdge(4,2);
	g.addEdge(4,3);
	g.addEdge(3,2);
	g.addEdge(1,2);
	g.visitV(0);	
	g.visitV(1);	
	g.visitV(2);	
	g.visitV(3);	
	//cout << "Following is Depth First Traversal (starting from vertex 0) \n"; 
	//g.DFS(4);
	cout << "Following is topological sorted Traversal (starting from vertex 0) \n"; 
	stack<int> stk;
	g.topological_sort(stk);
	cout<<"sorted values"<<endl;
	while(stk.size())
	{
		cout<<stk.top()<<" ";
		stk.pop();
	}
	cout<<endl;
	return 0;
}
	
