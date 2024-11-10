/*
http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
http://www.geeksforgeeks.org/puzzle-set-35-2-eggs-and-100-floors/
*/

//Egg Dropping Dynamic Programming



#include<iostream>
#include<algorithm>
using namespace std;


//TODO Recurssive


/*
Dynamic Programming
*/
int EggDroppingDP(int eggCount, int floorCount)
{
	if(eggCount <= 0) return -1;
	if(eggCount == 1) return floorCount;

	int** table = new int*[eggCount];
	for(int i=0; i<eggCount; i++)
	{
		table[i] = new int[floorCount+1];
	}

	for(int floor=1; floor<=floorCount; floor++)
		table[0][floor] = floor;  // table[0] means when we have only one egg

	for(int egg=0; egg<eggCount; egg++)
		table[egg][0] = 0;  // this is when we have zeor floors

	for(int egg=2; egg <= eggCount; egg++)
	{
		for(int floor=1; floor <= floorCount; floor++)
		{
			int minSteps = INT_MAX;
			//lets find out which floor if we try has min cost
			for(int kthFloor = 1; kthFloor<= floor; kthFloor++)
			{
				//      Result of Nth egg stored at arrar[N-1] so we doing egg-2      //
				//.....................Egg Break.................Egg doesnot Break....//
				int steps = 1 + max( table[egg-2][kthFloor-1], table[egg-1][floor-kthFloor]);
				minSteps = min(minSteps, steps);
			}
			table[egg-1][floor]= minSteps;
		}
	}
	int res = table[eggCount-1][floorCount];
	for(int i=0; i<eggCount; i++)
		delete[] table[i];
	delete[] table;
	return res;

}

int main_46_T_X_EggDropping()
{
	int eggCount = 2, floorCount = 36;
	int res = EggDroppingDP(eggCount, floorCount);
	printf ("\nMinimum number of trials in worst case with %d eggs and "
		"%d floors is %d \n", eggCount, floorCount, res);
	return 0;
}

