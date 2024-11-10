//Dijkstra's algorithm to find shortest path from source vertex to every other vertex.
//using adjacency matrix
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
#define NBR_OF_VERTICES 5

int matrix[NBR_OF_VERTICES][NBR_OF_VERTICES];

//maintain a vector of vertex and shortest distance from source vertex to each of those node.
//vector[i]=distance, where i is node number and distance is minimum distance from source.
//source vertex in our calculation is A, vertex 0.
void shortestPath()
{
	int shortestDistance[NBR_OF_VERTICES];
	int minShortestDistance=0;
	int minShortestNode=0;
	//initialize shortest distance to each edge starting from 0 is -1. For 0->0, distance is 0.
	shortestDistance[0]=0;
	for(int i=1;i<NBR_OF_VERTICES;i++)
		shortestDistance[i]=-1;
	
	//vector of nodes whose shortest distance is found is included
	vector<int> ivec;
	ivec.push_back(0);		//first node is included by default and its distance is 0
	//For each vertex shortest distance vector, find vertex not included in vector
	//and that is reachable from the vector of vertices. find the vertex with minimum distance, include that in vector
	//and include shortest distance of that vector in shortestDistance[] array.
	while(ivec.size()!=NBR_OF_VERTICES)
	{
	for(vector<int>::const_iterator it=ivec.begin();it!=ivec.end();it++)
	  {
		//if(ivec.size()==NBR_OF_VERTICES)
		//	break;		//all nodes explored
		minShortestDistance=0;
		minShortestNode=0;
		int row=*it;
		for(int i=0;i<NBR_OF_VERTICES;i++)
		{
			if(matrix[row][i]==-1 || matrix[row][i]==0 ) 	//no edge or self,skip.
				continue;
			//if shortestDistance for destination vertex is already present
			if(shortestDistance[i]!=-1) 
			{
				//if shortestDistance for current row+current edge is less than shortest Distance for the target vertex, 
				//update shortest Distance Table
				// shortestDistance[row] is always > 0. source-it is a vector element
				if( shortestDistance[row]+matrix[row][i] < shortestDistance[i])
					shortestDistance[i]=shortestDistance[row]+matrix[row][i];
			}
			//if shortestDistance for destination vertex is not present,
			else	//if(shortestDistance[i]==-1)		
			{
				shortestDistance[i]=shortestDistance[row]+matrix[row][i];			//update shortest Distance for cur node
			}
			
			// shortestDistance[row] is always >0 since it is present in vector and vector gets only valid values
			//update with minim
			if(minShortestDistance==0 || minShortestDistance > shortestDistance[row]+matrix[row][i] )
			{
				minShortestDistance = shortestDistance[row]+matrix[row][i];
				minShortestNode = i;
			}
		}
	  }
	  shortestDistance[minShortestNode]=minShortestDistance;
	  ivec.push_back(minShortestNode);
	}
	for(int i=0;i<NBR_OF_VERTICES;i++)
		cout<<"shortest distance from 0 to "<<i<<" is "<<shortestDistance[i]<<endl;
		
}

int main()
{
	
	cout<<"Adjacency Matrix is"<<endl; 
	//cout.setw(2);
	
	for(int row=0;row<NBR_OF_VERTICES;row++)
	{
		for(int col=0;col<NBR_OF_VERTICES;col++)
		{
			if(row==col)
				matrix[row][col]=0;
			else
				matrix[row][col]=-1;
			//cout<<setw(2)<<matrix[row][col]<<" ";
		}
		//cout<<endl;
	}
	//set adjacency matrix path
	matrix[0][1]=4;
	matrix[0][2]=1;
	matrix[1][4]=4;
	matrix[2][1]=2;
	matrix[2][3]=4;
	matrix[3][4]=4;
	
	/*matrix[1][0]=4;
	matrix[2][0]=1;
	matrix[4][1]=4;
	matrix[1][2]=2;
	matrix[3][2]=4;
	matrix[4][3]=4;
	*/
	cout<<"   A  B  C  D  E"<<endl;
	for(int row=0;row<NBR_OF_VERTICES;row++)
	{
		cout<<char(row+'A')<<" ";
		for(int col=0;col<NBR_OF_VERTICES;col++)
			cout<<setw(2)<<matrix[row][col]<<" ";
		cout<<endl;
	}
	shortestPath();
	
}
