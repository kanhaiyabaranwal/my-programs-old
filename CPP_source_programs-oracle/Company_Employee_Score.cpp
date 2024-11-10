/*create data structure to maintain database of primary key as key and value as (emp_id,score)
** structure : primary_key->(emp_id,score)
*/

#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;
#define RESIZE 4

struct emp_score{
	int emp_id;
	int score;
	emp_score(int e,int s):emp_id(e),score(s){
	}
	
};

class Emp_Game {
	int nextKeyIndex;
	vector<int> pNumbers;
	map<int,emp_score> esMap;
	
	public:
		bool createPrimeNumberStack();
		bool addNewEmp(int emp_id, int score=0);
		bool updateEmpScore(int key,int score);
		bool removeEmp(int key);
		bool listEmpInRange(int begin=0,int end=0);
		Emp_Game():nextKeyIndex(0){}
};

bool Emp_Game::createPrimeNumberStack()
{
	int count=0;
	int temp=nextKeyIndex;
	int cur_size=pNumbers.size();
	pNumbers.resize(nextKeyIndex+RESIZE);
	if(nextKeyIndex==0)
	{
		pNumbers[nextKeyIndex++]=2;
		pNumbers[nextKeyIndex++]=3;
		pNumbers[nextKeyIndex++]=5;
		pNumbers[nextKeyIndex]=7;
		count=4;
	}
	int cur=pNumbers[cur_size-1]+2;
	while(count<RESIZE)
	{
		int i=3;
		for(i=3;i<cur;i+=2)
		{
			if(cur%i==0)
				break;
		}
		if(i>=cur)
		{
			pNumbers[nextKeyIndex++]=cur;
			count++;
		}
		cur+=2;
		
	}
	//list prime numbers
	vector<int>::const_iterator citer=pNumbers.begin();
	/*while(citer!=pNumbers.end())
	{
		cout<<*citer<<"\t";
		citer++;
	}
	cout<<endl<<"Prime Numbers displayed"<<endl;
	*/
	nextKeyIndex=temp;
	return 0;
}

bool Emp_Game::addNewEmp(int emp_id,int score){
	cout<<"Adding new employee<"<<emp_id<<","<<score<<">\n";
	if( nextKeyIndex >= pNumbers.size())
	{
		createPrimeNumberStack();
		
	}
	esMap.insert(make_pair(pNumbers[nextKeyIndex++],emp_score(emp_id,score)));
}

bool Emp_Game::updateEmpScore(int key,int score)
{
	if(esMap.find(key)==esMap.end())
	{
		cout<<"key: "<<key<<" not found"<<endl;
		return -1;
	}
	map<int,emp_score>::iterator iter = esMap.find(key);
	(iter->second).score=score;
	return 0;
}
bool Emp_Game::removeEmp(int key)
{
	map<int,emp_score>::iterator iter = esMap.find(key);
	if(iter==esMap.end())
	{
		cout<<"key: "<<key<<" not found"<<endl;
		return -1;
	}
	esMap.erase(iter);
	
	
}
bool Emp_Game::listEmpInRange(int begin,int end)
{
	if(end==0)
	{
		end=pNumbers.size();
	}
	
	map<int,emp_score>::const_iterator citer = esMap.begin();
	//emp_score es;
	cout<<"List of players and their scores "<<endl;
	for(;citer!=esMap.end();citer++)
	{
		emp_score es=citer->second;
		cout<<"key is "<<citer->first<<" ,emp_id is "<<es.emp_id<<" and score is "<<es.score<<endl;
	}
}

int main()
{
	cout<<"Program to maintain Employees' score"<<endl;
	Emp_Game eg;
	eg.addNewEmp(121,20);
	eg.addNewEmp(221,30);
	eg.addNewEmp(321,40);
	eg.addNewEmp(421,50);
	eg.addNewEmp(521,60);
	eg.listEmpInRange();
	eg.updateEmpScore(5,50);
	cout<<endl<<"Scores after update"<<endl;
	eg.listEmpInRange();
	
	eg.removeEmp(5);
	cout<<endl<<"Scores after delete"<<endl;
	eg.listEmpInRange();
	return 0;
}
