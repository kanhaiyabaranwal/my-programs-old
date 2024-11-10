/*
https://www.youtube.com/watch?v=Vu84lmMzP2o&t=747s
http://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
*/

#include<iostream>
#include<vector>
using namespace std;

struct Point
{
	int x,y;
	Point(int _x, int _y) : x(_x),y(_y){}
	bool operator == (const Point& other) { return (x == other.x && y == other.y);}
};

enum Orientation
{
	AntiClockWise = -1,
	Collinear = 0,
	ClockWise = 1
};

/*
Find the orientation between below two line
.            --->               --->
.    Line1:   PQ       Line2:    PR
*/
Orientation getOrientation(Point p, Point q, Point r)
{
	int x1 = p.x - q.x;    int y1 = p.y - q.y;
	int x2 = p.x - r.x;    int y2 = p.y - r.y;

	int cross_product = x1*y2 - x2*y1;

	if( cross_product > 0)
		return AntiClockWise;
	if( cross_product < 0)
		return ClockWise;

	return Collinear;
}

/*
. Algo: This will return which is the farthest point from P?
. Precondition: p,q,r are in same line
*/

inline Point getFarPoint(Point p, Point q, Point r)
{
	return (abs(p.x-q.x) > abs(p.x-r.x)) ? p : r;
}

/*
Algo:
1) Find the element having lowest x axis value, this will be our staring point.
2) From the starting point(P) find the next point(Q) for  which is all the 
elements are in the rightside of line PQ . i.e. all other points are clockwise
3)If two points are Collinear, then consider the value which is far from point P 
*/
vector<Point*> wrapTheGift(vector<Point*> points)
{
	int n = points.size();
	if(n <= 3)
		return points;

	vector<Point*> result;
	int start = 0;
	int i =1;
	for(; i<n; i++)
	{
		if( points[i]->x < points[start]->x )
			start = i;
	}
	result.push_back(points[start]);

	int p,q=0,r=0;
	p=start;	
	do
	{
		q =  (p+1)%n;
		//find  left most point
		for(int r=0; r<n; r++)
		{
			if(q==r || p ==r) //same point we can skip..
				continue;
			Orientation res = getOrientation(*(points[p]),*(points[q]),*(points[r]));
			if(res == Collinear)
				q = (abs(points[p]->x - points[q]->x) > abs(points[p]->x - points[r]->x)) ? q : r;
			else if(res == AntiClockWise)
				q = r;
		}
		result.push_back(points[q]);
		p = q;
	}
	while(p!=start);
	return result;
}

int main_1_GiftWrappingAlgorithm_ConvexHull()
{
	vector<Point*> points;
	points.push_back(new Point(0,3));	points.push_back(new Point(2,2));
	points.push_back(new Point(1,1));	points.push_back(new Point(2,1));
	points.push_back(new Point(3,0));	points.push_back(new Point(0,0));
	points.push_back(new Point(3,3));

	vector<Point*> wrapper = wrapTheGift(points);
	// Print Result
	for (size_t i = 0; i < wrapper.size(); i++)
		cout << "(" << wrapper[i]->x << ", " << wrapper[i]->y << ")\n";

	return 0;
}
