#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int validCombo(int input1,int input2[],int input3)
{
	//Write code here
        int totalAttack=0;
        //input1 is also size of input2 and size of vector attack
        int totAttack=0;
        //multiplication of attack strength will keep track if they are distinct or not
        std::vector<int> mulattack;
        int distinctattack=0;
        for(int i=0;i<input1;i++)
                for(int j=0;j<input1;j++)
                        for(int k=0;k<input1;k++)
                                for(int l=0;l<input1;l++)
                                {
                                        totAttack=input2[i]+input2[j]+input2[k]+input2[l];
                                        if(totAttack==input3)
                                        {
                                                if(distinctattack==0)   //add first possible attack
                                                {
                                                        distinctattack++;
                                                        mulattack.push_back(input2[i]*input2[j]*input2[k]*input2[l]);
                                                }
                                                else
                                                {
                                                        int m;
                                                        for(m=0;m<distinctattack;m++)
                                                                if(mulattack[m]==input2[i]*input2[j]*input2[k]*input2[l])
                                                                        break;
                                                        if(m==distinctattack)   //attack is distinct, add
                                                        {
                                                                distinctattack++;
                                                                mulattack.push_back(input2[i]*input2[j]*input2[k]*input2[l]);
                                                        }
                                                }
                                        }
                                }
        return distinctattack;
}

int main()
{

	int nbrOfAttack=1;
	int strength[]={1};
	int strengthrequired=4;
	/*int nbrOfAttack;
	int strengthrequired;

	cout<<"Enter max nbr of attacks"<<endl;
	cin>>nbrOfAttack;
	int *strength=new int[nbrOfAttack];
	strength[0]=0;
	
	for(int i=1;i<=nbrOfAttack;i++)
	{
		cout<<"Enter strength of attack# "<<i<<"\t";
		cin>>strength[i];
	}
	cout<<"Enter Strength required\t";
	cin>>strengthrequired;
	//A person can choose any number of attacks and strength of all attacks available each time.
	//P1 chooses 2 attacks of strength 2,3. Total Strength of P1=2+3=5
	//P2 chooses 3 attacks of strength 2,3,3. Total Strength of P2=2+3+3=8
	//P3 chooses 1 attacks of strength 2. Total Strength of P3=2
	//P4 chooses 3 attacks of strength 1,2,2. Total Strength of P4=1+2+2=5
	//Total strenth=P1+p2+p3+p4=5+8+2+5=20
	//Possible, so output is 1.
	*/
	int out=validCombo(nbrOfAttack,strength,strengthrequired);
	if(out)
		cout<<"Foe can be killed in "<<out<<"ways\n";
	else
		cout<<"Foe can't be killed\n";
	return 0;
}

