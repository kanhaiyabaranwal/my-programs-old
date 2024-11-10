#include<iostream>
#include<map>
#include<string>
using namespace std;

class Employee{
	
	string name;
	double salary; 
	int rating;
	int mgrid;
	static int emp_seq_id;
	int emp_id;
	
	public:
		Employee(string nam,double sal,int rat,int mgr):name(nam),salary(sal),rating(rat),mgrid(mgr) {
			emp_id=++emp_seq_id;
		}
		
		int GetEmpID();
		int GetEmpName();
		int GetEmpSalary();
		int GetManagerID();
		int GetRating();
		
		int SetEmpID(int empid);
		int SetEmpName(string name);
		int SetEmpSalary(double salary);
		int SetManagerID(int mgr_id);
		int SetRating(int rating);
		int Promote();			//creates an istance of Manager with all details and delete Employee
		virtual ~Employee() {
		}
};
int Employee::emp_seq_id=0;
class Manager:public Employee{
	int nbrOfSubordinates;
	Employee **subordinates;
	int max;
	public:
		//Manager():max(25),nbrOfSubordinates(0) {
		//	subordinates=new Employee*[max];
		//}
		Manager(string nam,double sal,int rat,int mgr):max(25),nbrOfSubordinates(0) {
			//SetEmpID(int empid);
			SetEmpName(nam);
			SetEmpSalary(sal);
			SetManagerID(mgr);
			SetRating(rating);
			subordinates=new Employee*[max];
		}
		int AddSubordinate(Employee *emp);
		int AddSubordinate();
		int NbrOfSubordinates();
		Empoyee** GetSubordinates();
};
int Manager::AddSubordinate(Employee *emp){
	//employee pool exhausted, allocate another pool
	if(nbrOfSubordinates+1>=max)
	{
		//delete []subordinates;
		max=nbrOfSubordinates+25;
		Employee **oldsubordinates=subordinates;
		subordinates=new Employee[max];
		for(int i=0;i<nbrOfSubordinates;i++)
		{
			subordinates[i]=oldsubordinates[i];
			delete oldsubordinates[i];
		}
	}
	subordinates[nbrOfSubordinates++]=emp;
}
class Company;

class CEO:public Manager{
		CEO();
	public:
		friend class Company;
};
typedef map<string,Employee*> pmap;		
class Company{
	static Employee* ceo;
	pmap people;		//map of empid and Employee for faster lookup, delete and add
	public:
		int AddPeople();
		int DeleteAssociate(int empId);
		void ShowHierarchy();			//This is BFS traversal from level 0 to level 2
		int PromoteEmployee();
		static Employee* GetCEO(){
			if(!ceo)
				ceo=new CEO();
			return ceo;
		}
};
int Company::AddPeople(){
	string name;
	double salary;
	int rating;
	string mgr_name;
	ifstream in("employee.txt");
	while(in)
	{
		in.getline(name,',');
		in.getline(salary,',');
		in.getline(rating,',');
		in.getline(mgr_name);
		cout<<"name="<<name<<",salary="<<salary<<",rating="<<rating<<",manager name="<<mgr_name<<endl;
	
		pmap::const_iterator iter=people.find(mgr_name);
		if(iter==people.end())
		{
			cout<<"Manager "<<mgr_name<<" not found in company directory"<<endl;
			return -1;
		}
		Employee *mgr=(iter->second);
		int mgr_id=mgr->emp_id;
		Employee *emp=new Employee(name,salary,rating,mgr_id);
		//add to organization employee directory
		people.insert(make_pair(name,emp));
		//add to manager's subordinate list
		mgr.AddSubordinate(emp);
}

int main(){
	
}
