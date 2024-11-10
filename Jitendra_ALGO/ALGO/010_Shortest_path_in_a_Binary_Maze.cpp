/*
http://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0
http://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/
*/ 
#include<iostream>
#include<queue>
using namespace std;
int rowMax = 0;
int colMax = 0;
struct Point {
	int i;
	int j;
	explicit Point(int _i, int _j) : i(_i),j(_j){}
	inline bool operator == (const Point& o)
	{
		return ( i==o.i && j==o.j);
	}
};
struct Node {
	Point point;
	int distance; //distcance
	explicit Node(int _i,int _j, int _distance):point(_i,_j),distance(_distance){}
};

// left, right, top, buttom
int rows[] = {0,  0, -1, 1};
int cols[] = {-1, 1,  0, 0};

inline bool withinRange(int i, int j)
{
	return ( i >=0 && j>=0 && i<rowMax && j<colMax);
}

int BFS (int** M, Point s, Point d)
{
	bool** visited = new bool* [rowMax];
	for(int i =0; i<rowMax; i++)
	{
		visited[i] = new bool[colMax];
		memset(visited[i], false, (sizeof(bool))* colMax);
	}
	queue<Node> q;
	q.push(Node(s.i,s.j,0));
	visited[s.i][s.j] = true;
	while(!q.empty())
	{
		Node n = q.front();
		if(n.point == d)
			return n.distance;
		q.pop();
		for(int k=0; k<4; k++)
		{
			int i = n.point.i + rows[k];
			int j = n.point.j + cols[k];

			if(withinRange(i,j) && !visited[i][j] && M[i][j])
				q.push(Node(i,j,n.distance+1));
		}
	}
	//free memory
	for(int i = 0; i<rowMax; i++) {
		delete[] visited[i];   
	}
	delete[] visited;
	return -1;
}
// @@un-used@@ // @@not-complete@@ //
int BFS_PRIORITY_QUEUE(int** M, Point s, Point d)
{
	bool** visited = new bool* [rowMax];
	for(int i =0; i<rowMax; i++)
	{
		visited[i] = new bool[colMax];
		memset(visited[i], false, (sizeof(bool))* colMax);
	}
	//free memory
	for(int i = 0; i<rowMax; i++) {
		delete[] visited[i];   
	}
	delete[] visited;
	return -1;
}
void redirect_std_in_out_10()
{
	//freopen( "c:\\Users\\jisamal.ORADEV\\Documents\\Visual Studio 2008\\Projects\\KNPSearch\\KNPSearch\\output.txt", "w", stdout );
	//freopen( "c:\\Users\\jisamal.ORADEV\\Documents\\Visual Studio 2008\\Projects\\KNPSearch\\KNPSearch\\input.txt", "r", stdin );
}
int main_10(void)
{
	redirect_std_in_out_10();
	int testCases;
	cin >> testCases;
	for( int t=1; t <= testCases; t++)
	{
		cin >> rowMax;
		cin >> colMax;
		int** Matrix = new int* [rowMax];
		for(int i=0;i<rowMax;i++)
			Matrix[i] = new int[colMax];
		for(int i=0;i<rowMax;i++){
			for(int j=0;j<colMax;j++)
				cin >> Matrix[i][j];}
		int x,y;
		cin >> x;
		cin >> y;
		cout << BFS(Matrix, Point(0,0), Point(x,y)) << endl;
		//Delete
		for(int i = 0; i < rowMax; i++) {
			delete[] Matrix[i];   
		}
		delete[] Matrix;
	}
	return 0;
}

