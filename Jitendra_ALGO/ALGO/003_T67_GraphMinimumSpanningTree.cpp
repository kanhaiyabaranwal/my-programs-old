/*
 http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
 http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
 https://www.youtube.com/watch?v=ID00PMy0-vE
 https://www.youtube.com/watch?v=fAuF0EuZVCk&t=417s
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#include"002_T58_GraphDisjointSet.cpp"

using namespace std;

template<typename T>
struct Edge
{
	T vertice1;
	T vertice2;
	int weight;
	Edge(T v1, T v2, int w) : vertice1(v1), vertice2(v2), weight(w){}
};

template<typename T>
bool compareEdge(Edge<T> ob1,Edge<T>ob2)
{
	return ob1.weight < ob2.weight;
}

template<typename T>
class UGraph
{
public:
	UGraph(){}
	void addEdge(Edge<T> edge) {edges.push_back(edge);}
	void addVertices(T v) {vertices.insert(v);}
	void mstPopulate(vector<Edge<T>>&);
private:
	vector<Edge<T>> edges;
	set<T> vertices;
	//hide copy constructor and asignment operator
	UGraph(UGraph& other);
	UGraph& operator =(UGraph& other);
};

template<typename T>
void UGraph<T>::mstPopulate(vector<Edge<T>>& result)
{
	sort(edges.begin(),edges.end(), compareEdge<T>);

	//init parent/groupleader map
	set<T>::iterator vit;
	DisjointSet<T> dSet;
	for(vit = vertices.begin(); vit != vertices.end(); vit++)
		dSet.makeSet(*vit);

	//proces each edge
	vector<Edge<T>>::iterator it;
	for(it = edges.begin(); it!=edges.end(); it++)
	{
		Edge<T> edge = *it;
		if(dSet.isInSameSet(edge.vertice1,edge.vertice2))
			continue;
		result.push_back(edge);
		dSet.join(edge.vertice1,edge.vertice2);
	}
}


int main_3()
{
	
	UGraph<int> graph;
	graph.addVertices(0);
	graph.addVertices(1);
	graph.addVertices(2);
	graph.addVertices(3);
	graph.addVertices(4);
	graph.addVertices(5);
	graph.addVertices(6);
	graph.addVertices(7);
	graph.addVertices(8);

	graph.addEdge(Edge<int>(0,1,4));
	graph.addEdge(Edge<int>(1,2,8));
	graph.addEdge(Edge<int>(2,3,7));
	graph.addEdge(Edge<int>(3,4,9));
	graph.addEdge(Edge<int>(4,5,10));
	graph.addEdge(Edge<int>(5,6,2));
	graph.addEdge(Edge<int>(6,7,1));
	graph.addEdge(Edge<int>(7,8,7));
	graph.addEdge(Edge<int>(7,0,8));

	graph.addEdge(Edge<int>(1,7,11));
	graph.addEdge(Edge<int>(2,8,2));
	graph.addEdge(Edge<int>(8,6,6));

	graph.addEdge(Edge<int>(2,5,4));
	graph.addEdge(Edge<int>(3,5,14));


	vector<Edge<int>> result;
	graph.mstPopulate(result);
	vector<Edge<int>>::iterator it;
	for(it = result.begin(); it!=result.end(); it++)
		cout << (*it).weight << " ";
	cout<< endl;

	return 0;
}