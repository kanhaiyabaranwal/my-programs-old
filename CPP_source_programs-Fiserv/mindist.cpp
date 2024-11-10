//find the minimum distance between two given words.
//Find the minimum distance between 'Amazon' and 'The' 
#include<iostream>
#include<cstdlib>
#include<sstream>
using namespace std;

int main()
{
	string str="Amazon is one of the best company to work for. Forest amazon is the beautiful forest.";
	cout<<"string->"<<str<<endl;
	stringstream ss(str);
	string s;
	string s1="amazon",s2="the";
	char input[20]={0};
	int prevchar=0;		//1-amazon,2-the
	int mindist=INT_MAX;
	int dist=0;
	while(ss>>s)
	{
		cout<<s<<endl;
		strcpy(input,s.c_str());
		char *c=input;
			if((s=="amazon" || s=="Amazon") )
			{
				if(prevchar==2 )	//prev char was the
				{
					cout<<"amazon found after the after distance "<<dist<<endl;
					if(dist<mindist)
						mindist=dist;
				}
				dist=0;		//counting reset
				prevchar=1;
			}
			else if(s=="The" || s=="the")
			{
				if(prevchar==1 )	//prev char was amazon and distance was less
				{
					cout<<"the found after amazon after distance "<<dist<<endl;
					if(dist<mindist)
						mindist=dist;
				}
				dist=0;
				prevchar=2;
			}
			else
				dist++;
	}
	cout<<"minimum distance between amazon and the is "<<mindist<<" and last dist="<<dist<<endl;
	return 0;
}
