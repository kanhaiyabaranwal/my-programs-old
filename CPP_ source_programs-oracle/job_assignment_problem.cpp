/*
http://www.geeksforgeeks.org/branch-bound-set-4-job-assignment-problem/
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define N 4
int job_worker_cost[N][N]={
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };



int main()
{
	
	for(int worker_id=0;worker_id<N;worker_id++)
	{
		for(int job_id=0;job_id<N;job_id++)
			cout<<job_worker_cost[worker_id][job_id]<<",";
		cout<<endl;
	}
	
}

