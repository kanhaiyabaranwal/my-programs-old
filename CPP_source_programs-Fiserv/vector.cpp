#include<iostream>

using namespace std;
//implementation of vector of integers
#define CHUNK 3

class vector{
	int *vec;		
	int inflate(int increment);
	int curIndex;
	int vectorSize;
	public:
		vector():vec(NULL),curIndex(0),vectorSize(0){
		}
		int push_back(int i);
		const int & operator [](int i){
			return vec[i];
		}
		/*const int & operator=(vector &vec,int i)
		{
			vec[i]=vec[i];
			return *this;
			
		}*/
		int display(){
			cout<<"Nbr of elements in array="<<curIndex<<endl;
			cout<<"Int Arr elements are\t";
			for(int i=0;i<curIndex;i++)
				cout<<vec[i]<<'\t';
			cout<<"\nAll elements displayed\n";
			return 0;	
		}
		int assign(int i, int j){
			vec[i]=j;
			return 0;
		}
};

int vector::push_back(int num){
	if(curIndex>=vectorSize)
		inflate(CHUNK);
	//if(curIndex==0)
	//	vec[curIndex]=num;
	//else
	curIndex++;
		vec[curIndex-1]=num;
	return 0;
}
int vector::inflate(int increment){
	int oldSize=vectorSize;
	int newSize=oldSize+increment;
	int *newvec=new int[newSize];
	//copy old vector into new space
	//int sz=sizeof(vec)/sizeof(int);
	for(int i=0;i<oldSize;i++)
		//newvec->assign(i,vec[i]);
		newvec[i]=vec[i];
	vectorSize=newSize;
	curIndex=oldSize;
	delete []vec;
	vec=newvec;
	return 0;
}

int main()
{
	vector intArr;
	intArr.push_back(10);
	intArr.push_back(15);
	intArr.push_back(115);
	intArr.push_back(145);
	intArr.push_back(165);
	cout<<intArr.display();
	return 0;
}
