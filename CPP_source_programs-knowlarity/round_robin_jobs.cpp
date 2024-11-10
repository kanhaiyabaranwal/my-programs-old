#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct job{
	int job_id;
	queue<int> task_q;
	job(int job_id):job_id(job_id) {}
};

void round_robin_jobs ()
{
	vector<job> job_v;
	job j1(500);
	j1.task_q.push(700);
	j1.task_q.push(300);
	j1.task_q.push(350);
	job j2(600);
	j2.task_q.push(400);
	j2.task_q.push(350);
	j2.task_q.push(600);
	job j3(1000);
	j3.task_q.push(800);
	j3.task_q.push(100);
	job j4(200);
	j4.task_q.push(650);

	job_v.push_back(j1);
	job_v.push_back(j2);
	job_v.push_back(j3);
	job_v.push_back(j4);
	cout<<"Jobs along with tasks are "<<endl;
	bool flag=true;
	while(flag)
	{
	flag=false;
	for(int i=0;i<job_v.size();i++)
	{
		if(!job_v[i].task_q.empty())
		{
			cout<<" JOB ID : "<<job_v[i].job_id<< " Task id : "<<job_v[i].task_q.front()<<endl;
			job_v[i].task_q.pop();
			flag=true;
		}
	}
	}

}
int main()
{

	round_robin_jobs ();
	return 0;
}
