#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	//char arr[4]={{'k'},{'a'},{'n'},{'h'}};
	char arr[][9]={"kanhaiya","Prasad","Baranwal"};
	int sz=sizeof(arr)/sizeof(arr[0]);
	cout<<"sizeof arr="<<sz<<endl;
	cout<<"arr[3]="<<arr[3]<<endl;
	printf("arr[4]=%d\n",arr[4]);
	return 0;
}
