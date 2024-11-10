#include<iostream>
#include<vector>
using namespace std;
// printing sets without interval
//Given few sets of intervals print out the the entire intervals without overlapping, if they overlap then combine them into one.
//Sample test case:

//Input :    (5,7) (1 , 6) (2 ,4) (10 ,14) (8,9) 
//Output :   (1,7) (8,9) (10,14) 

class MySet { 
	
	public:
	int lb;
	int ub;
		MySet(int l, int u):lb(l),ub(u)	{}
		int getLB() { 
			return lb;
		}
		int getUB() { 
			return ub;
		}
};

int main()
{
	vector<MySet*> setvec;
	int lb,ub;
	int insertSet=1;
	cout<<"Preparing sets, It will ask for lower bound and upper bound. Enter -1 to exit "<<endl;
	while(1)
	{
		cout<<"Give lowerBound"<<endl;
		cin>>lb;
		if(lb==-1)
			break;
		cout<<"Give upperBound"<<endl;
		cin>>ub;
		insertSet=1;
		for(int i=0;i<setvec.size();i++)
		{
			if(
				(setvec[i]->lb < ub && setvec[i]->ub > lb) ||			//set has 5,9, input is 1,7
				(setvec[i]->lb < lb && setvec[i]->ub > lb) ||		//set has 5,9, input is 6,10
				(setvec[i]->lb < lb && setvec[i]->ub > ub) ||			//set has 5,9, input is 6,8
				(setvec[i]->lb > lb && setvec[i]->ub < ub)			//set has 5,9, input is 1,10
			  )
			{
			  	if(setvec[i]->lb > lb)
			  		setvec[i]->lb=lb;
			  	if(setvec[i]->ub < ub )
			  		setvec[i]->ub=ub;
			  		insertSet=0;
			  		break;
			  	
			}
			
		}
		if(insertSet)
			{
				MySet* newSet= new MySet(lb,ub);
				setvec.push_back(newSet);
				int size=setvec.size();
				cout<<"values inserted are"<<setvec[size-1]->lb<<endl;
			}
			
	}
	//cout<<"size="<<setvec.size()<<endl;
	for(int i=0;i<setvec.size();i++)
		cout<<"set# "<<i<<"=("<<setvec[i]->lb<<","<<setvec[i]->ub<<")"<<endl;
} 
