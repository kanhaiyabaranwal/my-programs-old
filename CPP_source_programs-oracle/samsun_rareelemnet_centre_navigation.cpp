#include<iostream>
#include<vector>
using namespace std;
#define R 8
#define C 8
#define COST_INT_MAX 5000
#define NUM_OF_RARE_ELEM 3

int matrix[R][C]={
		{0,0,1,0,0,1,0,0},
		{0,0,1,0,1,1,1,1},
		{0,0,1,0,1,0,0,1},
		{0,0,1,1,1,0,0,0},
		{0,1,0,0,1,1,1,1},
		};

struct element{
	int row,col;
	int cost[R][C];
	element(int r,int c);
	void fillCost(int r,int c,int oldCost);
};

element::element(int i,int j):row(i),col(j){
		cout<<"row:"<<row<<",col:"<<col<<endl;
		for(int r=0;r<R;r++)
			for(int c=0;c<C;c++)
				cost[r][c]=COST_INT_MAX;
		cost[row][col] = 0;
		fillCost(row,col,0);
	}
void element::fillCost(int r,int c,int oldCost){
		static int count=0;
		count++;
		cout<<"row:"<<r<<",col:"<<c;
		cout<<"  filling cost:count="<<count<<endl;
		int zz;
		//while(true)
		//{
			
			if(r+1<R && matrix[r+1][c] && cost[r+1][c] == COST_INT_MAX)
			{
				cost[r+1][c]=oldCost+1;
				fillCost(r+1,c,oldCost+1);
				
			}
			if(r-1>=0 && matrix[r-1][c] && cost[r-1][c] == COST_INT_MAX)
			{
				cost[r-1][c]=oldCost+1;
				fillCost(r-1,c,oldCost+1);
			}
			if(c+1<C && matrix[r][c+1] && cost[r][c+1] == COST_INT_MAX)
			{
				cost[r][c+1]=oldCost+1;
				fillCost(r,c+1,oldCost+1);
			}
			if(c-1>=0 && matrix[r][c-1] && cost[r][c-1] == COST_INT_MAX)
			{
				cost[r][c-1]=oldCost+1;
				fillCost(r,c-1,oldCost+1);
			}
			return;
		//}
	}

int findMinCost(vector<element> &evec)
{
	int min_cost=INT_MAX;
	int min_R=R,min_C=R;
	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
		{
			int cost=0;
			for(int i=0;i<3;i++)
				cost+=evec[i].cost[r][c];
			if(cost<min_cost)
			{
				min_cost=cost;
				min_R=r;
				min_C=c;
			}
		}
	cout<<"min_cost="<<min_cost<<" at index:r "<<min_R<<" and c"<<min_C<<endl;
	return min_cost;
}
int main()
{
	vector<element> evec;
	evec.push_back(element(0,2));
	evec.push_back(element(1,7));
	evec.push_back(element(4,7));
	cout<<"finding min cost"<<endl;
	findMinCost(evec);
	return 0;
}




