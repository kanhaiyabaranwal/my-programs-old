//find nth number in number system with digits 3 and 4 only.
//Numbers would be 3,4,33,34,43,44,333,334,343,344...
#include<iostream>
#include<string>
#include<new>
using namespace std;
void out_of_mem()
{
	cout<<"Out of memory"<<endl;
	exit(1);
}
string find(string *const num,int n,int m)
{
	int indexof2=1,powof2=2,sumofpowof2=2;
	num[1]="3";
	num[2]="4";
	int i=1;
	while(i<n)
	{
		for(int j=0;j<powof2;j++)
			num[i+powof2+j]="3"+num[i+j];
		int k=i;
		i+=powof2;
		for(int j=0;j<powof2;j++)
			num[i+powof2+j]="4"+num[k+j];
		//i=powof2;
		powof2<<=1;
		sumofpowof2+=powof2;
	}
	for(i=1;i<=n;i++)
		cout<<"num["<<i<<"]="<<num[i]<<endl;
	return num[m];
}
int main()
{
	int n;
	cout<<"Number system with digits 3 and 4 only."<<endl;
	cout<<"Numbers in sequence are  3,4,33,34,43,44,333,334,343,344..."<<endl;
	cout<<"Enter n where you look for nth number"<<endl;
	cin>>n;	
	int k=0,indexof2=1,powof2=2,sumofpowof2=2;
	while(sumofpowof2<n)
	{
		indexof2+=1;
		powof2<<=1;
		sumofpowof2+=powof2;
	}
	cout<<"smallest sumofpowof 2 larger than or equal to "<<n<<" is "<< sumofpowof2<<",index is "<<indexof2<<" and largest pow is "<<powof2<<endl;
	set_new_handler(out_of_mem);
	cout<<"sumofpowof2="<<sumofpowof2<<endl;
	//string * const str=new string[sumofpowof2];
	string * const str=new string[100];
	//string str[100];
	/*string * const num=new string[3];
	num[0]="Kanhaiya";
        num[1]="Prasad";
        num[2]="Baranwal";
        for(int i=0;i<3;i++)
                cout<<"str["<<i+1<<"]="<<num[i]<<endl;
	*/
	string num=find(str,sumofpowof2,n);
	cout<<n<<"th string is "<<num<<endl;
	return 0;

}
