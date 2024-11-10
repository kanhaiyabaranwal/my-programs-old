/*
https://www.youtube.com/watch?v=9mod_xRB-O0
http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem/

Box Stacking Dynamic Programming

Dynamic Programming | Set 22 (Box Stacking Problem)
You are given a set of n types of rectangular 3-D boxes,
where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers).
You want to create a stack of boxes which is as tall as possible,
but you can only stack a box on top of another box if the dimensions of the 2-D base
of the lower box are each strictly larger than those of the 2-D base of the higher box.

Of course, you can rotate a box so that any side functions as its base.
It is also allowable to use multiple instances of the same type of box.


*/
#include<iostream>
#include<algorithm>
using namespace std;

namespace NS84
{
	struct Box
	{
		int h, w, d;
	};
	bool compare(const Box a, const Box  b)
	{
		return (a.d * a.w ) > (b.d * b.w);
	}
	int getMaxHeight(Box* arr, int n)
	{
		//calculate all permutations
		int size = n * 3;
		Box* all = new Box[size];
		for (int i = 0; i < n; i++)
		{
			all[3 * i + 0] = { arr[i].h, arr[i].w, arr[i].d };
			all[3 * i + 1] = { arr[i].w, arr[i].h, arr[i].d };
			all[3 * i + 2] = { arr[i].d, arr[i].w, arr[i].h };
		}
		//sort it based on w * d
		std::sort(all, all + size, compare); 

		int* dp = new int[size];
		for (int i = 0; i < size; i++)
		{
			dp[i] = all[i].h;
		}
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				//if Box[i] can sit on Box[j]
				if ((all[i].w < all[j].w &&  all[i].d < all[j].d)
					|| (all[i].w < all[j].d &&  all[i].d < all[j].w))
				{
					int newHeight = dp[j] + all[i].h;
					dp[i] = newHeight > dp[i] ? newHeight : dp[i];
				}
			}
		}
		int maxHeight = dp[size - 1];
		delete[] dp;
		delete[] all;
		return maxHeight;
	}
	void test()
	{
		Box arr[] = { { 4, 6, 7 }, { 1, 2, 3 }, { 4, 5, 6 }, { 10, 12, 32 } };
		int n = sizeof(arr) / sizeof(arr[0]);

		int res = getMaxHeight(arr, n);
		cout << "The maximum possible height of stack is : " << res;
	}
}

int main_84()
{
	NS84::test();
	return 0;
}