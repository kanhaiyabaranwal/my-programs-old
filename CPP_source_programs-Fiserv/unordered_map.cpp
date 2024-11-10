#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>
using namespace std;

class ID{
	int i;
	public:
		ID(int in):i(in){
		}
		int getI() const {
			return i;
		}
		bool operator==(const ID& id) const{
			return id.i==i;
		}
};
typedef string name;

template<typename T>
struct Hash{
	
	int operator()(const T id) const
	{
		return hash<int>()(id.getI());
	}
};

int main()
{
	unordered_map<ID,name,Hash<ID> > umap;
	umap.insert(make_pair(1,"kan"));
	umap.insert(make_pair(2,"jan"));
	unordered_map<ID,name,Hash<ID> >::iterator iter=umap.begin();
	for(const auto& p:umap)
		cout<<"ID="<<p.first.getI()<<" name is"<<p.second<<endl;
	return 0;	
}
