#include<iostream>

template<class T, int incr=20>
class PStash{
	int quantity;
	int next;
	T** storage;
	void inflate(int increase=incr);
public:
	PStash():quantity(0),sotrage(0),next(0) { }
	~PStash();
	int add(T* element);
	T* operator[](int index) const ;
	T* remove(int index);
	int count() const {return next;}
	
	class iterator;
	friend class iterator;
	class iterator{
		PStash &ps;
		int index;
	public:
		iterator(PStash &pStash): ps(pStash),index(0) {}
		iterator(PStash &pStash, bool):ps(pStash),index(ps.next) {}
		iterator& operator=(const iterator& rv){
			ps=rv.ps;
			index=rv.index;
			return *this;
		}
	};
