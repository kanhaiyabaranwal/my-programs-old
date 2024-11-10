#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;

struct point{
	int x,y;
	point(int x1,int y1):x(x1),y(y1) {
	}
	bool operator==(const point& p) const {
		return x==p.x && y==p.y;
}
	
};

struct hashpoint{
	int operator()(const point& p) const {
		return hash<int>()(p.x)^hash<int>()(p.y);
	}
};

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

pair<int,int> get_canonical_form(int nominator, int denominator){
	int a=nominator;
	int b=denominator;
	a/=gcd(a,b);
	b/=gcd(a,b);
	return make_pair(a,b);
}

struct line{
	pair<int,int> slope;
	pair<int,int> intercept; 
	line(point p1,point p2):
		slope(p1.x!=p2.x ? get_canonical_form(p1.y-p2.y,p1.x-p2.x):make_pair(1,0)),
		intercept(p1.x!=p2.x ? get_canonical_form(p1.x*p2.y-p2.x*p1.y,p1.x-p2.x):make_pair(1,0)){
		
	}
	bool operator==(const line& l) const {
		return l.slope==slope && l.intercept==intercept;
	}
};

struct hashline{
	int operator()(const line& l) const {
		return hash<int>()(l.slope.first)^hash<int>()(l.slope.second)^hash<int>()(l.intercept.first)^hash<int>()(l.intercept.second);
	}
};

int line_covering_max_points(vector<point>& pvec){
	unordered_map<line,unordered_set<point,hashpoint>, hashline> umap;
	for(int i=0;i<pvec.size();i++)
	{
		for(int j=i+1;j<pvec.size();j++)
		{
			line l(pvec[i],pvec[j]);
			umap[l].insert(pvec[i]);
			umap[l].insert(pvec[j]);
		}
	}
	
	int max_points=0;
	unordered_map<line,unordered_set<point,hashpoint>, hashline>::const_iterator iter=umap.begin();
	for(;iter!=umap.end();iter++)
	{
		int n=(*iter).second.size();
		if(n>max_points)
			max_points=n;
	}
	cout<<"Max number of points through a line is "<<max_points<<endl;
	return max_points;
}

int main()
{
	cout<<"Program to find line with maximum covering points"<<endl;
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
	line_covering_max_points(pvec);
	return 0;
}
