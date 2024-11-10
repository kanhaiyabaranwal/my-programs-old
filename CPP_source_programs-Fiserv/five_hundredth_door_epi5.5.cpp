#include<iostream>
using namespace std;

int main()
{
	bool r[501]{0};
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
			if(i*j<=500)
				r[i*j]=!r[i*j];
	for(int i=1;i<=500;i++)
		if(r[i])
			cout<<i<<" ";
	cout<<endl;
	return 0;
}
