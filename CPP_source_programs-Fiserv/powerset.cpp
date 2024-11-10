#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

void printUtil(vector<int>& ivec, int start,int lenRemain,vector<int> tvec,int isDummy=0)
{
	static int count=0;
	cout<<"Call:"<<count++<<" start="<<start<<", lenRemain="<<lenRemain<<endl;
	//for each element in target set print the elements
	if(!lenRemain)
	{
		cout<<"{";
		copy(tvec.begin(),tvec.end()-1,ostream_iterator <int >(cout , ","));
		
		cout<<tvec.back()<<"},";
		cout.flush();
	}
	if(lenRemain>0)
	{
		vector<int> pvec;
		int i=start;
		if(isDummy)
		{
			pvec.push_back(ivec[i]);
			i++;
			lenRemain--;
		}
		else
			pvec=tvec;	
		while(i<=lenRemain)
		//for(;i<=ivec.size()-lenRemain;i++)
		{
			cout<<"Before:Size of pvec="<<pvec.size()<<", size of tvec="<<tvec.size()<<endl;
			pvec.push_back(ivec[i]);
			printUtil(ivec,i+1,lenRemain-1,pvec);
			//if(isDummy)
				pvec.pop_back();
			cout<<"After:Size of pvec="<<pvec.size()<<", size of tvec="<<tvec.size()<<endl;
			i++;
		}
	}
}


//create subset of length len
void print(vector<int>& ivec, int len)
{
	vector<int> tvec;
	for(int i=0;i<ivec.size()-len;i++)
	{
		printUtil(ivec,i,len,tvec,1);
	}
}

void powerset(vector<int>& ivec)
{
	int len=ivec.size();
	for(int i=1;i<=len;i++)	//for each length create subset
	{
		cout<<"Elements of length "<<i<<endl;
		print(ivec,i);
		cout<<endl;
	}
}

int main()
{
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	cout<<"Elements-> ";
	copy(ivec.begin(),ivec.end(),ostream_iterator <int >(cout , ","));
	cout<<endl;
	cout<<"Showing power sets"<<endl;
	powerset(ivec);
	return 0;
}
