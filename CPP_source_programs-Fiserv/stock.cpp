#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

struct stk{
	int time;
	string stock;
	int nbr;
	double price;
	int file_index;
};

int main()
{
	ifstream in[3];
	in[0].open("1.txt");
	in[1].open("2.txt");
	in[2].open("3.txt");
	string line;
	string time,stock,nbr,price;
	int count=0;
	int nbr_of_files=3;
	int i=0;
	map<int,stk> smap;
	while(i<nbr_of_files)
	{
		in[i++]>>line;
		stringstream ss;
		ss<<line;
		ss.getline(time,256,',');
		ss.getline(stock,256,',');
		ss.getline(nbr,256,',');
		ss.getline(price,256);
		count+=1;
		cout<<"Line["<<count<<"]-> "<<time<<","<<stock<<","<<nbr<<","<<price<<endl;
		stringstream temps;
		stk stkd;
		temps<<time;
		temps>>stkd.time;
		stkd.stock=stock;
		temps<<nbr;
		temps>>stkd.nbr;
		temps<<price;
		temps>>stkd.price;
		stkd.file_index=i;
		smap.insert(make_pair(stkd.time,stkd));
	}
	cout<<"showing map contents"<<endl;
	map<int,stk>::const_iterator iter=smap.begin();
	for(int i=0;iter!=smap.end();iter++,i++)
		cout<<iter->first<<","<<smap[i].stock<<","<<smap[i].nbr<<","<<smap[i].price<<endl;
	ofstream out("out.txt");
	cout<<"Now each line from file and sending data to output file"<<endl;
	while(smap.size()>0)
	{	
		out<<smap[0].time<<","<<smap[0].stock<<","<<smap[0].nbr<<","<<smap[0].price<<endl;
		//get next stock data from file.
		if(!(in[smap[0].file_index].eof()))
		{
			in[smap[0].file_index]>>line;
			//(ifstream)(*(smap[0].f))>>line;
			cout<<"Next input line read from file "<< smap[0].file_index<<" is "<<line<<endl;
			stringstream ss;
			ss<<line;
		ss.getline(time,256,',');
		ss.getline(stock,256,',');
		ss.getline(nbr,256,',');
		ss.getline(price,256);
			count+=1;
			cout<<"Line["<<count<<"]-> "<<time<<","<<stock<<","<<nbr<<","<<price<<endl;
			stringstream temps;
			stk stkd;
			temps<<time;
			temps>>stkd.time;
			stkd.stock=stock;
			temps<<nbr;
			temps>>stkd.nbr;
			temps<<price;
			temps>>stkd.price;
			stkd.file_index=smap[0].file_index;	//source file is same
			smap.insert(make_pair(stkd.time,stkd));
		}
		else
			in[smap[0].file_index].close();
			//(*(smap[0].f)).close();
		smap.erase(smap.begin());
	}
	return 0;
}
	
