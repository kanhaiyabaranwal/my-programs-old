# include <stdio.h>
# include <limits.h>
 
// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }
 
/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k,int *EggDrop )
{
    // If there are no floors, then no trials needed. OR if there is
    // one floor, one trial needed.
    if (k == 1 || k == 0)
        return k;
 
    // We need k trials for one egg and k floors
    if (n == 1)
        return k;
        
        if(EggDrop[k]<k) 
		return EggDrop[k];
	
 
    int min = INT_MAX, x, res;
 
    // Consider all droppings from 1st floor to kth floor and
    // return the minimum of these values plus 1.
    for (x = 1; x <= k; x++)
    {
        res = max(eggDrop(n-1, x-1,EggDrop), eggDrop(n, k-x,EggDrop));
        if (res < min)
            min = res;
    }
 	EggDrop[k]=min+1;
    return min + 1;
}
 
/* Driver program to test to pront printDups*/
int main()
{
    int n = 2, k = 10;
    int *EggDrop=new int[k];
    	for(int i=0;i<=k;i++)
		EggDrop[i]=i;

    printf ("\nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k,EggDrop));
    return 0;
}
