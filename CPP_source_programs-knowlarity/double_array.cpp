#include <stdio.h>
#include <iostream>
using namespace std;
// Same as "void print(int **arr, int m, int n)"
void print(int *arr[], int m, int n)
{
    int i, j;
	bool flag=0;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
	{
	if(!flag)
		cout<<"Inside flag1"<<endl;

        //printf("%d ", *((arr[i]) + j));
        printf("%d ", arr[i][j]);
	if(!flag)
	{
		cout<<"Inside flag2"<<endl;
		flag=1;
	}
	}
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m = 3;
    int n = 3;
    print((int **)arr, m, n);
    return 0;
}
