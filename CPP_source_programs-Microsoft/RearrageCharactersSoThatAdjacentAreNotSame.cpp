#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct CountChar{
	int count;
	char c;
	CountChar(int count,char c):count(count),c(c){
	}
	CountChar():count(0),c('\0'){
	}
	bool operator<(const CountChar &input) const{
		return count<input.count;
	}
	
};
class compare{
	public:
	bool operator()(const CountChar& lhs, const CountChar& rhs) const
	{
		return lhs.count > rhs.count;
	}
};

typedef priority_queue<CountChar> PQ;
void PopulatePQ(const string inputString, PQ& pq )
{
	int count[26]={0};
	for(int i=0;i<inputString.length();i++)
	{
		count[inputString[i]-'a']++;	
	}
	for(int i=0;i<26;i++)
	{
		
		if(count[i])
		{
			cout<<"Pushing "<<char(i+'a')<<", with count:"<<count[i];
			pq.push(CountChar(count[i],char(i+'a')));
		}
			
	}	
	
}
string RearrangePQString(PQ pq)
{
	string rearrangedString="";
	CountChar prev;
	while(pq.size())
	{
		auto top=pq.top();
		pq.pop();
		rearrangedString.append(1,top.c);
		top.count--;
		if(prev.count)
			pq.push(prev);
		prev=top;

	}
	
	return rearrangedString;
}

void RearrageString(string inputString)
{
	PQ pq;
	PopulatePQ(inputString,pq);
	string rearrangedString = RearrangePQString(pq);
	cout<<"RearrangedString is "<<rearrangedString<<endl;
	return;
}



int main()
{
	string str="aaaaaabbbbccccdef";
	RearrageString(str);
}

