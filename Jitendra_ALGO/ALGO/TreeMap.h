#include <iostream>
#include <list>

#include "ExceptionMsg.h"


/*
 This class return insert/delete and find max in logN time
*/

template<typename T>
class TreeMap
{
private:
	std::list<T> _list;
public:
	//TODO:-  currently it return N time we neeed to modify it
	void insert(const T& data){
		_list.insert(_list.begin(),data);
	}
	//TODO:-  currently it return N time we neeed to modify it
	void remove(const T& data){
		_list.remove(data);
		/*
		for( std::list<T>::iterator it = _list.begin(); it != _list.end() ; it++)
		{
			if(*it == data)
			{
				_list.erase(it);
				break;
			}
		}
		*/
	}
	bool exists(const T& data){
		bool exists=false;
		for( std::list<T>::iterator it = _list.begin(); it != _list.end() && !exists ; it++)
		{
			if( data == *it)
				exists = true;
		}
		return exists;
	}
	//TODO:-  currently it return N time we neeed to modify it
	const T& max(){
		if(_list.empty())
			throw(ExpectionMsg("Empty"));

		std::list<T>::iterator it = _list.begin();
		T& max = *it;
		for( ; it != _list.end() ; it++)
		{
			if( max < *it)
				max = *it;
		}
		return max;
	}

};
