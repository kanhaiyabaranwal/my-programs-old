#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;
#define R 5
#define C 4

struct cell{
	int r;
	int c;
	int val;
	cell(int r,int c,int v):r(r),c(c),val(v) {}
};

int shortest_path_rectangular_grid(int rec[][C],int m,int n)
{
	int s=0;
	queue<cell*> q;
	cell* first=new cell(0,0,0);
	q.push(first);
	cell* dummy=new cell(-1,-1,0);
	q.push(dummy);		//dummy  cell to mark level
	cell* front;
	int r=0,c=0;
	int visited[R][C];
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			visited[i][j]=0;
	visited[0][0]=1;
	while(q.size()>1)
	{
		front=q.front();
		if(front->r==-1)
		{
			q.push(dummy);	//next level
			cout<<"Change of level"<<endl;
			s++;
		}
		else
		{
			r=front->r,c=front->c;
			if(r==R-1 && c==C-1)
			{
				cout<<"Optimum distance found is "<<s<<endl;
				cout<<"It came from cell["<<r<<"]["<<c<<"]"<<endl;
				return s;
			}
		
				
			if(r+1<R && rec[r+1][c]!=-1 && !visited[r+1][c])
			{
				cell* newcell=new cell(r+1,c,10*r+c);	//save where it came from
				cout<<"Visiting from cell["<<r<<"]["<<c<<"] to cell["<<r+1<<"]["<<c<<endl;
				q.push(newcell);
				visited[r+1][c]=1;
			}
			if(c+1<C && rec[r][c+1]!=-1 && !visited[r][c+1])
			{
				cell* newcell=new cell(r,c+1,10*r+c);	//save where it came from
				cout<<"Visiting from cell["<<r<<"]["<<c<<"] to cell["<<r<<"]["<<c+1<<endl;
				visited[r][c+1]=1;
				q.push(newcell);
			}
			if(r+1<R && c+1<C && rec[r+1][c+1]!=-1 && !visited[r+1][c+1])
			{
				cell* newcell=new cell(r+1,c+1,10*r+c);	//save where it came from
				cout<<"Visiting from cell["<<r<<"]["<<c<<"] to cell["<<r+1<<"]["<<c+1<<endl;
				visited[r+1][c+1]=1;
				q.push(newcell);
			}
			delete front;
		}
		q.pop();
	}
	//reached here means no path to [R][C] exists
	cout<<"No path exists to reach to cell["<<R<<"]["<<C<<"]"<<endl;
	return -1;	
}
int main()
{
	int rec[R][C];
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			rec[i][j]=0;
	rec[1][1]=-1;
	rec[2][1]=-1;
	rec[2][3]=-1;
	rec[3][2]=-1;
	rec[4][2]=-1;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cout<<setw(4)<<rec[i][j];
		cout<<endl;
	}
	int s=shortest_path_rectangular_grid(rec,R,C);
	cout<<"Shortest path is of length:"<<s<<endl;
	return 0;
}
