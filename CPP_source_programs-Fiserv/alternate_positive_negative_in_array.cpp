#include<iostream>
#include<queue>
using namespace std;

void alternate_positive_negative_in_array(int *arr,int sz)
{
	deque<int> q;
	bool is_positive=true;
	if(arr[0]<0)
		q.push_back(0);
	for(int i=1;i<sz;i++)
	{
		cout<<"iteration# "<<i<<endl;	
		if((arr[i] >= 0 && arr[i-1] >= 0) || (arr[i] < 0 && arr[i-1] < 0))
		{
			cout<<"pushing "<<arr[i]<<endl;
			q.push_back(i);
		}	
		else if(q.size())	
		{
			deque<int>::iterator iter=q.begin();
			int temp=arr[*iter];	
			cout<<"Current element "<<arr[i]<<" first element in deque "<<temp<<endl;
			arr[*iter]=arr[i];
			cout<<"arr[*iter]"<<arr[*iter]<<endl;
			*iter+=1;
			iter++;
			int temp1;
			for(;iter!=q.end();iter++)
			{
				cout<<"arr[*iter]"<<arr[*iter]<<",temp="<<temp<<endl;
				cout<<"Swapping element at "<<*iter<<" value "<<arr[*iter]<<" with "<<temp<<endl;
				temp1=arr[*iter];
				arr[*iter]=temp;
				temp=temp1;
				*iter+=1;
				cout<<"Modified Array iteration#"<<i<<":";
				for(int i=0;i<sz;i++)
					cout<<arr[i]<<",";
				cout<<endl;
			}
			cout<<"Placeing "<<i<<"th position with "<<temp;
			arr[i]=temp;
				cout<<"Modified Array iteration#"<<i<<":";
				for(int i=0;i<sz;i++)
					cout<<arr[i]<<",";
				cout<<endl;
			cout<<"pop element from queue"<<arr[q.front()]<<endl;
			q.pop_front();
			if(q.size())
				q.pop_front();
		}
	}
}
	

int main()
{
	int arr[]={-1,3,4,5,6,7,8,-1,-2,-3,-4};
	//int arr[]={-1,3,4,-5};
	int sz=sizeof(arr)/sizeof(arr[0]);
	cout<<"Original Array:";
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	alternate_positive_negative_in_array(arr,sizeof(arr)/sizeof(arr[0]));
	cout<<"Modified Array:";
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	return 0;
}
	
