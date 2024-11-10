/*
http://www.geeksforgeeks.org/topological-sorting/
*/

#include<iostream>
#include<list>
#include<stack>
#include<set>

using namespace std;
//directed graph
class DGraph
{
public:
	DGraph(int v): V(v) { adj = new list<int> [V];  }
	void addEdge(int v,const int w) {  adj[v].push_back(w);	}
	void printTopologicalOrder();
private:
	//Number of vertices
	int V; 
	//pointer to an array containing adjaceny list for each vertices
	list<int> *adj;
	void topoUtil(int vertix, stack<int>& tStack, set<int>& visited);
};

void DGraph::topoUtil(int vertix, stack<int>& tStack, set<int>& visited)
{
	if(visited.find(vertix) != visited.end())
		return;

	//mark as visited
	visited.insert(vertix);
	//process edges first before putting it into the stack
	list<int> edges = adj[vertix];
	for(list<int>::iterator it = edges.begin(); it != edges.end() ; it++)
		topoUtil(*it,tStack,visited);

	//put current in the stack
	tStack.push(vertix);
}

void DGraph::printTopologicalOrder()
{
	stack<int> tStack;
	set<int> visited;
	//Process all nodes in the vertices list 
	for(int i =0; i<V; i++)
		topoUtil(i,tStack,visited);
	while(!tStack.empty())
	{
		int top = tStack.top(); tStack.pop();
		cout << top << " ";
	}
	cout << endl;
}

#if 0
int main()
{
	DGraph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.printTopologicalOrder();
	return 0;
}
#endif

