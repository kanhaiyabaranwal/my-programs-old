//Vertex cover problem- Find minimum of subset of vertices that has all edges incident n a Graph
//Solution using Adjacency Matrix
//Time Complexity- O(n^3)
//Kanhaiya P. Baranwal: 08-May-2015

#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
#define V 5
#define EDGES 8
#define DEBUG 0

struct Graph{
	int adjMat[V][V];
	int v;
	Graph(int v):v(v) {
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(i==j)
					adjMat[i][j]=0;
				else
					adjMat[i][j]=1;
			}
		}
		adjMat[0][3]=-1;
		adjMat[3][0]=-1;
		adjMat[2][4]=-1;
		adjMat[4][2]=-1;
		cout<<" ";
		for(int i=0;i<v;i++)
			cout<<setw(4)<<char(i+65);
		cout<<endl;
		for(int i=0;i<v;i++)
		{
			cout<<char(i+65);
			for(int j=0;j<v;j++)
				cout<<setw(4)<<adjMat[i][j];
			cout<<endl;
		}
				
	}
};

int vertex_cover(Graph& g)
{

	int VCMat[V][V];
	for(int i=0;i<g.v;i++)
		for(int j=0;j<g.v;j++)
			VCMat[i][j]=g.adjMat[i][j];

	int max_edges=0,max_vertex=-1;
	set<int> vcset;
	int edges=0;
	while(edges < EDGES)
	{
		max_vertex=-1;
		max_edges=0;
		for(int i=0;i<V;i++)		//if nbr of edges on vertex i is highest, 
		{
			int count=0;
			for(int j=0;j<V;j++)
			{
				if(VCMat[i][j]==1)
					count++;	
			}
			if(count>max_edges)
			{
				max_edges=count;
				max_vertex=i;
			}
		}
		//vertex with maximum edges identified, include edges in set of edges considered and remove from matrix
		if(DEBUG)
			cout<<"max_vertex="<<max_vertex<<endl;
		if(vcset.find(max_vertex)!=vcset.end())
		{
			cout<<"Fatal Error, set can't have vertices again!!!"<<endl;
			return -1;
		}
		vcset.insert(max_vertex);
		for(int j=0;j<V;j++)
		{
			if(VCMat[max_vertex][j]==1)
			{
				VCMat[max_vertex][j]=0;		//edge considered, remove from Vertex Cover Edges list
				VCMat[j][max_vertex]=0;
				edges++;
			}
		}
		if(DEBUG)
		{
			cout<<"Vertex cover status after removing all edges to vertex "<<max_vertex<<endl;
			for(int i=0;i<g.v;i++)
			{
				for(int j=0;j<g.v;j++)
					cout<<setw(4)<<VCMat[i][j];
				cout<<endl;
			}
		}
	}
	cout<<"Vertex Cover size:"<<vcset.size()<<endl;
	cout<<"Required vertices in Vertex Cover are:";
	set<int>::const_iterator iter=vcset.begin();
	while(iter!=vcset.end())
	{
		cout<<char(*iter+65)<<",";
		iter++;
	}
	cout<<endl;

	return 0;
}

int main()
{
	Graph g(5);
	vertex_cover(g);
	return 0;
}
	


