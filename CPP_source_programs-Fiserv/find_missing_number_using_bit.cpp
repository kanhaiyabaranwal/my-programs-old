#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void find_missing_number(ifstream *ifs)
{
	int count[1<<8]{0};
	int x;
	while(*ifs>>x)
		++count[x>>8];
	//found the count of numbers with same MSB, now compare if their count is less than 1<<8. If yes, then number with that MSB is missing
	for(int i=0;i<(1<<8);i++)
	{
		if(count[i]<(1<<8))
		{
			//missing number has MSB i. now find all numbers with MSB, mark count as 1 if found
			for(int j=0;j<(1<<8);j++)
				count[j]=0;
			ifs->clear();
			ifs->seekg(0,ios::beg);
			while(*ifs>>x)
			{
				if((x>>8)==i)
					++count[x&0xFF];
			}
			for(int k=0;k<(1<<8);k++)
			{
				if(count[k]==0)
				{
					int num=(i<<8) | k;
					cout<<"Missing number is "<<num<<" and k is "<<k<<endl;
					return;
				}
			}
		}
	}
	
}

int main()
{
	/*ofstream ofs("numbers.txt");
	int i=0;
	while(i<(1<<16))
		ofs<<i++<<endl;
	*/
	ifstream ifs("numbers.txt");
	find_missing_number(&ifs);
	
	return 0;
}
