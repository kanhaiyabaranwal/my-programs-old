#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define LEN 3
int largest[LEN][LEN];
int pos[LEN][LEN]={{1,7,8},{3,4,9},{2,5,6}};
int largest_snake_util(int i,int j,int print=0)
{
	//DP
	if(largest[i][j] > 1)
		return largest[i][j];
	int lenleft=0,lenright=0,lenup=0,lendown=0;
	//down length
	if(i-1>=0 and (pos[i-1][j]-pos[i][j])==1)
		lendown=largest_snake_util(i-1,j);	
	//up length
	if(i+1<LEN and (pos[i+1][j]-pos[i][j])==1)
		lenup=largest_snake_util(i+1,j);	
	//left length
	if(j-1>=0 and (pos[i][j-1]-pos[i][j])==1)
		lenleft=largest_snake_util(i,j-1);	
	//right length
	if(j+1<LEN and (pos[i][j+1]-pos[i][j])==1)
		lenright=largest_snake_util(i,j+1);	
	int largeside=lenleft>lenright?lenleft:lenright;
	int largeupdown=lenup>lendown?lenup:lendown;
	int largestAll=largeside>largeupdown?largeside:largeupdown;
	largest[i][j]=largestAll+1;
	return largest[i][j];
}

void LargestSnake()
{
	for(int i=0;i<LEN;i++)
		for(int j=0;j<LEN;j++)
			largest[i][j]=1;
	int largestpath=0;
	int len=0,largetstI=-1,largestJ=-1;
	for(int i=0;i<LEN;i++)
		for(int j=0;j<LEN;j++)
		{
			len=largest_snake_util(i,j);
			if(len>largestpath)
			{
				largestpath=len;
				largetstI=i;
				largestJ=j;	
			}
		}

	//largest_snake_util(largetstI,largestJ,1);	//last arg for printing
	cout<<"Largest snake starts at pos["<<largetstI<<"]["<<largestJ<<"] and is of length "<<largestpath<<endl;
}

int main()
{
	cout<<"Program to print largest snake in a square matrix NXN where adjacent cell's value differ by 1\n";
	//Input matrix is
	for(int i=0;i<LEN;i++)
	{
		for(int j=0;j<LEN;j++)
			cout<<setw(2)<<pos[i][j]<<"  ";
		cout<<endl;
	}
	
	LargestSnake();
	return 0;
}
