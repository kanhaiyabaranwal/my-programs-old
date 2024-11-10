//Kruskal's Algorithm for Minimum Spanning Tree.
//Algorithm starts with edges of least distance and push into array if both vertices are not already included.
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

struct Edge {
	int v1;
	int v2;
	int dist;
} ;
struct  Graph {
	int e;		//Number of edges
	Edge *edge;	//pointer to array of edges
	Graph(int e);
};
Graph::Graph(int nbr)
{
	e=nbr;
	edge=new Edge[e];
	for(int i=0;i<e;i++)
	{
		cout<<"Edge["<<i+1<<"] input"<<endl;
		cout<<"V1=";
		cin>>edge[i].v1;
		cout<<"V2=";
		cin>>edge[i].v2;
		cout<<"Edge's distance=";
		cin>>edge[i].dist;
	}
}

void kruskals(Graph &g)
{
	cout<<"Nbr of Edges in the graph is "<<g.e<<endl;
	//map of distance and edges
	multimap<int,Edge> mmap;	
	cout<<"Graph is\n";
	for(int i=0;i<g.e;i++)
	{ 
		mmap.insert(make_pair(g.edge[i].dist,g.edge[i]));
	}
	multimap<int,Edge>::const_iterator iter=mmap.begin();
	int *edge_array=new int[g.e];					//same as number of edges, array value represents destination vertex. -1 is uninitialized
	for(int i=0;i<g.e;i++)	
	{
		edge_array[i]=-1;			//value is initialized to -1 to represent no edge. It is set when edge is included in MST
	}
	int v1found,v2found;
	while(iter!=mmap.end())
	{
		v1found=0,v2found=0;
		for(int i=0;i<mmap.size();i++)	//scan through the edge array if vertex is already added
		{
			if(edge_array[i] != -1 )		//If both vertices already present, then a cycle, skip this edge then
			{
				if (i==(iter->second).v1 || edge_array[i]==(iter->second).v1)
					v1found=1;
				if (i==(iter->second).v2 || edge_array[i]==(iter->second).v2)
					v2found=1;
			}
		}
		if(!v1found || !v2found)				//insert edge into the array if not making cycle
		{
			if(edge_array[(iter->second).v1] == -1)
				edge_array[(iter->second).v1]=(iter->second).v2;
			else if(edge_array[(iter->second).v2] == -1)
				edge_array[(iter->second).v2]=(iter->second).v1;
		}
		iter++;
	}
	//Print Kruskal's MST
	cout<<"Printing Kruskal's Minimum Spanning Tree"<<endl;
	for(int i=0;i<mmap.size();i++)
	{
		if(edge_array[i]!=-1)
			cout<<"next edge has vertices -> "<<i<<","<<edge_array[i]<<endl;
	}
	return;
}


int main()
{
	cout<<"It's Undirected graph\n";
	cout<<"Grapth with Nbr of vertices="<<NBR_OF_VERTICES<<endl;
	int nbrofedges;
	cout<<"Enter Nbr of vertices in the graph"<<endl;
	cin>>nbrofedges;
	Graph g(nbrofedges);
	cout<<"graph created has following edges"<<endl;
	for(int i=0;i<g.e;i++)
	{
		cout<<"Edge["<<i+1<<"]->V1="<<g.edge[i].v1<<", V2="<<g.edge[i].v2<<", distance="<<g.edge[i].dist<<endl;
	}
	
	//traverses through the newly built graph
	kruskals(g);
	return 0;
}



