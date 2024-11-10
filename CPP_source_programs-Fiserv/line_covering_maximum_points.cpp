//Given  a set of points, program to identify line that covers maximum number of points.
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
#define epsilon 0.00000001

struct point{
	int x;
	int y;
	point(int x1,int y1):x(x1),y(y1) {
	}
	bool operator==(point& p) const{
		return (x==p.x && y==p.y);
	}
};
struct Line{
	double m;
	double c;
	Line(point p1,point p2):m(0.0),c(0.0){
		if(p1.x!=p2.x)
		{
			m=((double)p1.y-p2.y)/((double)p1.x-p2.x);
			c=((double)p1.x*p2.y-p1.y*p2.x)/((double)p1.x-p2.x);
		}
		else
		{
			m=NAN;
			c=NAN;	
		}
		
	}
	bool operator==(const Line& l) const
	{
	 	if(m-l.m <epsilon && c-l.c<epsilon)
		 	return true;
		return false;
	}	
};
/*struct X{int i,j,k;};
 
struct hash_X{
  size_t operator()(const X &x) const{
    return hash<int>()(x.i) ^ hash<int>()(x.j) ^ hash<int>()(x.k);
  }
};

struct compare_line{
	bool operator()(const Line& l1,const Line& l2) const
	{
	 	if(l1.m-l2.m <epsilon && l1.c-l2.c<epsilon)
		 	return true;
		return false;
	}
};*/

struct hash_line{
	bool operator()(const Line& l) const
	{
	 	return hash<double>()(l.m) ^ hash<double>()(l.c);
	}
};

struct hash_point{
	bool operator()(const point& p) const
	{
	 	return hash<double>()(p.x) ^ hash<double>()(p.y);
	}
};

struct compare_point{
	bool operator ()(const point& p1, const point& p2) const {
		return p1.x<p2.x || p1.y<p2.y;
	}
};

int find_line_covering_maximum_points(const vector<point>& ivec)
{
	//unordered map of line and count of points to the number
	//unordered_map<Line,set<point,compare_point>, hash<Line>, compare_line > hmap;
	//unordered_map<Line,set<point,compare_point>, hash_line > hmap;
	unordered_map<Line,unordered_set<point,hash_point>, hash_line > hmap;
	for(int i=0;i<ivec.size()-1;i++)
	{
		for(int j=i+1;j<ivec.size();j++)
		{
			//point p1(ivec[i]);
			//point p2(ivec[j]);			//m=((double)p1.y-p2.y)/((double)p1.x-p2.x);
			//c=((double)p1.x*p2.y-p1.y*p2.x)/((double)p1.x-p2.x);
			Line l(ivec[i],ivec[j]);
			hmap[l].insert(ivec[i]);
			hmap[l].insert(ivec[j]);
		}
	}
	//unordered_map<Line,set<point,compare_point>, hash_line >::const_iterator iter=hmap.begin();
	unordered_map<Line,unordered_set<point,hash_point>, hash_line >::const_iterator iter=hmap.begin();
	cout<<"Traversing through unordered map of line and points through"<<endl;
	int maxpoint=0;
	for(int l=0;iter!=hmap.end();iter++,l++)
	{
		cout<<"Line["<<l<<"] details: m="<<iter->first.m<<" ,c="<<iter->first.c<<endl;
		//set<point,compare_point>::const_iterator siter=iter->second.begin();
		unordered_set<point,hash_point>::const_iterator siter=iter->second.begin();
		cout<<"point details: ";
		int i;
		for(i=0;siter!=iter->second.end();siter++,i++)
				cout<<"point["<<i+1<<"]="<<(*siter).x<<","<<(*siter).y<<";\t";
		cout<<endl;
		if(i>maxpoint)
			maxpoint=i;
	}
	cout<<"maximum number of points through a line is "<<maxpoint<<endl;
	maxpoint=0;
	for(const pair<Line,unordered_set<point,hash_point> >& p:hmap)
		if(p.second.size()>maxpoint)
			maxpoint=p.second.size();
	cout<<"maximum number of points through a line calculated again is "<<maxpoint<<endl;
	return 0;
}

int main()
{
	vector<point> pvec;
	pvec.push_back(point(2,3));
	pvec.push_back(point(2,6));
	pvec.push_back(point(5,3));
	pvec.push_back(point(5,6));
	pvec.push_back(point(12,3));
	pvec.push_back(point(2,30));
	pvec.push_back(point(32,13));
	pvec.push_back(point(5,3));
	pvec.push_back(point(20,34));
	pvec.push_back(point(4,24));
	pvec.push_back(point(29,13));
	find_line_covering_maximum_points(pvec);
	return 0;
}

