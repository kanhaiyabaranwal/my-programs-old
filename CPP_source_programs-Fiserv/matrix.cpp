q#include<iostream>

using namespace std;
#define NUM_OF_ROWS 4
#define NUM_OF_COLUMNS 4
int main()
{
    int i;
    int arr[NUM_OF_ROWS][NUM_OF_COLUMNS]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<"N*M matrix***\n";
    for(i=0;i<NUM_OF_ROWS; i++)
    {
            for(int j=0; j<NUM_OF_COLUMNS; j++)
                    cout<< arr[i][j]<<"\t";
            cout<<endl;
    }
    cout<<"Rotated matrix by 90 degree\n";
    for(i=0;i<NUM_OF_COLUMNS; i++)
    {
            for(int j=1; j<=NUM_OF_ROWS; j++)
            //for(int j=NUM_OF_ROWS-1;j>=0; j--)
                    //cout<< arr[j][i]<<"\t";
                    cout<<arr[NUM_OF_ROWS-j][i]<<"\t";
            cout<<endl;
    }

    cin>>i;
    return 0;
}
