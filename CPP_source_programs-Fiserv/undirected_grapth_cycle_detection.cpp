//Detect cycle in undirected graph
#include<iostream>
using namespace std;
#define NBR_OF_VERTICES 5
#define NBR_OF_EDGES	4

struct Edge{
	int v1;
	int v2;
};

struct Graph{
	int v;
	int e;
	Edge *edge;
	Graph(int V,int E):v(V),e(E)	{
		edge=new Edge[e];
	}
};

//returns root of the vertex
int find(int *parent,int i)
{
	if(parent[i]==-1)
		return i;
	find(parent,parent[i]);
}
//combine sets to make one set. Use Union by rank or union by height
//Root's parent shows the negative of height of the set.
int Union(int* parent,int xset,int yset)
{
	if(parent[xset]<parent[yset])	//height of xset is smaller meaning its height is more, so make xset as yset's parent
		parent[yset]=xset;
	if(parent[yset]<parent[xset])	//height of yset is smaller meaning its height is more, so make yset as xset's parent
		parent[xset]=yset;
	else							//one can be other's parent and then increase its height
	{
		parent[yset]=xset;
		xset--;
	}
}

int IsCycle (Graph &g)
{
	//MakeSet of vertices, initializing each vertex height as -1
	int *parent=new int[g.v];
	for(int i=0;i<g.v;i++)
	{
		parent[i]=-1;		//initialize with height of the tree=-1
	}
	for(int i=0;i<g.e;i++)	//for each edge, identify if there is an edge
	{
		int xset,yset;
		xset=find(parent,g.edge[i].v1);
		yset=find(parent,g.edge[i].v2);
		if(xset==yset)		//if both vertices are in same set i.e. edge found in same set, means cycle found
			return 1;
		Union(parent,xset,yset);	//combine vertices to put into same set
	}
	delete []parent;
	return 0;
}

int main()
{
	Graph g(NBR_OF_VERTICES, NBR_OF_EDGES);
	
	
	g.edge[0]={0,1};
	g.edge[1]={1,2};
	g.edge[2]={2,3};
	g.edge[3]={3,4};
	g.edge[4]={4,0};
	g.edge[5]={0,2};
	g.edge[6]={4,2};
	//g.edge[7]={1,3};
	for(int i=0;i<g.e;i++)
		cout<<"g.edge["<<i+1<<"={"<<g.edge[i].v1<<","<<g.edge[i].v2<<"}"<<endl;
	int iscycle=IsCycle(g);
	cout<<"iscycle="<<iscycle<<endl;
	return 0;
}
