#include<iostream>
#include<unordered_set>
using namespace std;

void neha1 ()
{
	int n;
	//cout<<"enter number of participants"<<endl;
	cin>>n;
	int *arr=new int[n];
	//cout<<"enter participants"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//cout<<"Participants are :";
	/*for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}*/
	
	
	int i=n;
	while(true)
	{
		unordered_set<int> uset;
		bool flag=true;
		for(int j=0;j<n;j++)
		{
			int mod=arr[j]%i;
			if(uset.find(mod)!=uset.end())
			{
				flag=false; 
				break;
			}
			else
				uset.insert(mod);
		}
		if(flag)
		{
			//cout<<i<<" is the solution"<<endl;
			cout<<i;
			return ;
		}
		//cout<<i<<" is not the solution"<<endl;
		i++;
	}
}

int main()
{

	neha1 ();
	return 0;
}
