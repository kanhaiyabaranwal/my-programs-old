#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
	deque<string> sdeq(3,"kan");
	sdeq.push_back("prasad");
	sdeq.push_front("Mr.");
	vector<string> svec(3,"delhi");
	copy(svec.begin(),svec.end(), sdeq.begin());
	copy(sdeq.begin(),sdeq.end(), ostream_iterator<string> (cout," "));
	return 0;	
}
