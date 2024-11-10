#include<iostream>
#include<unordered_set>
#include<vector>
#include<utility>

using namespace std;


int bipartite_graph()
{
	vector< pair<int,int> > pvec;
	pvec.push_back(make_pair(1,2));
	pvec.push_back(make_pair(1,3));
	pvec.push_back(make_pair(2,4));
	pvec.push_back(make_pair(2,5));
	pvec.push_back(make_pair(3,6));
	pvec.push_back(make_pair(3,7));
	pvec.push_back(make_pair(1,7));
	unordered_set<int> s1,s2;
	for(int i=0;i<pvec.size(); i++)
	{
		cout<<pvec[i].first<<","<<pvec[i].second<<endl;
		int v1=pvec[i].first;
		int v2=pvec[i].second;
		//if v1 and v2 in s1 or v1 and v2 in s2
		if((s1.find(v1)!=s1.end() && s1.find(v2)!=s1.end())
		|| (s2.find(v1)!=s2.end() && s2.find(v2)!=s2.end()))
			return false;
		
		//if v1 in s1 but v2 not in s2, insert into s2
		if(s1.find(v1)!=s1.end() && s2.find(v2)==s2.end())
				s2.insert(v2);
		//if v1 in s2 but v2 not in s1, insert into s1
		if(s2.find(v1)!=s2.end() && s1.find(v2)==s1.end())
				s1.insert(v2);
		
		//if v2 in s1 but v1 not in s2, insert into s2
		if(s1.find(v2)!=s1.end() && s2.find(v1)==s2.end())
				s2.insert(v1);
		
		//if v2 in s2 but v1 not in s1, insert into s1
		if(s2.find(v2)!=s2.end() && s1.find(v1)==s1.end())
				s1.insert(v1);
				
		if(s1.find(v1)==s1.end() && s2.find(v1)==s2.end()
			&& (s1.find(v2)==s1.end() && s2.find(v2)==s2.end()))
		{
			s1.insert(v1);
			s2.insert(v2);
		}
		
	}
	typedef unordered_set<int>::const_iterator siter;
	siter iter=s1.begin();
	cout<<"First set is: ";
	while(iter!=s1.end())
	{
		cout<<*iter<<",";
	}
	iter=s2.begin();
	cout<<"Second set is: ";
	while(iter!=s2.end())
	{
		cout<<*iter<<",";
	}
	return true;
}

int main()
{
	if(bipartite_graph())
		cout<<"This is bipartite graph"<<endl;
	else
		cout<<"This is not a bipartite graph"<<endl;
	return 0;
	
}
