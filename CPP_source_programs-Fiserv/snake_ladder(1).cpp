//shortest distance in snake-ladder board
//Method#1: BFT to traverse from cell 1 to end
//lowest distance to every vertex is maintained in queue until last vertex is reached
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
using namespace std;
#define NBR_OF_CELLS 30
#define MAX_CELL 30

struct celldist{
	int v;
	int dist;	//distance from vertex 1
};
int snake_ladder(int *vertex)
{
	int next_dice=0;
	srand(time(NULL));
	int cur_cell=1;
	int move_nbr=0;
	int visited[NBR_OF_CELLS+1];	//mark all cells as none visited
	for(int i=1;i<=NBR_OF_CELLS; i++)
	{
		visited[i]=0;
	}
	queue<celldist> q;
	celldist c1={1,0};	//distance from cell1 to cell1 is 0
	q.push(c1); 
	visited[1]=1;
	int dist=0;	
	while(q.size()>0)
	{
		celldist cellfront=q.front();
		int v=cellfront.v;
		dist=cellfront.dist;
		q.pop();	//pop out the front cell from the queue
		celldist cellnext;
		for(int j=v+1;j<=(v+6) && j<=MAX_CELL;j++)	//can visit next 6 vertices or upto cell# 30
		{
			if(!visited[vertex[j]])		//if not visited then visit and set distance
			{
				cellnext.v=vertex[j];
				cellnext.dist=cellfront.dist+1;
				q.push(cellnext);
				visited[cellnext.v]=1;
			}
		}
	}
	return dist;	//return final distance
}	
//Method#2: Dynamic Programming: shortest distance to any cell reachable to last cell in count1.
//alternative way is to dynamic programming.
int optim_count[NBR_OF_CELLS+1];	//optim count to reach to a cell
void snake_ladder2(int *vertex,int curcell,int count)
{
	if(curcell>=NBR_OF_CELLS)
		return;	
	for(int i=1;i<=6;i++)
	{
		if((curcell+vertex[i]<=NBR_OF_CELLS) && (optim_count[curcell+vertex[i]]==-1 || (optim_count[curcell+vertex[i]]!=-1 && optim_count[curcell+vertex[i]]>count+1)))
		{
			optim_count[curcell+vertex[i]]=count+1;
			snake_ladder2(vertex,curcell+vertex[i],count+1);
		}
	}
	return;				
}


int main()
{
	cout<<"Solution:Snake-Ladder Game from Geeksforgeeks\n";
	cout<<"Source:http://www.geeksforgeeks.org/snake-ladder-problem-2/\n";
	int cell[NBR_OF_CELLS];	//5*6 box, each cell represent one number
	int vertex[NBR_OF_CELLS+1];	//destination of each cell upon movement, if snake, move to -i cell, if ladder, move to +i.
	for(int i=1;i<=NBR_OF_CELLS; i++)
	{
		cell[i]=i;
		vertex[i]=i;
	}
	vertex[3]=22;
	vertex[5]=8;
	vertex[11]=26;
	vertex[20]=29;
	vertex[17]=4;
	vertex[19]=7;
	vertex[21]=9;
	vertex[27]=1;

	int min_dist=snake_ladder(vertex);
	cout<<"minimum distance to reach to top="<<min_dist<<endl;
	//DP solution
	for(int i=1;i<=NBR_OF_CELLS; i++)
	{
		optim_count[i]=-1;
	}
	snake_ladder2(vertex,1,0);
	cout<<"minimum distance to reach to top using DP="<<optim_count[NBR_OF_CELLS]<<endl;
	return 0;
}