//suitable for scenario when range is comparable to number of elements.
#include<iostream>

using namespace std;
typedef struct {
	int num;
	int digit;
} NUM_T;

//int count_sort(int arr[],int len,int range)
int count_sort(NUM_T arr[],int len,int range,NUM_T *output)
{
	cout<<"Program for counting sort"<<endl;
	//int arr[]={2,3,5,7,2,1,8,4,6};
	//int len=sizeof(arr)/sizeof(arr[0]);
	//int range=9;
	int count[range];
	//int output[len];
	//NUM_T output[len];
	
	for(int i=0;i<range;i++)
		count[i]=0;
	for(int i=0;i<len;i++)
		count[arr[i].digit]++;
	for(int i=1;i<range;i++)
		count[i]+=count[i-1];
	int k=0;

	for(int i=0;i<len;i++)
	{
		output[count[arr[i].digit]-1].digit=arr[i].digit;
		output[count[arr[i].digit]-1].num=arr[i].num;
		count[arr[i].digit]--;
	}
	return 0;
}

int radix_sort(int arr[],int len,int nbrofdigits,int *output)
{

	NUM_T *pair1=new NUM_T[len];
	NUM_T *pair2=new NUM_T[len];
	int divisor=1;	
	NUM_T *temp;
	for(int d=1;d<=nbrofdigits; d++)
	{
		for(int i=0;i<len;i++)
		{
			pair1[i].num=arr[i];
			pair1[i].digit=(arr[i]/divisor)%10;
			//cout<<"num_pair["<<i<<"]=("<<num_pair[i].num<<","<<num_pair[i].digit<<"),"<<endl;
		}
		int range=10;
		count_sort(pair1,len,range,pair2);
		cout<<"Output in cycle "<<d<<endl;
		for(int i=0;i<len;i++)
			cout<<pair2[i].num<<","<<pair2[i].digit<<endl;
		divisor*=10;
		//change pointers for next cycle
		temp=pair2;
		pair2=pair1;
		pair1=temp;
	}
	for(int i=0;i<len;i++)
		output[i]=pair1[i].num;
	return 0;
}

int main()
{
	int arr[]={343,546,567,789,267,873,250,543,1,871,832,529,633,923,754,610,729,64,568,234,459,123,5,764,980};
	int len=sizeof(arr)/sizeof(arr[0]);
	int output[len];
	int nbrofdigits=3;
	radix_sort(arr,len,nbrofdigits,output);
	for(int i=0;i<len;i++)
		cout<<output[i]<<",";
	cout<<endl;
	return 0;
}
		
