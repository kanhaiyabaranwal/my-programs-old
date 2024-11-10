/*
http://www.geeksforgeeks.org/samsung-delhi-interview-experience-set-27-campus/
*/
#include<iostream>

using namespace std;

template<class T>
T** createArray(int n, T v=0)
{
	T** temp = new T*[n];
	for(int i=0;i<n;i++)
	{
		temp[i] = new T[n];
		for(int j= 0;j<n;j++)
			temp[i][j] = v;
	}
	return temp;
}

bool isSafe(int n, int i, int j, bool** visited)
{
	if (i <0 || j < 0)
		return false;
	if( i>=n || j >=n)
		return false;
	if(visited[i][j])
		return false;

	return true;
}

int _m[4] = {-1,1,0,0};
int _n[4] = {0,0,-1,1};
int _max = 5000;

void BfsUtil( int** M, int n, int i, int j, bool** visited, int** result)
{
	for(int k=0;k<4;k++)
	{
		int i1 = i + _m[k];
		int j1 = j + _n[k];
		if(isSafe(n,i1,j1,visited) && M[i1][j1] ==1 )
		{
			result[i1][j1] = result[i][j] + 1;
			visited[i1][j1] = true;
			BfsUtil(M,n,i1,j1,visited,result);
		}
	}
}

int** BFS( int** M, int n, int i, int j)
{
	bool** visited = createArray<bool>(n);
	int** result = createArray<int>(n, _max);
	visited[i][j] = true;
	result[i][j] = 0;
	BfsUtil(M,n,i,j,visited,result);
	return result;
}

int main_9()
{
	int input[8][8] = { 
		{0, 0, 1, 0, 0, 1, 0, 0}, 
		{0, 0, 1, 0, 1, 1, 1, 1}, 
		{0, 0, 1, 0, 1, 0, 0, 1}, 
		{0, 0, 1, 1, 1, 0, 0, 0}, 
		{0, 1, 0, 0, 1, 1, 1, 1}, 
		{0, 1, 0, 1, 0, 1, 1, 1}, 
		{0, 0, 1, 1, 1, 1, 0, 1}, 
		{0, 1, 1, 1, 1, 1, 1, 0}
	};

	int **M  = createArray<int>(8,0);
	for(int i= 0;i<8;i++)
	{
		for(int j= 0;j<8;j++)
			M[i][j] = input[i][j];
	}

	int k =3;
	pair<int,int> rare[3];
	rare[0] = std::make_pair<int,int>(0,2);
	rare[1] = std::make_pair<int,int>(1,7);
	rare[2] = std::make_pair<int,int>(4,7);

	int** bfss[3];
	for(int i=0; i<3; i++)
	{
		bfss[i] = BFS(M,8,rare[i].first,rare[i].second);
	}

	int min = _max;
	int c_i = -1;
	int c_j = -1;
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			int sum = 0;
			for(int k=0; k<3; k++)
			{
				sum += bfss[k][i][j];
			}
			if(sum < min)
			{
				min = sum;
				c_i = i;
				c_j = j;
			}
		}
	}

	return 0;
}