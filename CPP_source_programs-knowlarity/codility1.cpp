#include<iostream>
using namespace std;


int solution(int X, int Y, int A[], int N) {
    int result = -1;
    int nX = 0;
    int nY = 0;
    int i;
    for (i = 0; i < N; i++) {
        if (A[i] == X)
            nX += 1;
        else if (A[i] == Y)
            nY += 1;
        if (nX && nX == nY)
            result = i;
    }
    return result;
}

int main()
{
	//int x=8;
	//int y=50;
	int x=7;
	int y=42;
	int a[]={7,42,7,7,42};
	int res=solution(x,y,a,5);
	cout<<"res="<<res<<endl;
	return 0;
}
