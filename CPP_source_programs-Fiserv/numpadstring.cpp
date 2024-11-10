//Given- map of digits and set of characters assocated with it, as in numpad
//Mappings
/* 	1-AB
 	2-CD
	3-EF
	4-GH
	5-IJK
	6-LMN
	7-OPQ
	8-RST
	9-UVW
	0-XYZ 
*/
//Required-For given number, print combination of all characters possible
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void create_numpad(map<char,vector<char> >& numpad_map)
{
	//map<char,vector<char> > numpad_map;
	vector<char> inputvec;
	char input='A';
	char integer='1';
	int count=0;
	while(count<10)
	{
		inputvec.erase(inputvec.begin(),inputvec.end());
		inputvec.push_back(input++);
		inputvec.push_back(input++);
		if(count>3)
			inputvec.push_back(input++);
		numpad_map[integer++]=inputvec;
		vector<char>::const_iterator iter=numpad_map[integer-1].begin();
		cout<<"map[integer-1]="<<*iter<<",and "<<*(++iter)<<",and "<<*(++iter)<<endl;
		count++;
	}

}
void numpad_string(vector<char>& cvec,int index, char input_num[],map<char,vector<char> >& numpad_map)
{
	if(index>=strlen(input_num))
	{
		copy(cvec.begin(),cvec.end()-1,ostream_iterator<char>(cout,","));
		cout<<cvec.back()<<"\t";
		//for(int i=0;i<cvec.size();i++)
		//	cout<<cvec[i]<<"\t";
		return;
	}
	else
	{
		vector<char>::const_iterator iter=numpad_map[input_num[index]].begin();	
		for(;iter!=numpad_map[input_num[index]].end();iter++)
		{
			if(index==0)
				cout<<"\nNext->";
			cvec.push_back(*iter);
			numpad_string(cvec,index+1,input_num,numpad_map);
			cvec.pop_back();
		}
	}
}
int main()
{
	cout<<"Program to print possible strings on a numpad from input number"<<endl;
	map<char,vector<char> > numpad_map;
	create_numpad( numpad_map);
	cout<<"Input Number->";
	char num[20];
	cin>>num;
	vector<char> cvec;
	cout<<"Strings formed are:"<<endl;
	numpad_string(cvec,0,num,numpad_map);
	cout<<"All possible strings shown"<<endl;
	return 0;
}
	


