#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void next_high_number_with_same_digits ()
{
	int n=234729654;
	int largest=n%10;
	vector<int> ivec;
	ivec.push_back(largest);
	n/=10;
	int r;
	while(n)
	{
		r=n%10;
		int temp=n/10;
		if(r<largest)
		{
			n=(temp*10+largest)*10+r;
			break;
			
		}
		else
		{
			largest=r;
			n/=10;
			ivec.push_back(r);
		}
	}
	sort(ivec.begin(),ivec.end());
	for(int i=0;i<ivec.size();i++)
	{
		n=n*10+ivec[i];
	}
	cout<<"next_high_number_with_same_digits="<<n<<endl;
}
int main()
{

	next_high_number_with_same_digits ();
	return 0;
}
