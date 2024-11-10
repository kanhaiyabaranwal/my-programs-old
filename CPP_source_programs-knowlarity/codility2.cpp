#include<iostream>
using namespace std;

	int solution(int arr[] ,int n){
		if(n < 3) return 0;	
		int start = 0;	
		
		int total_count = 0;	//answer we want
		
		while(start < n-2){
			int end = start+1;	
			int diff = arr[end] - arr[start];	
			
			//extend until arithmetic condition fails
			while(end < n-1 && arr[end+1] - arr[end] == diff){
				end++;
			}
			
			int len = end - start + 1;	
			
			//valid slice must have at least 3 number
			if(len >= 3){
				total_count += ((len-2)*(len-1)/2);
			}
			
			//Arithmetic progression will not overlap, so move start to end
			start = end;
		}
		
		//consider overflow
		return (total_count > 1000000000) ? -1 : total_count;

	}
int main()
{
	int arr[]={-1,1,3,3,3,2,1,0};
	cout<<"Number of AP slices=";	
	cout<<solution(arr,8);
	cout<<endl;
}
