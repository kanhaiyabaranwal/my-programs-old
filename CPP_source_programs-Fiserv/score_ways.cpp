#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int score_ways(vector<int>& score_points,int target_score)
{
	int combinations[target_score+1];
	for(int i=1;i<=target_score;i++)
		combinations[i]=0;
	combinations[0]=1;
	int i=0;
	int score=score_points[i];
	for(;i<score_points.size();i++,score=score_points[i])
	{
		cout<<"i="<<i<<",score_points="<<score_points[i]<<",score="<<score<<endl;
		for(int j=score;j<=target_score;j++)
		{
			combinations[j]=combinations[j]+combinations[j-score];
		}
	}
	return combinations[target_score];
}

int main()
{
	vector<int> score_points(5);
	score_points[0]=2;
	score_points[1]=3;
	score_points[2]=4;
	score_points[3]=5;
	score_points[4]=10;

	int target_score=25;
	cout<<"Available score points:";
	copy(score_points.begin(),score_points.end(),ostream_iterator<int>(cout,","));
	int num_of_ways=score_ways(score_points,target_score);
	cout<<endl<<"Ways to score "<<target_score<<": "<<num_of_ways<<endl;
	return 0;
}
	
