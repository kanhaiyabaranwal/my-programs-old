/*
https://www.youtube.com/watch?v=cETfFsSTGJI
http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
http://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
*/
#include<iostream>
#include<algorithm>
using namespace std;

namespace NS_58
{
	int minJumps(int* arr, int n)
	{
		if(n <= 2) return n-1; //base cases
		if(arr[0] == 0) return -1;

		int maxReach = arr[0];
		int steps = arr[0];
		cout << arr[0] << "  ";
		int jump = 1;
		for(int i=1; i<n-2; i++)
		{
			maxReach = max(maxReach, i+arr[i]);
			steps--;

			if(steps ==0)
			{
				cout << arr[i] << "  ";
				jump++;

				if(i>maxReach)
					return -1;

				steps = maxReach -i;
			}
		}
		return jump;
	}

	int minJumps_improved(int* arr, int n)
	{
		if(n<=1) return 0;
		if(arr[0] == 0) return -1;

		int jumps =1;
		int current = arr[0];
		int backup = arr[0];
		for(int i=1; i<n; i++)
		{
			if(current == 0 && backup == 0) return -1;
			if(current == 0)
			{
				jumps++;
				current = backup;
			}
			current --; backup--;
			backup = (backup < arr[i]) ? arr[i] : backup;
		}
		return jumps;
	}
}


int main_58()
{
	int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int size = sizeof(arr)/sizeof(int); 
	int res = NS_58::minJumps(arr,size);
	int res_improved = NS_58::minJumps_improved(arr,size);
	cout << "\nMinimum number of jumps to reach end is :  " << res;
	return 0;
}