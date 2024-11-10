//Minimum Spanning Tree finds tree connecting all vertices with minimum cost which does not have any cycle - Kruskal's algo
//Edges are first sorted in ascending order and then add to set if it does not make cycle
//To detect cycle in undirected graph Use Union-findparent algorithm with Union by Height or Union by rank technique.
#include<iostream>
#include<map>
using namespace std;
#define NBR_OF_VERTICES 5
#define NBR_OF_EDGES	8

struct Edge{
	int v1;
	int v2;
	int dist;
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
int findparent(int *parent,int i)
{
	if(parent[i]<=-1)
		return i;
	findparent(parent,parent[i]);
}
//combine sets to make one set. Use Union by size. When size=number of vertices, path is found
//Root's parent shows the negative of size of the set.
void Union(int* parent,int xset,int yset)
{
	if(parent[xset]<parent[yset])	//parent[xset] denotes negative of size of set with root xset, xset is larger since negative value is smaller
	{
		parent[xset]+=parent[yset];		//parent of root represents its new size
		parent[yset]=xset;
	}
	else 							//size of yset is smaller meaning its size is more, so make yset as xset's parent, increase yset's size
	{		parent[yset]+=parent[xset];
		parent[xset]=yset;
	}
}

int kruskals (Graph &g)
{
	//MakeSet of vertices, initializing each vertex height as -1
	int *parent=new int[g.v];
	for(int i=0;i<g.v;i++)
	{
		parent[i]=-1;		//initialize with height of the tree=-1
	}
	multimap<int,Edge> mmap;
	for(int i=0;i<g.e;i++)	//for each edge, add into multimap with edge distance as the key
	{
		mmap.insert(make_pair(g.edge[i].dist,g.edge[i]));
	}
	multimap<int,Edge>::const_iterator iter=mmap.begin();
	int xset,yset;
	int mst;
	for(;iter!=mmap.end();iter++)	//for each edge, identify if there is an edge
	{
		
		xset=findparent(parent,iter->second.v1);	
		yset=findparent(parent,iter->second.v2); 
		if(parent[xset]==-g.v || parent[yset]==-g.v)				//if size of set is same as number of vertices in the graph, MST found in xset
		{
			cout<<"minimum cost of graph is "<<mst<<endl;
			return mst;
		}
		if(parent[xset]!=-1 && xset==yset)		//if both vertices are in same set i.e. edge found in same set, means cycle found, do not include that edge
			continue;
		mst+=iter->second.dist;
		Union(parent,xset,yset);	//combine vertices to put into same set
		cout<<"visited->v1="<<iter->second.v1<<",v2="<<iter->second.v2<<"dist="<<iter->second.dist<<endl;
	}
	delete []parent;
	return 0;
}

int main()
{
	Graph g(NBR_OF_VERTICES, NBR_OF_EDGES);
	
	
	g.edge[0]={0,1,5};
	g.edge[1]={1,2,3};
	g.edge[2]={2,3,7};
	g.edge[3]={3,4,4};
	g.edge[4]={4,0,6};
	g.edge[5]={0,2,5};
	g.edge[6]={4,2,5};
	g.edge[7]={1,3,2};
	for(int i=0;i<g.e;i++)
		cout<<"g.edge["<<i+1<<"={"<<g.edge[i].v1<<","<<g.edge[i].v2<<","<<g.edge[i].dist<<"}"<<endl;
	int MST=kruskals(g);
	cout<<"MST="<<MST<<endl;
	return 0;
}
