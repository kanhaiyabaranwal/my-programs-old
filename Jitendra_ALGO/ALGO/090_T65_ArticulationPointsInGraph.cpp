/*
https://www.youtube.com/watch?v=2kREIkF9UAs
http://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

Articulation Points Graph Algorithm
-----------------------------------
Articulation Points (or Cut Vertices) in a Graph
------------------------------------
A vertex in an undirected connected graph is an articulation point (or cut vertex) iff removing it (and edges through it) disconnects the graph.
Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more disconnected components.
They are useful for designing reliable networks.
For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <assert.h>
using namespace std;

namespace NS_90
{
	class UndirectedGraph
	{
		int V; // number of vertices
		list<int> *adj; //dynamic array of adjecent list
		using AdjacentIterator = list<int>::iterator;
		void APUtils(int u, int* parent, int* distance, int* lowest, int& time_counter, bool* visited, bool* AP);
	public:
		UndirectedGraph(int v) : V(v), adj(nullptr)
		{
			adj = new list<int>[V];
		}
		~UndirectedGraph()
		{
			if (adj != nullptr)
				delete[] adj;
		}
		void addEdge(int v1, int v2)
		{
			assert(v1 < V && v2 < V);
			adj[v1].push_back(v2); // as this is un-directd graph
			adj[v2].push_back(v1); // so both will point each other
		}
		void PrintArticulationPoints();
	};
	void UndirectedGraph::APUtils(int u, int* parent, int* distance, int* low, int& time_counter, bool* visited, bool* AP)
	{
		int children = 0;
		visited[u] = true;
		distance[u] = low[u] = ++time_counter;

		for (AdjacentIterator it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = *it;
			// If v is not visited yet, then make it a child of u in DFS tree and recur for it
			if (visited[v] == false)
			{
				children++;
				parent[v] = u;

				APUtils(v, parent, distance, low, time_counter, visited, AP);
				low[u] = std::min(low[u], low[v]);

				// check if it an articulation point
				// (1) u is root of DFS tree and has two or more chilren.
				if (parent[u] == -1 && children > 1)
					AP[u] = true;
				// (2) If u is not root and low value of one of its child is more than discovery value of u.
				if (parent[u] != -1 && low[v] >= distance[u])
					AP[u] = true;
			}
			else if (v != parent[u])
			{
				low[u] = std::min(low[u], distance[v]);
			}
		}

	}

	void UndirectedGraph::PrintArticulationPoints()
	{
		int* parent = new int[V];
		int* distance = new int[V];
		int* low = new int[V];
		bool* visited = new bool[V];
		bool* AP = new bool[V];
		int time_counter = 0;
		//initilize the variable
		for (int i = 0; i < V; i++)
		{
			AP[i] = visited[i] = false;
			parent[i] = -1;
			distance[i] = low[i] = 0;
		}
		// do actual process
		for (int u = 0; u < V; u++)
		{
			if (visited[u] == false)
			{
				APUtils(u, parent, distance, low, time_counter, visited, AP);
			}
		}
		//print all articulation points
		for (int i = 0; i < V; i++)
		{
			if (AP[i])
				cout << i << "  ";
		}
		//cleanup
		delete[] visited;
		delete[] parent;
		delete[] distance;
		delete[] low;
		delete[] AP;
	}

	void test()
	{
		cout << "\nArticulation points in first graph \n";
		UndirectedGraph g1(5);
		g1.addEdge(1, 0);
		g1.addEdge(0, 2);
		g1.addEdge(2, 1);
		g1.addEdge(0, 3);
		g1.addEdge(3, 4);
		g1.PrintArticulationPoints();

		cout << "\nArticulation points in second graph \n";
		UndirectedGraph g2(4);
		g2.addEdge(0, 1);
		g2.addEdge(1, 2);
		g2.addEdge(2, 3);
		g2.PrintArticulationPoints();

		cout << "\nArticulation points in third graph \n";
		UndirectedGraph g3(7);
		g3.addEdge(0, 1);
		g3.addEdge(1, 2);
		g3.addEdge(2, 0);
		g3.addEdge(1, 3);
		g3.addEdge(1, 4);
		g3.addEdge(1, 6);
		g3.addEdge(3, 5);
		g3.addEdge(4, 5);
		g3.PrintArticulationPoints();
	}
}

int main_90_ArticulationPoints()
{
	NS_90::test();
	return 0;
}