/*
http://www.geeksforgeeks.org/branch-bound-set-4-job-assignment-problem/
*/
#include<iostream>
#include<queue>
using namespace std;
#define MAX_JOB_SIZE 100

inline void initAssignFlags(bool* assigned,bool data=false, int size =MAX_JOB_SIZE)
{
	for(int i=0; i<size; i++)
		assigned[i] = data;
}

struct Node
{
	int workerId, jobId;
	int pathCost; //total cost from root till current node;
	int minCost; //min cost from remaining jobs
	bool assigned[MAX_JOB_SIZE]; // keep track of all assigned job till now
	Node* parent;
	int n;

	Node(int _workerId, int _jobId, int _pathCost, int _minCost, 
		Node* _parent, int _totalJob):
	workerId(_workerId), jobId(_jobId), pathCost(_pathCost),
		minCost(_minCost), parent(_parent), n(_totalJob)
	{
		if(_parent!= NULL)
			memcpy(assigned, _parent->assigned, n * sizeof(bool));
		else // root pointer
			initAssignFlags(assigned);
		assigned[jobId] = true;
	}
};
struct compareNode
{
	bool operator()(Node* n1, Node* n2)
	{
		return n1->minCost > n2->minCost;
	}
};
void clean(priority_queue<Node*,vector<Node*>,compareNode>& pq)
{
	while(!pq.empty())
	{
		Node* tmp = pq.top(); pq.pop();
		delete tmp;
	}
}

void printResult(Node *min)
{
    if(min->parent==NULL)
        return;
    printResult(min->parent);
    cout << "Assign Worker " << char(min->workerId + 'A')
         << " to Job " << min->jobId << endl;
}

int minCostUtil(int** costMatrix, int n, 
					int workerId, int jobId,
					int pathCost, bool* alreadyAssigned)
{
	bool tmpAssigned[MAX_JOB_SIZE];
	initAssignFlags(tmpAssigned);
	tmpAssigned[jobId] = true; // this job is fixed for workerId

	int totalMinCost = pathCost;
	for(int worker=workerId+1; worker<n; worker++)
	{
		int minCost = INT_MAX;
		int minCostIndex = -1;
		for(int job =0; job<n; job++)
		{
			if( !alreadyAssigned[job] && !tmpAssigned[job] 
			&& costMatrix[worker][job] < minCost )
			{
				minCost = costMatrix[worker][job];
				minCostIndex = job;
			}
		}
		totalMinCost += minCost;
		tmpAssigned[minCostIndex] = true;
	}

	return totalMinCost;
}
int findMinCost(int** costMatrix, int n)
{
	priority_queue<Node*,vector<Node*>,compareNode> pq;
	Node* root = new Node(-1,-1,0,0,NULL,n);
	pq.push(root);
	while(!pq.empty())
	{
		Node* min = pq.top();
		pq.pop();
		//return if last worker is already assigned with job
		if(min->workerId == (n-1))
		{
			printResult(min);
			int minCost = min->minCost;
			delete min;
			clean(pq);
			return minCost;
		}
		//for next worker find the cost matrix
		int nextWorkerId = min->workerId +1;
		for( int jobId=0; jobId < n; jobId++)
		{
			//skip this job if it is already assigned
			if(min->assigned[jobId]) 
				continue;
			//pathCost = total cost in the tree till current node
			int pathCost = min->pathCost + costMatrix[nextWorkerId][jobId];
			//calculate lowest possiable cost for other workers
			int minCost = minCostUtil(costMatrix,n,nextWorkerId,jobId, pathCost,min->assigned);
			Node* child = new Node(nextWorkerId,jobId, pathCost,minCost,min,n);
			pq.push(child);
		}
	}
	return -1;
}

int main_JobAssignmentProblem_Branch_Bound()
{
	// x-cordinate represents a Worker
	// y-cordinate represents a Job
#define N 4
	int costMatrix[N][N] =
	{
		{9, 2, 7, 8},
		{6, 4, 3, 7},
		{5, 8, 1, 8},
		{7, 6, 9, 4}
	};
	//convert 2D array to int**
	int n = 4;
	int** costMatrix2= new int* [n];
	for(int i=0; i<n; i++)
	{
		costMatrix2[i] = new int[n];
		for(int j=0; j<n; j++)
			costMatrix2[i][j] = costMatrix[i][j];
	}


	cout << "\nOptimal Cost is "
		<< findMinCost(costMatrix2,n);

	return 0;
}