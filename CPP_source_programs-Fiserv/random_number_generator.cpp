#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int uniform_random_a_b(int a, int b) {
	int t = b - a + 1, res;
	srand(time(NULL));
	double resi=rand()%t;
	cout<<"random number is "<<resi+a<<endl;
	/*do {
		res = 0;
		for (int i = 0; (1 << i) < t; ++i) {
			// zero_one_random() is the system -provided random number generator.
			
			res = (res << 1) | zero_one_random();
		}
	} while (res >= t);
	return res + a;
	*/
	return 0;
}

int main()
{
	uniform_random_a_b(5,10);
	return 0;
}
