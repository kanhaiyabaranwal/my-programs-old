#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
/*void quicksort(vector<int> arr,int lower,int upper)
{
 	cout<<"will do quick sort\n";
}*/


int main(){
	//FILE *f=fopen("D:\kanhaiya\Algorithms","r");
	ifstream ifs;
	
	string file("file");
	//string fileFull;
	//fileFull.append();
	int fileCount=1;
	stringstream ss;
	while(fileCount<2)
	{
		ss<<fileCount;
		file.append(ss.str());
		cout<<"file is "<<file<<endl;
		ifs.open("file1.txt",ios::in);
		//ifs.open(file,ios::in);
		string str;
		vector<int> arr;
		//arr.capacity(10);
		int count=0;
		while(getline(ifs,str))
		{
			cout<<str<<endl;
			arr.push_back(atoi(str.c_str()));
			if(count++>=9)
			{
				cout<<"limit reached\n";
				cout<<"will sort only 10 characters at a time\n";
				break; 
			}
		}
		cout<<"elements to be sorted are"<<endl;
		for(int i=0;i<count;i++)
		{
			cout<<arr[i]<<"\t";
		}
		sort(arr.begin(),arr.end());
		//quicksort(arr,0,9);
		cout<<"Numbers after sorting"<<endl;
		for(int i=0;i<count;i++)
		{
			cout<<arr[i]<<"\t";
			
		}
	}
	return 0;
}

