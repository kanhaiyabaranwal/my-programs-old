#include<iostream>
using namespace std;

void reorder(int arr[],int index[],int n)
{
	int i=0;
	while(i<n)
	{
		int temp=arr[i];
		int tempi=index[i];
		arr[i]=arr[index[i]];
		index[i]=i;
		arr[temp[i]=temp;
		index[tempi]=tempi;
}



// Driver program
int main()
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    reorder(arr, index, n);
 
    cout << "Reordered array is: \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 
    cout << "\nModified Index array is: \n";
    for (int i=0; i<n; i++)
        cout << index[i] << " ";
    return 0;
}
