#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Vertex{
	int num;
	bool visited;
	Vertex(int num=-1,bool visited=0):num(num),visited(visited){
	}
};
struct Graph{
	int v;
	int e;
	vector<int>  *adjList;
	Graph(int v):v(v){
		adjList=new vector<int>[v];
		
	}
	void addEdge(int v1, int v2){
		adjList[v1-1].push_back(v2-1);
		
	}
	void ShowEdges(){
		cout<<"Showing edges of the Graph using Adjacency List"<<endl;
		for(int i=0;i<v;i++)
		{
			cout<<"number of elements at vertex "<<i+1<<" is "<<adjList[i].size()<<endl;
			cout<<"Node["<<i+1<<"]->";
			for(int j=0;j<adjList[i].size();j++)
				cout<<adjList[i][j]+1<<",";
			cout<<endl;
		}
	}
	void topological_sort(){
		bool visited[v];
		for(int i=0;i<v;i++) 
			visited[i]=0;
		stack<int> sint;
		for(int i=0;i<v;i++)
		{
			if(!visited[i])
				top_sort(i,sint,visited);
		}
		//sorted edges are put into stack, now display
		cout<<"sorted edges are put into stack, now display them"<<endl;
		while(sint.size())
		{
			cout<<sint.top()+1<<",";
			sint.pop();
		}
		cout<<endl;
	}
	void top_sort(int v,stack<int>& sint, bool *visited)
	{
		for(int i=0;i<adjList[v].size();i++)
		{
			if(!visited[adjList[v][i]])			//vertex is not visited, then visit
				top_sort(adjList[v][i],sint,visited);
		}
		sint.push(v);
		visited[v]=1;
	}
	
};
void make_set(int *arr,int v)
{
	for(int i=0;i<v;i++)
		arr[i]=-1;
}

int find(int *arr,int x)
{
	if(arr[x]==-1)
		return x;
	else
		return find(arr,arr[x]);
}
void Union(int *arr,int x,int y)
{
	int xparent=find(arr,x);
	int yparent=find(arr,y);
	arr[xparent]=yparent;
}
int IsCircle(Graph &g)
{
	int *arr=new int[g.v];
	make_set(arr,g.v);
	//for each vertex, find all edges and see if circle found
	for(int i=0;i<g.v;i++)
	{
		int xparent=find(arr,i);
		for(int j=0;j<g.adjList[i].size();j++)
		{
			int yparent=find(arr,g.adjList[i][j]);	
			if(xparent==yparent)
				return 1;
			else
				Union(arr,xparent,yparent);
		}
	}
	return 0;
}

int main()
{
	Graph g(7);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(4,5);
	g.addEdge(4,6);
	g.addEdge(4,3);
	g.addEdge(4,2);
	g.addEdge(5,6);
	g.addEdge(7,6);
	g.ShowEdges();
	g.topological_sort();
	if(IsCircle(g))
		cout<<"Circle found in the graph"<<endl;
	else
		cout<<"No Circle exist in the graph"<<endl;
	
	return 0;
}

