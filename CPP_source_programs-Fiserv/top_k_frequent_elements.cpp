//Find top k frequent elements from a stream of elements in O(k) space and O(nlogk) time
//input from file input.txt
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

typedef map<int,int>  mymap;

void top_k_frequent_elements(int k)
{
	ifstream in("input.txt");
	int input;
	mymap imap;
	cout<<"elements are:"<<endl;
	while(in>>input)
	{
		cout<<input<<" ";
		mymap::iterator iter=imap.find(input);	
		if(iter!=imap.end())	
		{
			cout<<"Before:element "<<iter->first<<" found with counter "<<iter->second<<endl;
			(iter->second)++;
			cout<<"After:element "<<iter->first<<" found with counter "<<iter->second<<endl;
		}
		else
		{
			if(imap.size()<k)
			{
				cout<<"Inserting element "<<input<<" with counter 1"<<endl;
				imap[input]=1;		//insert
			}
			else
			{
				cout<<"Element "<<input<<" not found in imap,decreasing counter for each"<<endl;
				for(iter=imap.begin();iter!=imap.end(); iter++)
				{
					if(--(iter->second)==0)		//decrease counter of each element,if 0 remove element and insert current input with counter 1
					{
						cout<<"Removing element "<<iter->first<<" with counter "<<iter->second<<endl;
						imap.erase(iter);
						cout<<"Inserting element "<<input<<" with counter 1"<<endl;
						imap[input]=1;
						//done, no need to process further break
						break;
					}
				}
					
			}
		}
	}
	
	cout<<"Showing most frequent elements"<<endl;
	for(mymap::const_iterator iter=imap.begin();iter!=imap.end(); iter++)
		cout<<"Element:"<<iter->first<<"; count:"<<iter->second<<endl;
	cout<<endl<<"Done"<<endl;
	return;
}
int main()
{
	cout<<"Enter number:";
	int k;
	cin>>k;
	cout<<"Finding top "<<k<<" elements"<<endl;
	top_k_frequent_elements(k);
	return 0;
}
		
	
