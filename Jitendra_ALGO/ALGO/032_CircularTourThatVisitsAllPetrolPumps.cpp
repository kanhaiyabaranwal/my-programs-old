/*
http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
*/
#include<iostream>
using namespace std;

struct PetrolPump{
	int petrol;
	int distance;
	//PetrolPump(int p, int d) : petrol(p), distance(d){}
};

inline int nextCirularStation(int i, int size)
{
	return  (i +1) % size;
}

inline int petrolBalance( const PetrolPump& p)
{
	return p.petrol - p.distance;
}

int getStartPoint(PetrolPump* arr, int size)
{
	if(size <= 0) return -1;
	if(size == 1) return 0;
	int finish = 0; int current = 1;
	int current_petrol  = petrolBalance(arr[0]);
	while(true)
	{
		//Continue till we have petrol
		while(current_petrol >= 0 && finish != current)
		{
			current_petrol += petrolBalance(arr[current]);
			current = nextCirularStation(current, size);
		}
		//So we have covered all stations
		if(current_petrol >= 0 && finish == current)
			return finish;
		//Advance the finish/start point till we get petrol
		while(current_petrol < 0)
		{
			current_petrol -= petrolBalance(arr[finish]);
			finish = nextCirularStation(finish, size);
			//If finish point is again zero then we dont have solution
			if(finish == 0)
				return -1;
		}
		//Check while advancing the start/finish point if we reached to 
		// current point, then increment the current point else top while
		// will fail
		if(current == finish)  
		{
			current_petrol += petrolBalance(arr[current]);
			current = nextCirularStation(current, size);
		}
	}
	return -1;
}


int main_32_CircularTourThatVisitsAllPetrolPumps()
//int main()
{
	//struct PetrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
	struct PetrolPump arr[] = {{1, 3}, {2, 1}};
	int n = sizeof(arr)/sizeof(arr[0]);

	int start = getStartPoint(arr, n);

	(start == -1)? printf("No solution"): printf("Start = %d", start);

	return 0;
}