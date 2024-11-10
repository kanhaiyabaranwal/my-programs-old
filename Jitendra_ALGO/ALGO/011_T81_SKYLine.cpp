/*
https://www.youtube.com/watch?v=GSBLe8cKu0s
http://www.geeksforgeeks.org/divide-and-conquer-set-7-the-skyline-problem/
Skyline Problem
Divide and Conquer | Set 7 (The Skyline Problem)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "TreeMap.h"
using namespace std;

struct pos {
	int x;
	int y;
	bool start;
	pos(int _x,int _y,bool _start) : x(_x),y(_y),start(_start){}

};
struct building{
	int x;
	int y;
	int h;
	building(int _x,int _h,int _y) : x(_x),y(_y),h(_h){}

};

bool myCompare(pos p1, pos p2)
{
	if( p1.x == p2.x)
	{
		if(p1.start && p2.start)
			return (p1.y > p2.y);
		else if ( !p1.start && !p2.start)
			return ( p1.y < p2.y);
		else
			return (!p1.start);
	}
	else
		return (p1.x < p2.x);
}

void print(const vector<pos>& positions)
{
	for(vector<pos>::const_iterator it = positions.begin(); it != positions.end();it++)
	{
		cout << "(" << it->x << "," << it->y << (it->start ? ",s) " : ",e) ") ;
	}
	cout << endl;
}

vector<pos> skyline(const vector<building>& buildings)
{
	vector <pos> result;
	vector<pos> positions;
	for(vector<building>::const_iterator it = buildings.begin(); it != buildings.end();it++)
	{
		building b = *it;
		pos start(b.x,b.h,true);
		pos end(b.y,b.h,false);
		positions.push_back(start);
		positions.push_back(end);
	}
	print(positions);
	std::sort(positions.begin(),positions.end(), myCompare);
	print(positions);

	TreeMap<int> treemap;
	treemap.insert(0);
	int max =0;
	for(vector<pos>::iterator it = positions.begin();
		it != positions.end(); it++)
	{
		pos current = *it;
		if(current.start)
		{
			treemap.insert(current.y);
			if( max != treemap.max())
			{
				max = treemap.max();
				result.push_back(pos(current.x,max,current.start));
			}
		}
		else
		{
			treemap.remove(current.y);
			if( max != treemap.max())
			{
				max = treemap.max();
				result.push_back(pos(current.x,max,current.start));
			}
		}

	}
	return result;
}

int main_11()
{
	vector<building> buildings;
//	buildings.push_back(building(1,3,3));
	buildings.push_back(building(1,11,5));   //1
	buildings.push_back(building(2,6,7));    //2
	buildings.push_back(building(3,13,9));   //3
	buildings.push_back(building(12,7,16));  //4
	buildings.push_back(building(14,3,25));  //5
	buildings.push_back(building(19,18,22)); //6
	buildings.push_back(building(23,13,29)); //7
	buildings.push_back(building(24,4,28));  //8

	vector<pos> res = skyline(buildings);
	cout << "result: \n" ;
	print(res);
	return 0;
}

