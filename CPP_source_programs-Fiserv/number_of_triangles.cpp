#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

#define NUM 6


int number_of_triangles(vector<int>& ivec)
{
	sort(ivec.begin(),ivec.end());
	for(int i=0;i<ivec.size();i++)
		cout<<ivec[i]<<",";
	cout<<endl;
	//find number of triangles
	int sz=ivec.size();
	int k,val=0;	
	int count=0;
	bool flag1=true,flag2=true;
	for(int i=0;i<sz-2;i++)
	{
		val=0;
		for(int j=i+1;j<sz-1;j++)
		{
			if(val>j)
			{
				for(int k=j+1;k<val;k++)
				{
					if(flag1)
					{
						flag1=false;
						cout<<"Triangles from previous calculations "<<endl;
					}
					cout<<ivec[i]<<","<<ivec[j]<<","<<ivec[k]<<endl;
					count++;
				}
				flag1=true;
			}
			else
				val=j+1;
			for(k=val;k<sz;k++)
			{
				if(ivec[i]+ivec[j]<=ivec[k])
					break;
				else
				{
					if(flag2)
					{
						flag2=false;
						cout<<"New triangles found are "<<endl;
					}
					count++;
					cout<<ivec[i]<<","<<ivec[j]<<","<<ivec[k]<<endl;
				}
			}
			flag2=true;
			val=k;	
		}
	}	
	cout<<"Number of triangls found="<<count<<endl;
	return 0;
}

int comp(const void* a,const void * b)
{
	return *(int*)a > *(int*)b ;
}

int main()
{
	int arr[]={4,76,1,89,32,67,23,1,5,7,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),comp);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	
	vector<int> ivec;
	srand(time(NULL));
	for(int i=0;i<NUM;i++)
	{
		ivec.push_back(rand()%25+1);
		cout<<ivec[i]<<",";
	}
	cout<<endl;
	number_of_triangles(ivec);
	return 0;
}
	
