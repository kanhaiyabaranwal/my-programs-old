/*
https://www.youtube.com/watch?v=WxpIHvsu1RI
http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
*/


#include<iostream>
#include <algorithm>
using namespace std;

struct GameState
{
	int firstPlayer;
	int secondPlayer;
	GameState(int f, int s) : firstPlayer(f), secondPlayer(s){}
	GameState(): firstPlayer(0), secondPlayer(0) {}
	GameState& operator=(const GameState& other)
	{
		if ( this != &other)
		{
			firstPlayer = other.firstPlayer;
			secondPlayer = other.secondPlayer;
		}
		return *this;
	}
};


int optimalStrategyOfGame(int* arr, int n)
{
	GameState** table = new GameState*[n];
	for(int i=0; i<n; i++)
	{
		table[i] = new GameState[n];
		table[i][i] = GameState(arr[i],0); // here length = 1
	}
	for(int length=2; length <= n; length++)
	{
		for(int i=0; i+length <= n; i++)
		{
			int j = i+length -1;

			GameState option1( arr[i]+table[i+1][j].secondPlayer, table[i+1][j].firstPlayer);
			GameState option2( arr[j]+table[i][j-1].secondPlayer, table[i][j-1].firstPlayer);

			table[i][j] = option1.firstPlayer > option2.firstPlayer ? option1 : option2;
		}
	}
	int result = table[0][n-1].firstPlayer;
	for(int i=0; i< n; i++) delete[] table[i];
	delete[] table;
	return result;
}

int optimalStrategyOfGame_sol2(int* arr, int n)
{
	int** table = new int*[n];
	for (int i = 0; i < n; i++)
		table[i] = new int[n];

	for (int length = 1; length <= n; length++)
	{
		for (int i = 0; i + length <= n; i++)
		{
			int j = i + length - 1;

			int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
			int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
			int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

			table[i][j] = std::max(arr[i] + std::min(x, y), arr[j] + std::min(y, z));
		}
	}
	int result = table[0][n - 1];
	//cleanup
	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete[] table;
	return result;
}


int main_43_T_5_OptimalStrategyForGame()
//int main()
{
	int arr1[] = {8, 15, 3, 7};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int result = optimalStrategyOfGame(arr1, n);
	cout << result << endl;
	result = optimalStrategyOfGame_sol2(arr1, n);
	cout << result << endl;

	int arr2[] = {2, 2, 2, 2};
	n = sizeof(arr2)/sizeof(arr2[0]);
	result = optimalStrategyOfGame(arr2, n);
	cout << result << endl;
	result = optimalStrategyOfGame_sol2(arr2, n);
	cout << result << endl;

	int arr3[] = {20, 30, 2, 2, 2, 10};
	n = sizeof(arr3)/sizeof(arr3[0]);
	result = optimalStrategyOfGame(arr3, n);
	cout << result << endl;
	result = optimalStrategyOfGame_sol2(arr3, n);
	cout << result << endl;

	return 0;
}