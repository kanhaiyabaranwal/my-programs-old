#include <iostream>
#include <unordered_map>
using namespace std;

int findFirstRepeatedIndex(int n, int* nums )
{
    unordered_map<int,int> umap;
    for(int i=0;i<n;i++)
    {
        if(umap.find(nums[i]) == umap.end())
            umap[i]=nums[i];
        else
        {
            cout<<i;
            return i;
        }
    }
    return -1;
}

int main() {
	
	int nbrOfTestCases,nbrOfTestInputs;
	cin>>nbrOfTestCases;
	int i=0;
	while(i<nbrOfTestCases)
	{
	    cin<<nbrOfTestInputs;
	    int *testInputs=new int[nbrOfTestInputs];
	    for(int j=0;j<nbrOfTestInputs;j++)
	    {
	        cin>>testInputs[j];
	    }
	    findFirstRepeatedIndex(nbrOfTestInputs, testInputs);
	    i++;
	    delete testInputs;
	}
	return 0;
}
