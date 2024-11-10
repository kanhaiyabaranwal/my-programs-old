#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

typedef map<int,char> MAP;
typedef map<int,char>::iterator ITER;
void assign(MAP& m_map,int keyBegin,int keyEnd, char val)
{
	if(keyBegin>=keyEnd)
		return;

	//int keyEnd=10;	
	ITER iter2=m_map.upper_bound(keyEnd);
	if(iter2==m_map.end())
	{
		iter2--;
		char temp=iter2->second;
		cout<<"end:erasing last before"<<endl;
		if(iter2->first>keyBegin)	
			m_map.erase(iter2);
		cout<<"end:Inserting temp"<<endl;
		m_map.insert(make_pair(keyEnd,temp));
	}	
	//upper_bound()- Returns an iterator pointing to the first element with keyBegin greater than k, or end() 
	else
	{
		iter2--;
		cout<<"iter2->second="<<iter2->second<<" and val="<<val<<endl;
		//if(iter2->first!=keyEnd && iter2->second!=val)
		if(iter2->first!=keyEnd)
		{
			cout<<"Iam inside"<<endl;
			char temp=iter2->second;
			std::pair<std::map<int,char>::iterator,bool> ret;
			cout<<"Inserting temp:"<<temp<<"at keyBegin "<<keyEnd<<endl;
			ret=m_map.insert(make_pair(keyEnd,temp));
			iter2=ret.first;
			//iter2++;
			//m_map.insert(make_pair(keyEnd,temp);
			//iter2++;
		}
		else
		{
			//do nothing
			;
		}
	}
	//int keyBegin=4;
	//char val='X';
	ITER iter=m_map.lower_bound(keyBegin);	//returns iter with same or greater keyBegin
	
	if(iter->first != keyBegin)
	{
		std::pair<std::map<int,char>::iterator,bool> ret;
		cout<<"Inserting keyBegin1"<<endl;
		ret=m_map.insert(make_pair(keyBegin,val));
		//set new iterator	
		iter=ret.first;
	}
	else
	//if(iter!=m_map.begin())
		m_map[iter->first]=val;

	iter++;
		
	//check for duplicate
	cout<<"Done erasing "<<endl;
	m_map.erase(iter,iter2);
	cout<<"Done erasing again"<<endl;
	ITER iter_clean=m_map.begin();
	ITER previter=iter_clean;
	ITER save_iter=m_map.end();
	for(;iter_clean!=m_map.end();iter_clean++)	
	{
		if(previter->second==iter_clean->second)
			save_iter=iter_clean;
		previter=iter_clean;
	}	
	if(save_iter!=m_map.end())
		m_map.erase(save_iter);
	
		
	//cout<<"lower_bound(c)="<<iter->second<<endl;
}

int main()
{
	//map<int,char> m_map;
	MAP m_map;
	m_map.insert(make_pair(-100,'Z'));
	m_map.insert(make_pair(2,'A'));
	m_map.insert(make_pair(5,'B'));
	m_map.insert(make_pair(9,'C'));
	m_map.insert(make_pair(15,'D'));
	cout<<"map before assign"<<endl;
	for(ITER iter=m_map.begin();iter!=m_map.end(); iter++)
		cout<<"keyBegin="<<iter->first<<" ; val="<<iter->second<<endl;
	//assigns value with keyBegins between 7 and 10
	//assign(m_map,4,10,'X');
       cout<<"Enter values:"<<endl;
        int val1,val2;
        char ch;
        cin>>val1>>val2>>ch;
        //imap.assign(5,7,'X');
        assign(m_map,val1,val2,ch);

	//assign(m_map,7,10,'C');
	cout<<"map after assign"<<endl;
	for(ITER iter=m_map.begin();iter!=m_map.end(); iter++)
		cout<<"keyBegin="<<iter->first<<" ; val="<<iter->second<<endl;
	return 0;
}
