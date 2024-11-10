/*
http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/
https://www.youtube.com/watch?v=lAXZGERcDf4
http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<limits.h>

using namespace std;

// Number of vertices in the graph
#define V 9
#define INF INT_MAX
#define MACRO_47_USE_SET 1

#if 0

namespace NS_47
{

	inline int calculate_distance(int d1, int d2)
	{
		if (d1 == INF || d2 == INF) return INF;
		return d1 + d2;
	}

	//print result
	void printSolution(int dist[], int n)
	{
		printf("Vertex\t\tDistance from Source\n");
		for (int i = 0; i < V; i++)
			printf("%d\t\t%d\n", i, dist[i]);
	}

#if MACRO_47_USE_SET
	int findMiniumUsingSet(int dist[V], set<int> &unvisited)
	{
		int min_dist_index = -1;
		int min_dist = INF;
		for (set<int>::iterator it = unvisited.begin();
			it != unvisited.end(); it++)
		{
			if (min_dist > dist[*it])
			{
				min_dist = dist[*it];
				min_dist_index = *it;
			}
		}
		return min_dist_index;
	}
#else
	int findMiniumUsingArray(int dist[V], bool visited_array[V])
	{
		int min_dist_index = -1;
		int min_dist = INF;
		for (int i = 0; i < V; i++)
		{
			if (!visited_array[i] && min_dist > dist[i])
			{
				min_dist = dist[i];
				min_dist_index = i;
			}
		}
		return min_dist_index;
	}
#endif

	void dijkstra(int graph[V][V], int src)
	{
		if (src < 0 || src >= V) return;
#if MACRO_47_USE_SET
		set<int> unvisited;
		for (int i = 0; i < V; i++) unvisited.insert(i);
#else
		bool bVisited[V]; std::fill(bVisited, bVisited + V, false);
#endif
		int dist[V]; std::fill(dist, dist + V, INF);

		int start = src;
		dist[start] = 0;
		while (start != -1)
		{
			for (int end = 0; end < V; end++)
			{
				if (start == end) continue;
				int cost = graph[start][end];
				int new_dist = calculate_distance(dist[start], cost ? cost : INF);
				dist[end] = min(new_dist, dist[end]);
			}
#if MACRO_47_USE_SET
			unvisited.erase(start);
			start = findMiniumUsingSet(dist, unvisited);
#else
			bVisited[start] = true;
			start = findMiniumUsingArray(dist, bVisited);
#endif
		}
		printSolution(dist, src);
	}

	struct node47Set {
		int vertex;
		int distance;
		node47Set(int v, int d) : vertex(v), distance(d) {}
	};

	struct operatorLessNode47Set
	{
		bool operator () (node47Set* a, node47Set* b)
		{
			if (a->distance == b->distance)
				return (a->vertex < b->vertex);
			return a->distance < b->distance;
		}
	};

	/*Using min-heap
	We will use set data structor as set always keeps lowest value on the
	begin and erase/inset will take order of log(N)
	*/
	void dijkstra_improved(int graph[V][V], int src)
	{
		if (src < 0 || src >= V) return;

		set<node47Set*, operatorLessNode47Set> minSet;
		//vector<int> dist(V,INF);
		int dist[V]; std::fill(dist, dist + V, INF);

		dist[src] = 0;
		minSet.insert(new node47Set(src, 0));

		while (!minSet.empty())
		{
			node47Set* current = *(minSet.begin()); minSet.erase(minSet.begin());
			int start = current->vertex;
			int current_distance = current->distance;

			for (int vertex = 0; vertex < V; vertex++)
			{
				// same vertiex no need to process or if there is no path
				if (vertex == start || graph[start][vertex] == 0) continue;

				int total_distance = current_distance + graph[start][vertex];
				if (total_distance > dist[vertex]) continue; // this is loop

				node47Set* newNode = new node47Set(vertex, dist[vertex]);
				if (newNode->distance != INF) // that means it is already in set
					minSet.erase(minSet.find(newNode));

				dist[vertex] = total_distance;
				newNode->distance = total_distance;
				minSet.insert(newNode);
			}

			delete current;
		}
		printSolution(dist, src);
	}

	void test()
	{
		int graph1[V][V] = {
			{0, 4, 0, 0, 0, 0, 0, 8, 0},
			{4, 0, 8, 0, 0, 0, 0, 11, 0},
			{0, 8, 0, 7, 0, 4, 0, 0, 2},
			{0, 0, 7, 0, 9, 14, 0, 0, 0},
			{0, 0, 0, 9, 0, 10, 0, 0, 0},
			{0, 0, 4, 14, 10, 0, 2, 0, 0},
			{0, 0, 0, 0, 0, 2, 0, 1, 6},
			{8, 11, 0, 0, 0, 0, 1, 0, 7},
			{0, 0, 2, 0, 0, 0, 6, 7, 0}
		};
		int graph[V][V] = {
			{0, 4, 4, 0, 0, 0, 0, 8, 0},
			{4, 0, 8, 0, 0, 0, 0, 11, 0},
			{4, 8, 0, 7, 0, 4, 0, 0, 2},
			{0, 0, 7, 0, 9, 14, 0, 0, 0},
			{0, 0, 0, 9, 0, 10, 0, 0, 0},
			{0, 0, 4, 14, 10, 0, 2, 0, 0},
			{0, 0, 0, 0, 0, 2, 0, 1, 6},
			{8, 11, 0, 0, 0, 0, 1, 0, 7},
			{0, 0, 2, 0, 0, 0, 6, 7, 0}
		};
		dijkstra(graph, 0);
		dijkstra_improved(graph, 0);
	}
}

int main_47_DijkstraShortestPath()
{
	NS_47::test();
	return 0;
}

#endif