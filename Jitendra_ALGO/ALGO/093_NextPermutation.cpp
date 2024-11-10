

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
namespace NS93
{
	void nextPermutation(int* A, int n) {

		//int n = A.size();
		if (n <= 1) return;
		if (n == 2)
		{
			std::swap(A[0], A[1]);
			return;
		}
		bool waveFound = false;
		int i = n - 1;
		while (i > 0)
		{
			if (A[i] > A[i - 1])
			{
				waveFound = true;
				break;
			}
			i--;
		}
		if (!waveFound)
		{
			int i = 0; int j = n - 1;
			while (i < j)
			{
				std::swap(A[i], A[j]);
				i++; j--;
			}
			return;
		}
		int  j = i; i--;
		int k = j + 1;
		while (k < n)
		{
			if (A[i] < A[k] && A[j] > A[k])
				j = k;
			k++;
		}
		std::swap(A[i], A[j]);
		//vector<int>::iterator it = A.begin() + (i + 1);
		//std::sort(it, A.end());
		std::sort((A + i + 1), (A + n));
	}

	void test()
	{
		int arr[] = { 444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52 };
		int n = sizeof(arr) / sizeof(arr[0]);
		nextPermutation(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

}

int main_93()
{
	NS93::test();
	return 0;
}