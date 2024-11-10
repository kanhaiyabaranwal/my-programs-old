#include <iostream>
#include<stack>
using namespace std;
void
replace(int arr[], int len) {
        stack<int> stk;
    
    for(int i=0;i<len;i++)
    {
        while(!stk.empty() && arr[i]>arr[stk.top()])
        {
            arr[stk.top()]=arr[i];
            stk.pop();
        }
        stk.push(i);
     }
     for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
     cout<<endl;
               


}
int main() {
	// your code goes here
	int arr[]={12, 15, 37, 6, 23, 10, 2, 78};
	replace(arr,8);
	
	return 0;
}
