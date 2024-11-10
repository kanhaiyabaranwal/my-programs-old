#include<iostream>
#include<queue>

#define M 3
#define N 5
using namespace std;

void minimum_time_required_so_that_all_oranges_become_rotten()
{
	int a[][N]={ 
					 {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}
				};
    
	queue<pair<int,int> > pq;     
    for(int i=0;i<M;i++)
    {
	
		for(int j=0;j<N;j++)
    	{
    		cout<<a[i][j]<<"  ";
    		if(a[i][j]==2)
    			pq.push(make_pair(i,j));
		}
		cout<<endl;
	}
	pq.push(make_pair(-1,-1));
	int row,col;
	int time=0;
	int in;
	while(pq.size()>1)
	{
		std::pair<int,int> front=pq.front();
		pq.pop();
		row=front.first,col=front.second;
		if(row==-1 && col==-1)
		{
			time++;
			pq.push(make_pair(row,col));
		}
		else
		{
			cout<<"Rotting for row:"<<row << "and col:"<<col<<endl;
			if(row+1 < M && a[row+1][col]==1)
			{
			
				pq.push(make_pair(row+1,col));
				a[row+1][col]=2;
			}
			if(row-1 >=0 && a[row-1][col]==1)
			{
				a[row-1][col]=2;
				pq.push(make_pair(row-1,col));
			}
			if(col+1 < N && a[row][col+1]==1)
			{
				a[row][col+1]=2;
				pq.push(make_pair(row,col+1));
			}
			if(col-1 >=0 && a[row][col-1]==1)
			{
				a[row][col-1]=2;
				pq.push(make_pair(row,col-1));
			}
			
		}
		cout<<"counter required: "<<time<<endl;
		//cin>>in;

	}
	
	cout<<"Time required: "<<time<<endl;
}


int main()
{
	minimum_time_required_so_that_all_oranges_become_rotten();
	return 0;
}
