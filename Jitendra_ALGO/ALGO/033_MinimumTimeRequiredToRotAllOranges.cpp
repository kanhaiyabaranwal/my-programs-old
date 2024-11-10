/*
http://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/
*/
#include<iostream>
#include<queue>
using namespace std;

#define R 3
#define C 5

struct point{
	int x; int y;
	point(int _x, int _y) : x(_x), y(_y){}
};

bool isValid(int A[][C], int x, int y)
{
	if( x >= 0 && x < R && y >= 0 && y < C && A[x][y] == 1)
		return true;
	return false;
}
int x[] = { 1, -1, 0, 0};
int y[] = { 0, 0, 1, -1};

int minTimeRotOranges (int A[][C])
{
	queue<point> Q;
	int count = 0;
	for(int i=0; i<R; i++)
	{ 
		for(int j=0; j<C; j++) 
		{
			if(A[i][j] == 2) 
			{ 
				Q.push(point(i,j));
				count++; 
			} 
		} 	
	}
	int newCount = 0;
	int time = 0;
	bool changeFlag = false;
	while(!Q.empty())
	{
		point p = Q.front(); Q.pop(); count--;
		for(int i=0; i<4; i++)
		{
			int x1 = p.x + x[i];
			int y1 = p.y + y[i];
			if( isValid(A, x1,y1))
			{
				A[x1][y1] = 2;
				Q.push(point(x1,y1));
				newCount++;
				changeFlag = true;
			}
		}
		if(count == 0)
		{
			if(!changeFlag)
				break;
			else
			{
				count = newCount;
				newCount =0;
				changeFlag = false;
				time++;
			}
		}
	}

	//check if anyone could not rotten
	for(int i=0; i<R; i++)
	{ 
		for(int j=0; j<C; j++) 
		{
			if(A[i][j] == 1) 
				return -1;
		} 	
	}

	return time;
}

int main_33_MinimumTimeRequiredToRotAllOranges()
{
	int arr[][C] = { {2, 1, 0, 2, 1},
		/**/		 {1, 0, 1, 2, 1},
		/**/		 {1, 0, 0, 2, 1}};
	//int ans = -1;
	int ans = minTimeRotOranges(arr);
	if (ans == -1)
		cout << "All oranges cannot rotn";
	else
		cout << "Time required for all oranges to rot => " << ans << endl;
	return 0;
}