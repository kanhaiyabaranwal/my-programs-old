#include<iostream>
using namespace std;
#define NUM 5
//optimum_matrix_chain_multiplication program using top-down DP
int op[NUM][NUM];
int optim(int *arr,int i,int j)
{
        int min=-1,res=0;
        if(i==j)
                return 0;
        if(op[i][j])
                return op[i][j];
        for(int k=i;k<j;k++)
        {
                res=optim(arr,i,k)+optim(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
                if(min==-1 || min>res)
                        min=res;
        }
        op[i][j]=min;
        return min;
}

int main()
{
        int arr[NUM]={40,20,30,10,30};
	cout<<"arr size="<<sizeof(arr)/sizeof(arr[0])<<endl;
        for(int i=0;i<NUM;i++)
                for(int j=0;j<NUM;j++)
                        op[i][j]=0;
	cout<<"op values initialized to 0."<<endl;
        int min=optim(arr,1,NUM-1);     //indexes are passed
        cout<<"Minimum operations required are :"<<min<<endl;
        return 0;
}
