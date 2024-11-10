#include    <iostream>
using namespace std;

int findSubArray(char arr[],int size)
{
    int starcount = 0;
    int hashcount = 0;
    int s=0,e=-1,max1 = -1;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == '#') hashcount++;
        if(arr[i] == '*') starcount++;
        if(starcount == hashcount)
            max1 = starcount+hashcount , s = 0, e = i;
        else
        {
            int temp = 2 * min ( starcount , hashcount);
            if(temp > max1)
                max1 = temp, s = i -temp + 1,e = i;
        }
    }
    cout<<"start : "<<s<<"\t"<<", end : "<<e<<endl;
    cout<<"subarray : " <<endl;
    for(int i=s;i<=e;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    return max1;
}
/* Driver program to test above functions */
int main()
{
    char arr[] =  {'#', '#', '*', '#', '#', '#', '*','*','#','#','*'};
    int size = sizeof(arr)/sizeof(arr[0]);
  
    int m = findSubArray(arr, size);
    cout<<"count : "<<m<<endl;
    return 0;
}
