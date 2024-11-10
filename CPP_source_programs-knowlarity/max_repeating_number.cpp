#include<iostream>
using namespace std;

void max_repeating_number ()
{
	int a[]={2, 3, 3, 5, 3, 4, 1, 6};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"arr:";
	for(int i=0;i<n;i++)
		cout<<a[i]<<",";
	cout<<endl;
	int i=0;
	while(i<n)
	{
		while(a[i]>0)
		{
			int temp=0;
			cout<<"a["<<i<<"]="<<a[i]<<endl;
			if(a[a[i]]>0)
			{
				temp=a[a[i]];
				a[a[i]]=-1;
			}
			else if(a[a[i]]<0)
				a[a[i]]--;
			if(a[i]!=temp)
				a[i]=temp;
		}
		i++;
	}
	for(int i=0;i<n;i++)
		cout<<"Count of "<<i<<": "<<a[i]<<endl;
}

int main()
{

	max_repeating_number ();
	return 0;
}
