#include<iostream>
using namespace std;

void count_chars ()
{
	char arr[]="kanhaiyaprasadbaranwal";
	int count[26] {0};
	for(int i=0;i<sizeof(arr);i++)
	{
		count[arr[i]-97]++;
	}
	cout<<"count of a is "<<count[0]<<endl;
	for(int i=0;i<sizeof(arr);i++)
	{
		if(count[arr[i]-97])
		{
			cout<<arr[i]<<", count="<<count[arr[i]-97]<<endl;
			count[arr[i]-97]=0;
		}
	}
	


}
int main()
{

	count_chars ();
	return 0;
}
