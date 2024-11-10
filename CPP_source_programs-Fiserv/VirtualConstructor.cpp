#include<iostream>
#include<string>
using namespace std;

class Game{
	Game *g;
	protected:
		Game(){
		g=0;			//letter constructor
		cout<<"I am letter constructor\n";
		}
		public:
			Game(const string &s);	//envelope constructor
			virtual void play() { 
				g->play();
			}
			virtual void create(){
				g->create();
			}
			virtual ~Game();
};
class Football:public Game{
	public:
	Football(){
		cout<<"I am Football\n";
	}
	void play(){
		cout<<"I am playing football\n";
	}
	void create(){
		cout<<"I shall creat Football game\n";
	}
	~Football(){
		cout<<"Football is no more\n";
	}
};
class Cricket:public Game{
	public:
	Cricket(){
		cout<<"I am Cricket\n";
	}
	void play(){
		cout<<"I am playing cricket\n";
	}
	void create(){
		cout<<"I shall creat cricket game\n";
	}
	~Cricket(){
		cout<<"Cricket is no more\n";
	}
};
//Virtual constructor for Shape should be defined after all derived classes are defined
Game::Game(const string &str){
	cout<<"I am envelope constructor\n";
	if(str=="Football")
		g=new Football();
	else if(str=="Cricket")
		g=new Cricket();
	else
		cout<<"Bad game option\n";
	g->create();		//will call correct polymorphic function since g is fully constructed
}
Game::~Game(){
	if(g)
		delete g;
}

int main(){
	Game g1("Football");
	Game g2("Cricket");
	return 0;
}


