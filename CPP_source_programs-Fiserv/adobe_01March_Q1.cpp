#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
	cout<<"Adobe online test"<<endl;
	int a[3][3][2]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
	printf("%d %d %d \n", *(*(*(a+0)+2)+1),*(*(*(a+2)+1)+1),	*(a[1][1]+1));
	
	int b[2][3]={5,6,7,8,9,10};
	printf("%d %d %d",b[0],b[1]);
	
	return 0;
}
