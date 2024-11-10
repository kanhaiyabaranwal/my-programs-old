#include<iostream>
#include<string>

//custom hashmap with id as emp id%range and value as employee name

using namespace std;
#define R 5

struct employee_node{
	int emp_id;
	string employee_name;
	employee_node* next;
	employee_node(int id,string name,employee_node* n=NULL):emp_id(id),employee_name(name),next(n){
	}
};

class EmpHashMap{
	employee_node** eHead;
	static const int range=5;
	string find(int id);
	public:
		bool insert(int id,string employee_name);
		bool remove(int id);
		bool update(int id,string name);
		string operator[](int id);
		void navigate();
		EmpHashMap(){
			eHead=new employee_node*[range];
			for(int i=0;i<range;i++)
				eHead[i]=NULL;
		}
		~EmpHashMap(){
			delete []eHead;
		}
};

string EmpHashMap::find(int id)
{
	int key=id%range;
	employee_node* cur_emp=eHead[key];
	while(cur_emp)
	{
		if(cur_emp->emp_id==id)
			return cur_emp->employee_name;
		cur_emp=cur_emp->next;
	}
	return "";
}
bool EmpHashMap::insert(int id,string employee_name)
{
	if(find(id) != "")		//employee already present.
	{
		cout<<"employee id already present, can't insert id->"<<id<<" with name "<<employee_name<<endl;
		return false;
	}
		
	int key=id%range;
	employee_node *emp=new employee_node(id,employee_name);
	if(!emp)
		return NULL;
	if(!eHead[key])
		eHead[key]=emp;
	else	//hash
	{
		employee_node* emp_temp=eHead[key];
		while(emp_temp->next)
			emp_temp=emp_temp->next;
		emp_temp->next=emp;
		
	}
	return true;
}

bool EmpHashMap::remove(int id)
{
	if(find(id) == "")
	{
		cout<<"employee not present, nothing will be deleted";
		return false;
	}
	int key=id%range;
	employee_node* emp_temp=eHead[key];
	employee_node* prev=NULL;
	while(emp_temp)
	{
		if(emp_temp->emp_id==id)
		{
			if(prev)
			{
				prev->next=emp_temp->next;
			}
			else
				eHead[key]=emp_temp->next;
			delete emp_temp;
			return true;
		}
		prev = emp_temp;
		emp_temp=emp_temp->next;
	}
	cout<<"Employee with given id not found"<<endl;
	return false;
}

bool EmpHashMap::update(int id, string name)
{

	
}

void EmpHashMap::navigate()
{
	for(int key=0;key<range;key++)
	{
		if(eHead[key])
		{
			cout<<"employees with key "<<key<<" present are ";
			employee_node* emp_temp=eHead[key];
			while(emp_temp)
			{
				cout<<emp_temp->employee_name<<",";
				emp_temp=emp_temp->next;
			}
			cout<<endl;
		}
		
		
	}
}

string EmpHashMap::operator[](int id){
	string name=find(id);
	return name;
}


int main()
{
	EmpHashMap ehash_map;
	ehash_map.insert(1,"kan");
	ehash_map.insert(2,"abhi");
	ehash_map.insert(3,"ramesh");
	ehash_map.insert(4,"satish");
	ehash_map.insert(8,"abhi");
	ehash_map.insert(6,"abhishek");
	ehash_map.insert(2,"vinay");
	ehash_map.insert(12,"pramod");
	ehash_map.navigate();
	
	int id;
	cin>>id;
	string name=ehash_map[id];
	cout<<"emp_id: "<<id<<" name="<<name<<endl;
	return 0;
}


