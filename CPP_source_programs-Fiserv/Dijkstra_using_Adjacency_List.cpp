//Dijkstra's shortest path algorithm.
//Uses adjacency list to represent graph
#include<iostream>
#include<vector>
using namespace std;

struct edge{
	int v1;
	int v2;
	int dist;
	edge(int v1,int v2,int dist):v1(v1),v2(v2),dist(dist){
	}
};

struct Graph{
	int v;
	vector<edge> *adjList;
	Graph(int v):v(v){ 
		adjList=new vector<edge>[v];		//array of 	vectors of integers
	}
	void addEdge(int v1,int v2,int dist){
		adjList[v1].push_back(edge(v1,v2,dist));
	}
	void ShowGraph()
	{
		for(int i=0;i<v;i++)
		{
			cout<<"Adjacency list for node "<<i<<":";
			vector<edge>::const_iterator iter=adjList[i].begin();
			while(iter!=adjList[i].end())
			{
				cout<<(*iter).v2<<"("<<(*iter).dist<<"),";
				iter++;
			}
			cout<<endl;
		}
	}
};
//Dijkstra's shortest path for source vertex v
void ShortestPath(Graph &g,int v)
{
	vector<int> ivec;
	int dist[g.v];
	for(int i=0;i<g.v;i++)
	{
		dist[i]=-1;
	}
	dist[v]=0;
	ivec.push_back(v);
	while(ivec.size()!=g.v)
	{
		for(int i=0;i<ivec.size();i++)
		{
			vector<edge>::const_iterator iter=adjList[i].begin();
			if(dist[(*iter).v2]==-1 || )
			while(iter!=adjList[i].end())
			{
				cout<<(*iter).v2<<"("<<(*iter).dist<<"),";
				iter++;
			}
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0,1,4);
	g.addEdge(0,2,1);
	g.addEdge(1,4,4);
	g.addEdge(2,3,4);
	g.addEdge(2,1,2);
	g.addEdge(3,4,4);
	//g.addEdge(2,5);
	g.ShowGraph();
	ShortestPath(g,int v);
}
