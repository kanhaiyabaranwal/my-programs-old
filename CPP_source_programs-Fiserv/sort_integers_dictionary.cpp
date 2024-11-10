#include<iostream>
#include<map>
#include<set>
using namespace std;

int sort_integers_dictionary_order(int *arr,int sz)
{
	int maxNbrOfDigits=0;
	int temp;
	//find max number of digits in the array
	for(int i=0;i<sz;i++)
	{
		int temp=arr[i];
		int nbrOfDigits=0;
		while(temp>0)
		{
			nbrOfDigits++;
			temp/=10;
		}
		if(maxNbrOfDigits<nbrOfDigits)
			maxNbrOfDigits=nbrOfDigits;
	}
	cout<<"Max number of digits="<<maxNbrOfDigits<<endl;
	cout<<"Numbr of elements="<<sz<<endl;
	//create map of zero padded number and actual number
	multimap<int,int> imap;
	for(int i=0;i<sz;i++)
	{
		int temp=arr[i];
		int nbrOfDigits=0;
		int index=1;
		while(temp>0)
		{
			nbrOfDigits++;
			temp/=10;
		}
		while(maxNbrOfDigits-nbrOfDigits>0)
		{
			index*=10;
			nbrOfDigits++;
		}
		cout<<"inserting "<<arr[i]*index<<" and "<<arr[i]<<endl;
		imap.insert(make_pair(arr[i]*index,arr[i]));
	}
	cout<<"Sorting in dictionary order,map size="<<imap.size()<<endl;	
	multimap<int,int>::const_iterator iter=imap.begin();
	while(iter!=imap.end())
	{
		int count=imap.count(iter->first);
		if(count>1)
		{
			set<int> iset;
			while(count>0)
			{
				iset.insert(iter->second);
				iter++;
				count--;
			}
			set<int>::const_iterator iter1=iset.begin();
			while(iter1!=iset.end())
			{
				cout<<"Next element from the set="<<*iter1<<endl;
				iter1++;
			}
		}	
		else
		{
			//cout<<iter->first<<","<<iter->second<<endl;
			cout<<"Next element from the map="<<iter->second<<endl;
			iter++;
		}
	}
	cout<<"sorting completed "<<endl;
	return 0;
}

int main()
{
	int arr[]={1,2,10,20,100,110};
	int sz=sizeof(arr)/sizeof(arr[0]);
	cout<<"Number of elements="<<sz<<endl;
	sort_integers_dictionary_order(arr,sz);
	return 0;
}


