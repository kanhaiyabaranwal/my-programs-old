#include<iostream>
#include<limits.h>
using namespace std;

int eggDrop(int n,int k, int *EggDrop)	//n-no. of eggs, k-no. of floors, returns minimum no. of trials for eggDropping puzzle
{
	if(n==1)		//if only one egg, no. of trials is number of floors
		return k;
	if(k==1 || k==0)		//if no. of floors is 1, number of trials is 1
		return k;
	if(EggDrop[k]<k) 
		return EggDrop[k];
	int nbrTrialsLower=0;
	int nbrTrialsUpper=0;
	//for ith floor, determine no. of minimum trials required with n-1 eggs.
	//if egg breaks at ith floor, trials required is eggDrop(n-1,i-1)
	//if egg does not break, trials required is eggDrop(n,k-i)
	int minTrialRequired=k;
	for(int i=2;i<=k;i++)
	{
		nbrTrialsLower=eggDrop(n-1,i-1,EggDrop)+1;		// trial for ith node i.e. current node
		nbrTrialsUpper=eggDrop(n,k-i,EggDrop)+1;
	 	if(nbrTrialsLower>=nbrTrialsUpper && nbrTrialsLower < minTrialRequired)
			minTrialRequired = nbrTrialsLower;
		else if(nbrTrialsUpper > nbrTrialsLower && nbrTrialsUpper < minTrialRequired)
			minTrialRequired = nbrTrialsUpper;
	}
	EggDrop[k]=minTrialRequired;
	return minTrialRequired;
}

int main()
{
	int nbrOfFloors, nbrOfEggs;
		cout<<"Nbr of floors?\t";
	cin>>nbrOfFloors;
	int *EggDrop=new int[nbrOfFloors];
	for(int i=0;i<=nbrOfFloors;i++)
		EggDrop[i]=i;
		
	cout<<"Nbr of Eggs?\t";
	cin>>nbrOfEggs;
	int nbrOfTrials=eggDrop(nbrOfEggs,nbrOfFloors,EggDrop);
	cout<<"Number of Trials required="<<nbrOfTrials<<endl;
	return 0;
}
