#include <vector>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;
using std::vector;

int main()
{

vector<int> deck;
vector<int> nums;
default_random_engine eng(time(0));
uniform_int_distribution<int> dis(0, 51);

int pos1;
int pos2;
int num1;
int num2;
int i;
int n;
int m;

for (i = 0; i < 52; i++)
{
    nums.push_back(i);

}

for(int j = 0; j < 52; j++)
{
    cout << nums.at(i) << "\n";
}


for(n = 0; n < 50; n++)
{
    pos1 = dis(eng);
    pos2 = dis(eng);

    cout << pos1 << "\n" << pos2 << "\n";

    num1 = deck.at(pos1);
    num2 = deck.at(pos2);

}

}

