#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 10

struct Point{
	int x;
	int y;
	Point(int x=0,int y=0):x(x),y(y) {}
	Point& operator=(Point& p)
	{
		x=p.x;
		y=p.y;
		return *this;
	}
};

int compareX(const void* p1, const void* p2)
{
	return (((Point*)p1)->x -((Point*)p2)->x);
}
int compareY(const void* p1, const void* p2)
{
	return (((Point*)p1)->y -((Point*)p2)->y);
}

float dist(Point p1,Point p2)
{
	float d= sqrt(abs((float)(p1.x-p2.x)*(p1.x-p2.x) - (float)(p1.y-p2.y)*(p1.y-p2.y))); 
	cout<<"Distance found between points("<<p1.x<<","<<p1.y<<") and ("<<p2.x<<","<<p2.y<<") is "<<d<<endl;
	return d;
}
	
float BruteForceDist(Point p[],int s,int e,float d=float(1000.0))
{
	float min=d;
	for(int i=s;i<=e;i++)
	{
		for(int j=i;j<=e;j++)
		{
			float temp=dist(p[i],p[j]);
			if(temp<min)
				min=temp;
		}
	}
	return min;
}

float min(float d1,float d2)
{
	return d1>d2?d1:d2;
}

float closest_distance_pair(Point p[],int s,int e)
{
	if(e-s<3)
		return BruteForceDist(p,s,e);
	qsort(p+s,e-s+1,sizeof(Point),compareX);
	int mid=s+((e-s)>>2);
	float dl=closest_distance_pair(p,s,mid-1);
	float dr=closest_distance_pair(p,mid+1,e);
	float d=min(dl,dr);
	
	//find strip of points with distance closer than d from mid points
	Point strip[N];
	int k=0;
	for(int i=s;i<=e;i++)
	{
		if(abs(p[i].x-p[mid].x)<d)
			strip[k++]=p[i];
	}
	k--;	
	qsort(strip,k+1,sizeof(Point),compareY);
	float min_d=BruteForceDist(strip,0,k,d);
	return min_d;
}
// Driver program to test above functions
int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest_distance_pair(P,0, n-1));
    return 0;
}
