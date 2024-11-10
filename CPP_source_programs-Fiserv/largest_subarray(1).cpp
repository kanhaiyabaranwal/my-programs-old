//Program to find max subarray of equal number of * and #  from a string of only * and #.
#include<iostream>
using namespace std;
int main()
{
	char arr[]="*##*###*****####*#*###*";
	int len=strlen(arr);
	cout<<"len="<<len<<endl;
	int *newarr=new int[2*len+1];
	int newdistance[2*len+1];		//distance between pair with same number

	int *arrpos=newarr+len-1;		//allow negative positions also
	int *distance=newdistance+len-1;	//distance  for negative  positions

	for(int i=-len;i<=len; i++)
		arrpos[i]=-100,distance[i]=0;
	int pos=0;			//universal position of each character

	for(int i=0;i<len;i++)
	{
		if(arr[i]=='*')	//* is +1
			pos++;
		else
			pos--;	//# is -1
		if(arrpos[pos]!=-100)	//this number was encountered before
			distance[pos]=i-arrpos[pos];
		else		//first time pos found
			arrpos[pos]=i;	//save position of number
	}
	int max=0;
	int maxpos=0;
	for(int i=-len;i<=len;i++)
	{
		if(arrpos[i]!=-100)
		{
			cout<<"Largest distance for number "<<i<<" is "<<distance[i]<<" ,1st occr="<<arrpos[i]<<endl;
			//now find largest of all distances, that is the largest subarray.
			if(max<distance[i])
			{
				max=distance[i];
				maxpos=arrpos[i];
			}
		}
	}
	cout<<"max subarray of equal number of * and # is of length "<<max<<" and starts at pos "<<maxpos+1<<endl;
	return 0;
}
