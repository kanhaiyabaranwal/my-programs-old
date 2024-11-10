#define __IBMCPP_TR1__ 1
#include<iostream>
#include<sstream>
#include<fstream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

class star{
	int id;
	int x,y,z;
	int dist;
	public:
	star(int ID,int X,int Y,int Z):id(ID),x(X),y(Y),z(Z),dist(x*x+y*y+z*z) {}
	int getID() const { return id;}
	int getX() const { return x;}
	int getY() const { return y;}
	int getZ() const { return z;}
	int getDist() const { return dist;}
	bool operator<(const star& s) const { return  dist<s.dist; }
};
int find_closest_stars(vector<star>& svec)
{
	vector<star>::const_iterator iter=svec.begin();
	size_t sz=svec.size();
	priority_queue<star,vector<star> > pstar;
	int k=3;
	int i;
	for(i=0;iter!=svec.end() && i<k;iter++,i++)
	{
		cout<<"star["<<i<<"]->"<<iter->getID()<<","<<iter->getX()<<","<<iter->getY()<<","<<iter->getZ()<<endl;
		pstar.push(*iter);
	}
	while(i<sz)
	{
		cout<<"Current star's dist="<<iter->getDist()<<", max dist in priority queue="<<pstar.top().getDist()<<endl;
		if(iter->getDist() < pstar.top().getDist() )
		{
			cout<<"Current star will be pushed"<<endl;
			pstar.pop();
			pstar.push(*iter);
		}	
		else
			cout<<"Current star not pushed"<<endl;
		iter++,i++;
	}
	cout<<"Iterating through closest stars ..."<<endl;
	while(pstar.size()>0)
	{
		cout<<pstar.top().getID()<<"\t";
		pstar.pop();
	}
	return 0;


}

int main()
{
	cout<<"Program to find closest 3 stars\n";
	ifstream in("start_dist.txt");
	string line;	
	vector<star> svec;
	while(in>>line)
	{
		cout<<"Next star "<<line<<endl;
		stringstream ss(line);
		string id,x,y,z;
		int ID,X,Y,Z;
		getline(ss,id,',');
		getline(ss,x,',');
		getline(ss,y,',');
		getline(ss,z);
		cout<<"Star id="<<id<<", x="<<x<<", y="<<y<<", z="<<z<<endl;
		ID=atoi(id.c_str());
		X=atoi(x.c_str());
		Y=atoi(y.c_str());
		Z=atoi(z.c_str());
		star s(ID,X,Y,Z);
		svec.push_back(s);
	}
	find_closest_stars(svec);
		
	
	return 0;
}
