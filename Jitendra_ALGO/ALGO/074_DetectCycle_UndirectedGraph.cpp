/*
http://www.geeksforgeeks.org/detect-cycle-undirected-graph/
Detect cycle in an undirected graph
Given an undirected graph, how to check if there is a cycle in the graph?
*/
#include<iostream>
#include<vector>
using namespace std;

namespace NS74
{
	typedef std::pair<int, int> edge;
	typedef vector<edge> edges;
	typedef edges::iterator edgesIt;

#define EDGE(x, y) std::make_pair<int,int>(x,y)

	int getGroupLeader(int* leaders, int n, int v)
	{
		int gl = v;
		while (leaders[gl] != gl)
			gl = leaders[gl];
		leaders[v] = gl; //path compression
		return gl;
	}

	bool isCycle(edges& E, int maxV)
	{
		int n = maxV + 1;
		int* leaders = new int[n];
		int* ranks = new int[n];
		bool cycle = false;
		for (int i = 0; i < n; i++) 
		{ 
			leaders[i] = i; 
			ranks[i] = 1;
		}
		for (edgesIt it = E.begin(); it != E.end() && !cycle; it++)
		{
			int v1 = it->first; int gl1 = getGroupLeader(leaders, n, v1);
			int v2 = it->second; int gl2 = getGroupLeader(leaders, n, v2);
			if (gl1 == gl2)
			{
				cycle = true; break;
			}
			else
			{
				//merge the the leader of higher rank
				if (ranks[gl1] > ranks[gl2])
				{
					leaders[v2] = gl1;
					ranks[gl1] += ranks[v2];
				}
				else
				{
					leaders[v1] = gl2;
					ranks[gl2] += ranks[v1];
				}
			}
		}
		delete[] leaders;
		return cycle;
	}

	void test()
	{
		edges E;
		E.push_back(EDGE(1, 0));
		E.push_back(EDGE(0, 3));
		E.push_back(EDGE(3, 4));
		E.push_back(EDGE(0, 2));
		E.push_back(EDGE(2, 1));
		int n = 4;
		bool is_cycle = isCycle(E, n);
		if (is_cycle)
			cout << "\n\n Yes there is cycle. \n";
		else
			cout << "\n\n No there is no cycle. \n";
	}
}


int main_74()
{
	NS74::test();
	return 0;
}
