/*
http://www.geeksforgeeks.org/weighted-job-scheduling/
https://www.youtube.com/watch?v=cr6Ip0J9izc
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job
{
	int start;
	int end;
	int profit;
	Job(int s, int e, int p) : start(s), end(e), profit(p){}
};

bool compareJob( Job j1, Job j2)
{
	if(j1.end == j2.end) 
		return (j1.start < j2.start);
	return (j1.end < j2.end);
}
bool canInclude(Job job, int t)
{
	if( t>0 && t >= job.end)
		return true;
	return false;
}

/***************************************************************************
................ recurssive ..............................................
****************************************************************************
time = O(n * 2^n)
space = O(n)
n = jobs length
Algo : recurressively call max of exclude or include
***************************************************************************/
int maxProfit(vector<Job> jobs, int n , int time)
{
	if ( n<0 || time<= 0)
		return 0;
	int profit_include = 0;
	Job current = jobs[n];

	if(canInclude(current, time))
		profit_include = current.profit + maxProfit(jobs, n-1, current.start);

	int profit_exclude = maxProfit(jobs, n-1, time);

	return (profit_include > profit_exclude) ? profit_include : profit_exclude;
}



/***********************************************************************************
.................. maxProfit dynamic programming part one .........................
************************************************************************************
time O(n) 
space O(n)
n = last job end time

Algo: 
.... Create an array of length of last job end time +1
.... Init first element with 0, that means when time = 0 then max profit = 0
.... Start time=1 and current job point point to first job 
.... Fill rest element it with max of below
.... 1) If current time is less than current job end time then value = previous max
....... because this job cant be scheduled
.... 2) When current time is greater than job pointer end time then this job can be 
....... scheduled, so update value as
....... Max of below options:
........ A) Include case: 
........... For all jobs end point = current job max of below
........... include profit = current profit + DPArray of index jobs start point
........ B) Exclude case: value of previous index

**************************************************************************************/
int maxProfitDP1(vector<Job> jobs)
{
	Job last = jobs[jobs.size()-1];
	int n = last.end + 1;

	int* DPArray = new int[n];
	memset(DPArray,0,sizeof(int) * n);

	DPArray[0] = 0;
	vector<Job>::iterator it = jobs.begin();

	for(int i=1;i<n;i++)
	{
		int max = DPArray[i-1];
		while(it != jobs.end() && i >= (*it).end)
		{
			int profit = (*it).profit + DPArray[(*it).start];
			max = (profit >max ) ? profit : max;
			it++;
		}
		DPArray[i] = max;
	}
	int result = DPArray[n-1];
	delete[] DPArray;
	return result;
}


/***********************************************************************************
................. maxProfit dynamic programming part two ..........................
************************************************************************************
time O(n2) 
space O(n)
n = jobs length

Algo: create an array of jobs lenght and fill it with max of below 2 options
....1) include job : current job profit + find max from previous DPArray where 
.................... the previous job end time is less than or equal to current job
....2) exclude job : max profit from previous job

**************************************************************************************/
int maxProfitDP2(vector<Job> jobs)
{	
	int n = jobs.size();
	if( n < 0)
		return 0;
	int* DPArray = new int[n];
	memset(DPArray,0,sizeof(int) * n);

	vector<Job>::iterator it = jobs.begin();
	DPArray[0] = it->profit;
	it++;
	int index =1;

	while(it != jobs.end())
	{
		vector<Job>::iterator tmp = it-1;
		int excludeProfit = tmp->profit;

		while(tmp != jobs.begin() && tmp->end > it->start)
			tmp--;
		int prevProfit = 0;
		if(tmp->end >= it->start)
			prevProfit = tmp->profit;
		int includeProfit = prevProfit + it->profit;

		DPArray[index++]  = (excludeProfit > includeProfit) ? excludeProfit : includeProfit;		
		it++;
	}
	int result = DPArray[n-1];
	delete[] DPArray;
	return result;
}

int main_16()
{
	vector<Job> jobs;
	jobs.push_back(Job(1,2,50));
	jobs.push_back(Job(3,5,20));
	jobs.push_back(Job(6,19,100));
	jobs.push_back(Job(2,100,200));

	sort(jobs.begin(),jobs.end(),compareJob);

	cout << "maxProfit() =  " << maxProfit(jobs,jobs.size() -1,INT_MAX) << endl;
	cout << "maxProfitDP1() =  " << maxProfitDP1(jobs) << endl;
	cout << "maxProfitDP2() =  " << maxProfitDP2(jobs) << endl;

	return 0;
}




