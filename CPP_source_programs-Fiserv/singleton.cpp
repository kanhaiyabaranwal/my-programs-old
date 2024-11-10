#include<iostream>
using namespace std;

class Queen{
	Queen(){
	cout<<"Create one instance only\n";
	}
	Queen(const Queen&){
	}
	static Queen * qInst;
	public:
	static Queen* getQueen(){
			if(qInst){
				cout<<"Instance already available";
				return qInst;
			}
			else
			{
				qInst=new Queen();
				return qInst;
			}
		
	}
};

 Queen * Queen::qInst=NULL;

int main(){
	cout<<"Caling first time\n";
	//Queen q;
	Queen::getQueen();
	cout<<"Caling Second time\n";
	Queen::getQueen();
	return 0;
}
