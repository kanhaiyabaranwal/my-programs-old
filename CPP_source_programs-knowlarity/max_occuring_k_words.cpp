#include<iostream>
#include<queue>
#include<fstream>
#include<unordered_map>
using namespace std;

struct word_count{
	string word;
	int count;
	word_count(string str,int count=1):word(str),count(count) {}
	bool operator<(const word_count &wc) const
	{
		return count>wc.count;
	}
};

void max_occuring_k_words()
{
	string str;
	unordered_map<string,int> umap;
	ifstream in("words.txt");
	int k=4;
	priority_queue<word_count,vector<word_count> > pq;
	while(in>>str)
	{
		umap[str]++;
	}
	cout<<"Iterating through the elements in heap"<<endl;
	for(auto it=umap.begin();it!=umap.end(); it++)
	{
		if(pq.size()<k)
			pq.push(word_count(it->first,it->second));	
		else
		{
			if(pq.top().count<it->second)
			{
				pq.pop();
				pq.push(word_count(it->first,it->second));	
			}
		}
		
	}
	while(pq.size())
	{
		word_count top=pq.top();
		cout<<"next element:"<< top.word<<" and count is "<<top.count<<endl;
		pq.pop();
	}
}


int main()
{
	priority_queue<word_count,vector<word_count> > pq;
	word_count wc1("kan",1);
	word_count wc2("jam",2);
	word_count wc3("game",3);
	pq.push(wc1);
	pq.push(wc2);
	pq.push(wc3);
	cout<<"Top elem="<<pq.top().word<<endl;
	max_occuring_k_words();
	return 0;
}
