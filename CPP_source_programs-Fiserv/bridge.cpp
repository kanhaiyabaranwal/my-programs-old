#include<iostream>
using namespace std;

//Bridge pattern; definition is different from implementation
//Here education is different from school. So separate class is defined for how education is done. It can be trhough school or open schooling

class school {
public:
	virtual char * getSchoolName() =0;
	virtual char * getSchoolPlace() =0;
	virtual ~school() {}
};

class RegSchool :public school{
	char schoolName[25];
	char schoolPlace[10];
public:
	RegSchool(char *name,char *place){
		strcpy(schoolName,name);
		strcpy(schoolPlace,place);
	}
	char * getSchoolName() { return schoolName; }
	char * getSchoolPlace() { return schoolPlace; }
};
class OpenSchool :public school{
	char schoolName[25];
public:
	OpenSchool(char *name) {
		strcpy(schoolName,name);
	}
	char * getSchoolName() { return schoolName; }
	char * getSchoolPlace() { cout<<"It's an open school\n"; return "Delhi"; }
};

//definition is Educate, implementation is schooling
class Educate {
	int classNbr;
	school *sch;
public:
	Educate(int cl, school *s) : classNbr(cl),sch(s)	{}
	int getClass() {return classNbr;}
	char * getSchoolName() { return sch->getSchoolName(); }
};

int main()
{
	school *s1 = new RegSchool("St. Xaviers","Ranchi");
	Educate ed1(4,s1);
	cout<<"School name in regular education is "<<ed1.getSchoolName()<<endl;
	school *s2 = new OpenSchool("National Open School");
	Educate ed2(4,s2);
	cout<<"School name in open education is "<<ed2.getSchoolName()<<endl;
	
	cout <<"Testing 123"<<endl;
	return 0;
}
