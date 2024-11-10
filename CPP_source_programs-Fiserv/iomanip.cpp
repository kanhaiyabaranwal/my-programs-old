#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	ofstream out("output.txt");
	out<<setw(30)<<"kanhaiya";
	cout<<setw(30)<<"kanhaiya";
	//cout<<"kan";
	return 0;
}
