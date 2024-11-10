#include<iostream>
#include<string>
using namespace std;

class FiservEmp;
class Emp{
	string name;
	int emp_id;
	public:
	Emp(string str, int emp):name(str),emp_id(emp)	{}
	bool operator==(const Emp* emp)
	{
		cout<<"Inside operator ==\n";
		return emp_id==emp->emp_id;
	}
	int getEmpID() const
	{
		return emp_id;
	}
	friend std::ostream& operator<< (std::ostream& out, const Emp & e) ;
	friend class FiservEmp;
	virtual ~Emp()	{ }
};
class FiservEmp:public Emp{
	public:
	FiservEmp(string str, int emp):Emp(str,emp) {}
	FiservEmp(const Emp& emp):Emp(emp.name,emp.emp_id) {}	//constructor conversion
	bool operator==(const FiservEmp* femp)
	{
		cout<<"Inside Fiseremp operator==\n";
		return getEmpID()==femp->getEmpID();
	}
};
std::ostream& operator<<(std::ostream& out,const Emp& e)
{
	out<<"employee name="<<e.name<<" and emp_id="<<e.emp_id<<endl;
	return out;
}
int main()
{
	//FiservEmp*  e= new FiservEmp("kanhaiya",32);
	//Emp*  e= new FiservEmp("kanhaiya",32);
	FiservEmp*  e= new FiservEmp("kanhaiya",32);
	FiservEmp e1("John",33);
	cout<<e<<endl;
	int i=(e1==e);
	cout<<"i="<<i<<endl;
	delete e;
	return 0;
}
