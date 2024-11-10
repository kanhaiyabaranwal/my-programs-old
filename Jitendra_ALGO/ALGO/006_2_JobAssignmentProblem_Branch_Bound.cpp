#include<iostream>
#include<vector>
#include<queue>
using namespace std;

namespace NS6_2
{
#define N 4

	struct node {
		int TotalJob;
		int JobID;
		int WorkerID;
		bool* assignedFlags;
		int minCost;
		int pathCost;
		node* parent;
		//constructor
		node(int n, int jId, int wId, int path_cost, int min_cost, node* p = NULL)
			: TotalJob(n), JobID(jId), WorkerID(wId), assignedFlags(NULL),
			minCost(min_cost), pathCost(path_cost), parent(p)
		{
			assignedFlags = new bool[n];
			for (int i = 0; i < n; i++)
				assignedFlags[i] = parent ? parent->assignedFlags[i] : false;
			assignedFlags[JobID] = true;
		}
		//destructor
		~node()
		{
			if (assignedFlags)
				delete[] assignedFlags;
		}
	};
	struct compareNode
	{
		bool operator()(node* n1, node* n2)
		{
			return n1->minCost > n2->minCost;
		}
	};

	void printResult(node* res)
	{
		if (res->parent == NULL)
			return;
		printResult(res->parent);
		cout << "Assign Worker " << char(res->WorkerID + 'A')
			<< " to Job " << res->JobID << endl;
	}

	int findMinCost(int CM[N][N])
	{
		int n = N;
		priority_queue<node*, vector<node*>, compareNode> PQ;
		node* root = new node(n, -1, -1, 0, 0, NULL);
		PQ.push(root);
		while (!PQ.empty())
		{
			node* parent = PQ.top(); PQ.pop();
			int worker = parent->WorkerID + 1;
			if (worker == n)
			{
				//all assignment done return
				printResult(parent);
				return parent->pathCost;
				// TODO delete nodes in PQ
			}
			for (int job = 0; job < n; job++)
			{
				if (parent->assignedFlags[job])
					continue; // this job is already assigned
				int path_cost = parent->pathCost + CM[worker][job];
				int min_cost = path_cost;
				for (int ow = worker + 1; ow < n; ow++)
				{
					int tmp_min_cost = INT_MAX;
					for (int oj = 0; oj < n; oj++)
					{
						if (oj == job || parent->assignedFlags[oj])
							continue; // these jobs are not aviable
						tmp_min_cost = min(tmp_min_cost, CM[ow][oj]);
					}
					if (tmp_min_cost != INT_MAX)
					{
						min_cost += tmp_min_cost;
					}
				}
				node* child = new node(n, job, worker, path_cost, min_cost, parent);
				PQ.push(child);
			}
		}
		return -1;
	}

	void test()
	{
		// x-cordinate represents a Worker
		// y-cordinate represents a Job
		int costMatrix_1[N][N] =
		{
			{9, 2, 7, 8},
			{6, 4, 3, 7},
			{5, 8, 1, 8},
			{7, 6, 9, 4}
		};
		int costMatrix[N][N] =
		{
		{82, 83, 69, 92},
		{77, 37, 49, 92},
		{11, 69,  5, 86},
		{ 8,  9, 98, 23}
		};
		int costMatrix_3[N][N] =
		{
		{2500, 4000, 3500},
		{4000, 6000, 3500},
		{2000, 4000, 2500}
		};
		int costMatrix_4[N][N] =
		{
		{90, 75, 75, 80},
		{30, 85, 55, 65},
		{125, 95, 90, 105},
		{45, 110, 95, 115}
		};
		int res = findMinCost(costMatrix);
		cout << "\nOptimal Cost is " << res;
	}
}
int main_6_2()
{
	NS6_2::test();
	return 0;
}