#include<iostream>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
#define NBR_OF_BOXES 20

struct Box{
	int width;
	int depth;
	int height;
	Box(int w,int d,int h):width(w),depth(d),height(h) { }
	bool canBeAbove(Box* b){
		if(b==NULL)
			return true;
		else if(b->width>width && b->depth>depth && b->height>height)
			return true;
		else
			return false;
	}
};

stack<Box*> createStack(vector<Box*> &bvec,Box* bottom=NULL)
{
	vector<Box*>::const_iterator iter=bvec.begin();
	stack<Box*> maxstack;
	int max_height=0;
	
	for(int i=0;iter!=bvec.end();iter++,i++)
	{
		//if(bottom==NULL)
		//	createStack(bvec,*iter);
		if((*iter)->canBeAbove(bottom))		//check if current box can be placed over bottom box
		{
			stack<Box*> newstack=createStack(bvec,*iter);
			if(newstack.size()>maxstack.size())
			{
				maxstack=newstack;
				max_height=newstack.size();
			}
		}
	}
	if(bottom)
		maxstack.push(bottom);
	//if(maxstack.size()==0)				//must put bottom if stack is empty
	//	maxstack.push(bottom);
	
	return maxstack;
			
	
	
}

int main()
{
	srand(time(NULL));
	cout<<"Creating largest stack of boxes in decreasing order"<<endl;
	vector<Box*> bvec;
	Box *b;
	for(int i=0;i<NBR_OF_BOXES;i++)
	{
		int w=rand()%9+1;
		int d=rand()%9+1;
		int h=rand()%9+1;
		b=new Box(w,d,h);
		bvec.push_back(b);
	}
	vector<Box*>::const_iterator iter=bvec.begin();
	for(int i=0;iter!=bvec.end();iter++,i++)
		cout<<"Box["<<i<<"]="<<(*iter)->width<<","<<(*iter)->depth<<","<<(*iter)->height<<endl;
	stack<Box*> sb=createStack(bvec);
	cout<<"Showing largest stack of boxes now"<<endl;
	int count=0;
	while(sb.size()>0)
	{
		b=sb.top();
		cout<<"Box["<<count++<<"]="<<b->width<<","<<b->depth<<","<<b->height<<endl;
		sb.pop();
	}
	return 0;		
}
