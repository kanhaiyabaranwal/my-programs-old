#include<iostream>
#include<vector>
using namespace std;

int solution(vector<int>& A){
	int n=A.size();
	if(n < 3) return 0;	
	int start = 0;	
	
	int total_count = 0;	
	
	while(start < n-2){
		int end = start+1;	
		int diff = A[end] - A[start];	
		
		while((end < n-1) && (A[end+1] - A[end] == diff)){
			end++;
		}
		
		int len = end - start + 1;	
		
		if(len >= 3){
			total_count += ((len-2)*(len-1)/2);
		}
		
		start = end;
	}
	if(total_count > 1000000000)
		return -1;
	return total_count;

}
int main()
{
vector<int> A{-1,1,3,3,3,2,1,0};
cout<<"Number of AP slices=";	
cout<<solution(A);
cout<<endl;
}
