#include<iostream>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;

void sig_handler(int i){
	signal(SIGINT,sig_handler);
	cout<<"Signal being interrupted\n";
	cout<<"I am alive\n";
}

int main(){
	signal(SIGINT,sig_handler);
	cout<<"Hi, I am doing good\n";
	sleep(5);
	cout<<"Hi, I am doing good again\n";
	sleep(20);
	cout<<"Hi, I am doing good again and again\n";
	return 0;
}
