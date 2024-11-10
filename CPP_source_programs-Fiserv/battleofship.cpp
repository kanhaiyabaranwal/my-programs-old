//Game of Battle of ships

#include<iostream>
using namespace std;

#define LIVE 0
#define DEAD 1
#define HIT 1

class Point{
	public:
		Point(int x1=0,int y1=0):x(x1),y(y1),hit(HIT)
		{
		}
		int x;
		int y;
		int hit;
	
};
class Ship{
	Point *points;
	int power;
	int state;
	int x1,y1,x2,y2;
		void Assign(int a1,int b1,int a2,int b2){
			int num;
			if(x1<x2)
				num=x2-x1+1;
			else
				num=y2-y1+1;
			points=new Point[num];
			for(int i=0;i<num;i++)
			{
				if(x1<x2)			//horizontal
				{
					int y=y1;
					points[i].x=x1+i;
					points[i].y=y1;
				}
				else			//vertical
				{
					int x=x1;
					points[i].x=x1;
					points[i].y=y1+i;
				}
			}
			
			
		}
		public:
		Ship() {
		}
		~Ship(){
			delete [] points;
		}
		void CreateShip(){
			//take x,y and call private contructor
			int a1,b1,a2,b2;
			cout<<"ship's Initial position x,y (Ex input is 1 2 ) ";
			cin>>a1>>b1;
			cout<<endl<<"ship's final position(Ex input is 1 3) ";
			cin>>a2>>b2;
			x1=a1,y1=b1,x2=a2,y2=b2;
			Assign(a1,b1,a2,b2);	
		}
	
		int PointOnShip(Point p)
		{
			if(x1==x2 && x1==p.x)	//vertical
			{
				
				if(p.y>=y1 && p.y<=y2)	//hit
				{
					int i=p.y-y1;
					points[i].hit--;
					if(points[i].hit<=0)
						return 1;
				}
			}
			else if(y1==y2 && p.y==y1)					//horizontal
			{
				if(p.x>=x1 && p.x<=x2)	//hit
				{
					int i=p.x-x1;
					points[i].hit--;
					if(points[i].hit<=0)
						return 1;
				}
			}
			return 0;
			
		}
		int IsShipAlive(){
			int num;
			if(x1<x2)
				num=x2-x1+1;
			else
				num=y2-y1+1;
			for(int i=0;i<num;i++)
			{
				if(points[i].hit==1)
					return 1;
				;				//if hit is zero, look other points
			}
			return 0;
		}
	
};
class Player{
	static int id_seq;
	int id;
	int power;
	public:
		Player(int pow=0):id(id_seq++),power(pow){
		}
		
};
int Player::id_seq=0;
class Board{
	int N;
	int s;
	//Point *cell;
	Ship *ship;
	public:
		Board(int num,int num_ships):N(num),s(num_ships){
			//cell=new Point[N*N];
			ship=new Ship[s];
			for(int i=0;i<s;i++)
			{
				cout<<"Enter Dimensions for ship "<<i+1<<" ";
				ship[i].CreateShip();
			}
			
		}
		~Board(){
			delete [] ship;
		}
		int CheckPointOnShip(int x1,int y1)
		{
			Point p(x1,y1);
			int ret;
			for(int i=0;i<s;i++)
			{
				ret=ship[i].PointOnShip(p);
				if(ret)
				{
					cout<<"It's a hit"<<endl;
					return 1;
				}
				
			}
			cout<<"It's a miss"<<endl;	
			return 0;
		}
			int CheckAllShips()
			{
				for(int i=0;i<s;i++)
				{
					if(!ship[i].IsShipAlive())
					{
						return 1;
					}
				}
				return 0;
			}
};
class Battleship{
	Board *b1,*b2;
	Player p1,p2;	
	public:
		Battleship(int num_of_boards,int num_of_ships){
			cout<<"Creating board 1"<<endl;
			b1=new Board(num_of_boards,num_of_ships);
			cout<<"Creating board 2"<<endl;
			b2=new Board(num_of_boards,num_of_ships);
		}
		~Battleship(){
			delete b1;
			delete b2;
		}
		int play(){
			int x1,y1;
			while(true)
			{
			
			cout<<"Player 1 guess a block : "<<endl;
			cin>>x1>>y1;
			int ret=b2->CheckPointOnShip(x1,y1);
			if(ret)
			{
						int all=b2->CheckAllShips();
						if(all)
						{
							cout<<"Player 1 wins the game! Have Fun!"<<endl;
							return 1;
						}
			}
			cout<<"Player 2 guess a block : "<<endl;
			cin>>x1>>y1;
			ret=b1->CheckPointOnShip(x1,y1);
			if(ret)
			{
						int all=b1->CheckAllShips();
						if(all)
						{
							cout<<"Player 2 wins the game! Have fun!"<<endl;
							return 1;
						}
			}
		}
		return 0;		//never reaches here
	}
};
int main()
{
	int N,s;
	cout<<"Game Of Battleship: "<<endl
		<<"Input: "<<endl
		<<"Two boards of square size."<<endl
		<<"Each board contains equal no. of ships."<<endl
		<<"Ships can be either horizontal or vertical"<<endl
		<<"Dimensions of ships is decided based on initial and final coordinates x,y."<<endl<<endl
		
		<<"Rule of Game: "<<endl
		<<"Each player gets a chance to guess a position in second player's board."<<endl
		<<"If his guess is correct, it's a hit otherwise a miss"<<endl
		<<"If all ships are killed, the player wins!"<<endl<<endl;
	cout<<"Game Begins"<<endl;
		
	cout<<"What is Board Size(ex-for 4*4, enter 4) ";
	cin>>N;
	cout<<"Enter nbr of ships on each board(ex-1.) ";
	cin>>s;
	int x,y;
	Battleship battle(N,s);
	cout<<endl<<"Game Begins"<<endl;	
	battle.play();
	return 0;
}


