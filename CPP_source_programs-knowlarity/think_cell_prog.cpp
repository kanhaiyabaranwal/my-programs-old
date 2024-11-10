#include <iostream>
#include <assert.h>

#include <map>

#include <limits>
using namespace std;




template<class K, class V>

class interval_map {

    friend void IntervalMapTest();



private:

    //std::map<K,V> m_map;



public:
    std::map<K,V> m_map;

    // constructor associates whole range of K with val by inserting (K_min, val)

    // into the map

    interval_map( V const& val) {

        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));

    };



    // Assign value val to interval [keyBegin, keyEnd). 

    // Overwrite previous values in this interval. 

    // Do not change values outside this interval.

    // Conforming to the C++ Standard Library conventions, the interval 

    // includes keyBegin, but excludes keyEnd.

    // If !( keyBegin < keyEnd ), this designates an empty interval, 

    // and assign must do nothing.

    void assign( K const& keyBegin, K const& keyEnd, const V& val ) {

// INSERT YOUR SOLUTION HERE
	 assert(("keyBegin must be less than keyEnd", keyBegin < keyEnd));

	//upper bound handling
        typename std::map<K,V>::iterator iter2=m_map.upper_bound(keyEnd);
	//Key is greater than all keys in map
        if(iter2==m_map.end())
        {
                iter2--;
                V value=iter2->second;
		if(iter2->first>keyBegin)
	        	m_map.erase(iter2);
                m_map.insert(std::make_pair(keyEnd,value));
        }
        else	//Upperbound key is found
        {
                iter2--;
                if(iter2->first!=keyEnd)
                {
                        V value=iter2->second;
                        std::pair<typename std::map<K,V>::iterator,bool> ret;
                        ret=m_map.insert(std::make_pair(keyEnd,value));
                        iter2=ret.first;
                }
                else
                {
                        //key matches, let it go
                        ;
                }
        }
        typename std::map<K,V>::iterator iter1=m_map.lower_bound(keyBegin);  //returns iter with same or greater keyBegin

        if(iter1->first != keyBegin)
        {
                std::pair<typename std::map<K,V>::iterator,bool> ret;
                ret=m_map.insert(std::make_pair(keyBegin,val));
                //set new iterator      
                iter1=ret.first;
        }
        else
	{
		//lower bound found. replace value to say begin of interval.
                m_map[iter1->first]=val;
	}

        iter1++;
	if(iter1->first<iter2->first)
	        m_map.erase(iter1,iter2);

	//clean duplicates
	if(m_map.size()>1)
	{
		typename std::map<K,V>::iterator iter_clean=m_map.begin();
	        typename std::map<K,V>::iterator previter=iter_clean;
	        typename std::map<K,V>::iterator save_iter=m_map.end();
		iter_clean++;
	        for(;iter_clean!=m_map.end();iter_clean++)
	        {
	                if(previter->first!=iter_clean->first && previter->second==iter_clean->second)
			{
	                        save_iter=iter_clean;
				m_map.erase(save_iter);
			}
			else
	                	previter=iter_clean;
	        }
	}
	
	

    }



    // look-up of the value associated with key

    V const& operator[]( K const& key ) const {

        return ( --m_map.upper_bound(key) )->second;

    }

};



// Many solutions we receive are incorrect. Consider using a randomized test

// to discover the cases that your implementation does not handle correctly.

// We recommend to implement a function IntervalMapTest() here that tests the

// functionality of the interval_map, for example using a map of unsigned int

// intervals to char.



int main(int argc, char* argv[]) {

    //IntervalMapTest();
	typedef std::map<int,char> MAP;
	typedef std::map<int,char>::iterator ITER;
    interval_map<int,char> imap('Z');
        imap.m_map.insert(std::make_pair(2,'A'));
        imap.m_map.insert(std::make_pair(5,'B'));
        imap.m_map.insert(std::make_pair(9,'C'));
        imap.m_map.insert(std::make_pair(15,'D'));
        imap.m_map.insert(std::make_pair(2,'D'));
        cout<<"map before assign"<<"\n";
        for(ITER iter=imap.m_map.begin();iter!=imap.m_map.end(); iter++)
                cout<<"keyBegin="<<iter->first<<" ; val="<<iter->second<<"\n";
        //assigns value with keyBegins between 7 and 10
        //assign(m_map,4,10,'X');
	cout<<"Enter values:"<<endl;
	int val1,val2;
	char ch;
	cin>>val1>>val2>>ch;
        //imap.assign(5,7,'X');
        imap.assign(val1,val2,ch);
        cout<<"map after assign"<<"\n";
        for(ITER iter=imap.m_map.begin();iter!=imap.m_map.end(); iter++)
                cout<<"keyBegin="<<iter->first<<" ; val="<<iter->second<<"\n";


    return 0;

}
