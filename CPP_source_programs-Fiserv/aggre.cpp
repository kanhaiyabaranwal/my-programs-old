#include<iostream.h>

class Employee
{
  public:

    Employee(char *name){
      cout<<"Employee::ctor\n";
      myName_p = new char(sizeof(strlen(name)));
      myName_p = name;
    }
    
    char* disp(){return(myName_p);};

    ~Employee()
    {
      cout<<"Employee:dtor\n\n";
      delete (myName_p);
    }

  private:
    char *myName_p;
};

class Company
{
  public:
    Company(char * compName, Employee* emp){
      cout<<"Company::ctor\n";
      name = new char(sizeof(strlen(compName))); 
      name = compName;
      myEmp_p = emp;
    };

    ~Company()
    {
      cout<<"Company:dtor\n\n";
      myEmp_p = NULL;
    };
    
  private:
    char *name;
    Employee *myEmp_p;
};


int main()
{
  cout<<"\nExample of Aggregation Relationship \n";
  cout<<"-----------------------------------------\n\n";
    
  {
    cout<<"Here, an Employee-Keerti works for Company-MS \n";
    Employee emp("Keerti");
  
    {
      Company comp("MS", &emp);
    } // here Company object will be deleted, whereas Employee object is still there

    cout<<"At this point Company gets deleted...\n";
    cout<<"\nBut Employee-"<<emp.disp();
    cout<<" is still there\n";
    
  } //here Employee object will be deleted

  return(0);
}

