#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace NS_94
{
	vector<int> getAllPrimesTill(int n)
	{
		bool* boolArr = new bool[n + 1];
		memset(boolArr, true, sizeof(boolArr));
		for (int p = 2; p*p <= n; p++)
		{
			if (boolArr[p] == true)
			{
				for (int i = p * 2; i <= n; i += p)
					boolArr[i] = false;
			}
		}
		vector<int> primes;
		for (int p = 2; p <= n; p++)
		{
			if (boolArr[p])
				primes.push_back(p);
		}
		delete[] boolArr;
		return std::move(primes);
	}
	long long int combination(int n, int p)
	{
		p = std::min(n - p, p);
		vector<int> primes = getAllPrimesTill(n);
		int size = primes.size();
		vector<int> primePow_n;
		vector<int> primePow_p;
		for (int i = 0; i < size; i++)
		{
			primePow_n.push_back(0);
			primePow_p.push_back(0);
		}

		int count = p; int number = n;
		while (count > 0)
		{
			int current = number; count--; number--;
			for (int i = 0; i < size; i++)
			{
				int x = primes[i];
				while (current > 1 && current % x == 0)
				{
					primePow_n[i]++;
					current /= x;
				}
			}
		}
		count = p; number = p;
		while (count > 1)
		{
			int current = number; count--; number--;
			for (int i = 0; i < size; i++)
			{
				int x = primes[i];
				while (current > 1 && current % x == 0)
				{
					primePow_p[i]++;
					current /= x;
				}
			}
		}
		//subtract powers of primes
		for (int i = 0; i < size; i++)
		{
			primePow_n[i] = primePow_n[i] - primePow_p[i];
			if (primePow_n[i] < 0) return -1; // this should never occur
		}

		//now calculate the result
		long long int res = 1;
		for (int i = 0; i < size; i++)
		{
			long long int x = static_cast<long long int>(primes[i]);
			count = primePow_n[i];
			while (count > 0)
			{
				res *= x; count--;
			}
		}

		return res;
	}

	void test()
	{
		long long int res = combination(10000,2);
		cout << res;
	}
}
int main_94()
{
	NS_94::test();
	return 0;
}