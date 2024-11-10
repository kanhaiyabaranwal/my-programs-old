#include <iostream>
#include <queue>
using namespace std;
int find_kth_smallest(int *arr,int sz, int k)
{
	//max heap of size k will have kth highest element on top
    priority_queue<int, std::vector<int>, std::less<int> > pq;
    
    //push an element smaller than max to heap, ow pop max and push new element. kth max is still maintained.
    for(int i=0;i<sz;i++)
	{
		if(pq.size()<k)
			pq.push(arr[i]);
		else if(arr[i]<pq.top())
		{
			pq.pop();
			pq.push(arr[i]);	
		}	
		
	}
	return pq.top();
	cout<<"Showing priority queue\n";
	for(int i=0;i<k;i++)
	{
		cout<<pq.top()<<", ";
		pq.pop();
	}
	
}


int main() {
	//code
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
	    int num_test_cases;
	    cin>>num_test_cases;
	    int *arr=new int[num_test_cases];
	    for(int j=0;j<num_test_cases;j++)
	        cin>>arr[j];
	    int k;
	    cin>>k;
	    int min=find_kth_smallest(arr,num_test_cases,k);
	    cout<<min<<endl;
	    delete arr;
	}
	return 0;
}
