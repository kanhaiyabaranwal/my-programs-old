#include<iostream>
#include<vector>
#include<set>
#define V 9
using namespace std;

void dijkstra(int graph[][V], int source)
{
	set<int> vset;
	int dist[V];
	int minD=INT_MAX;
	int cur_node,next_node;
	
	vset.insert(source);
	dist[0]=0;
	cout<<"First node is "<<0<<endl;
	for(int i=1;i<V;i++)
	{
		if ( graph[0][i]==0 )
		{
			dist[i]=INT_MAX;
			continue;
		}
		dist[i]=graph[0][i];
		if(dist[i]<minD)
		{
			minD=dist[i];
			next_node=i;
		}
	}
	cout<<"second node is "<<next_node<<", and minD is "<<minD<<endl;
	vset.insert(next_node);
	int in;
	while(vset.size()<V)
	{
		minD=INT_MAX;
		cur_node=next_node;
		set<int>::const_iterator iter= vset.begin();
		while(iter!=vset.end())
		{
			cur_node=*iter;
			int minD=INT_MAX;
			for(int i=0;i<V;i++)
			{
				if(dist[i] > dist[cur_node]+graph[cur_node][i])
				{
					if(i!= cur_node && graph[cur_node][i] && vset.find(i) == vset.end() && graph[cur_node][i] + dist[cur_node] < minD)
					{
						next_node=i;
						minD=graph[cur_node][i] + dist[cur_node];
					}
					dist[i]=dist[cur_node]+graph[cur_node][i];
					
				}

			}
			iter++;
		}
		
		//minD+=cur_minD;		
		cout<<"cur node is "<<cur_node<<endl;
		cout<<"next node is "<<next_node<<" and minD is "<<minD<<endl;
		dist[next_node]=dist[cur_node]+minD;
		vset.insert(next_node);
		cin>>in;
	}
	
	cout<<"Min distance matrix"<<endl;
	for(int i=0;i<V;i++)
		cout<<dist[i]<<",";
	cout<<endl;
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
