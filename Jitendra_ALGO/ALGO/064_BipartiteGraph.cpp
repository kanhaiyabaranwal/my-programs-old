/*
http://www.geeksforgeeks.org/bipartite-graph/

Check whether a given graph is Bipartite or not

A Bipartite Graph is a graph whose vertices can be divided into two independent sets,
U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. 
In other words, for every edge (u, v), either u belongs to U and v to V, or 
u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

*/
#include <iostream>
#include<set>
using namespace std; 
const int V = 4;

namespace NS_64
{
	bool isBipartite(int G[][V])
	{
		set<int> red; // todo make it unordered_set
		set<int> blue; // or just use array
		for(int i=0; i<V; i++)
		{
			for(int j=0; j<V; j++)
			{
				if(i==j || G[i][j] == 0) continue;
				//insert i if it not present in either set
				if(blue.find(i) == blue.end() && red.find(i) == red.end())
					blue.insert(i);
				//insert j
				if(blue.find(i) != blue.end())
				{
					if(red.find(j) == red.end()) 
						red.insert(j);
				}
				else
				{
					if(blue.find(j) == blue.end())
						blue.insert(j);
				}
				if((blue.find(i) != blue.end() && blue.find(j) != blue.end()) ||
					(red.find(i) != red.end() && red.find(j) != red.end()))
					return false;

			}
		}
		return true;
	}
}


int main_64()
{

	int G[][V] = {
		{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0}
	};
	/*
	int G[][V] = {
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0}
	};
	*/
	bool res = NS_64::isBipartite(G);
	res ? cout << "Yes" : cout << "No";
	return 0;
}