#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<iterator>
#include<set>
#include<sstream>
using namespace std;

class Int{
	int i;
	public:
		Int(int j=0):i(j){
		}
		int getI() const{
			return i;
		}
		/*bool operator<(const Int& J) const{
			return i<J.i;
		}*/
};

class Less{
	public:
	bool operator()(const Int& i,const Int& j){
		return i.getI()<j.getI();
	}
};

class upper{
	public:
	char operator()(char c) {
		return c+1;
	}
};

int square(int c) {
	return c*c;
}

/*class Replace{
	public:
		Replace(){
		}
	bool operator()(string &s){
		return s=="neha" ? true : false;
	}
};*/

bool Replace(string & s){
	return s=="neha" ? true : false;
	//return ch=='n' ? true : false;
}

int main()
{
	int arr[]={1,34,3,65,76,8};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int sum=accumulate(arr,arr+sz,0);
	cout<<"sum is "<<sum<<endl;
	sort(arr,arr+sz);
	cout<<"Sorted array is ";
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl<<"sqauring elements"<<endl;
	//for_each(arr,arr+sz,square);
	transform(arr,arr+sz,arr+sz,square);
	copy(arr,arr+sz,ostream_iterator<int>(cout," "));
	
	vector<string> svec;
	svec.push_back("kanhaiya");
	svec.push_back(" ");
	svec.push_back("prasad");
	svec.push_back(" ");
	svec.push_back("Baranwal");
	string all=accumulate(svec.begin(),svec.end(),string(""));
	cout<<"All string is "<<all<<endl;
	
	//set
	set<Int,Less > iset;
	iset.insert(4);
	iset.insert(5);
	set<Int>::iterator siter=iset.begin();
	cout<<"First element in set is "<<siter->getI()<<endl;
	
	//string
	string str="kanhaiya";
	cout<<endl<<"string is ";
	//transform(str.begin(),str.end(),str.begin(),upper);
	copy(str.begin(),str.end(),ostream_iterator<char> (cout," "));
	
	//use of repace copy if
	svec.erase(svec.begin(),svec.end());
	vector<string> svec1(100);
	string s="neha is a girl. neha is my wife. neha is pregnant. neha is from samastipur. Her childhood name is neha priyadarshini.";
	stringstream ss(s);
	string stemp;
	while(ss>>stemp)
		svec.push_back(stemp);
	cout<<"Old string is:"<<s<<endl;
	
	//string snew;
	replace_copy_if(svec.begin(),svec.end(),svec1.begin(),Replace,"sneha");
	cout<<"New string is:";
	copy(svec1.begin(),svec1.end(),ostream_iterator<string> (cout," "));
	cout<<endl;
	
	return 0; 
	
}
