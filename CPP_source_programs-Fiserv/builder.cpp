#include<iostream>
using namespace std;

class LoanBuilder;
class Loan{
	char *type;
	double balance;
	char dueDate[11];
	bool closed;
	char currency[3];
	float intRate;
public:
	virtual void setType(char* inputtype=0){
		type=new char[sizeof(inputtype)];
		strcpy(type, inputtype);
	}
	virtual void setBalance(double inputBalance=0){
		balance=inputBalance;
	}
	virtual void setDueDate(char* inputDueDate=0)
	{
		strcpy(dueDate, inputDueDate);
	}
 	virtual void setClosed(bool inputClosed=0)
	{
		closed=inputClosed;
	}
	virtual void setCurrency( char* inputCurrency=0)
	{
		strcpy(currency, inputCurrency);
	}
 	virtual void setIntRate( float inputIntRate=0)
	{
		intRate= inputIntRate;
	}
public:
	char* getType(){
		return type;
	}
	double getBalance(){
		return balance;
	}
	char* getDueDate(){
		return dueDate;
	}
	
	friend class LoanBuilder;
	Loan() { 
		cout<<"Loan construction is not part of creation\n";
	}
	
};
//Abstract Loan Builder
class LoanBuilder{
protected:
	Loan *loan;
public:
	void createLoan(){
		loan= new Loan();
	}
	Loan* getLoan() const
	{
		return loan;
	}
	virtual void setType(char* inputtype=0)=0;
	virtual void setBalance(double inputBalance=0)=0;
	virtual void setDueDate(char* inputDueDate=0)=0;
 	virtual void setClosed(bool inputClosed=0)=0;
	virtual void setCurrency( char* inputCurrency=0)=0;
 	virtual void setIntRate( float inputIntRate=0)=0;
	
};
class RegLoanBuilder: public LoanBuilder{
public:
	void setType(char* inputtype=0){
		cout<<"Building regular loan"<<endl;
		loan->setType(inputtype);
	}
	virtual void setBalance(double inputBalance=0){
		loan->setBalance(inputBalance);
	}
	virtual void setDueDate(char* inputDueDate=0)
	{
		loan->setDueDate(inputDueDate);
	}
 	virtual void setClosed(bool inputClosed=0)
	{
		loan->setClosed(inputClosed);
	}
	virtual void setCurrency( char* inputCurrency=0)
	{
		loan->setCurrency(inputCurrency);
	}
 	virtual void setIntRate( float inputIntRate=0)
	{
		loan->setIntRate(inputIntRate);
	}
};
class StudentLoanBuilder: public LoanBuilder{
public:
	void createLoan(){
		loan= new Loan();
	}
	Loan* getLoan()
	{
		return loan;
	}
	void setType(char* inputtype=0){
		cout<<"Building Student loan"<<endl;
		loan->setType(inputtype);
	}
	virtual void setBalance(double inputBalance=0){
		loan->setBalance(inputBalance);
	}
	virtual void setDueDate(char* inputDueDate=0)
	{
		loan->setDueDate(inputDueDate);
	}
 	virtual void setClosed(bool inputClosed=0)
	{
		loan->setClosed(inputClosed);
	}
	virtual void setCurrency( char* inputCurrency=0)
	{
		loan->setCurrency(inputCurrency);
	}
 	virtual void setIntRate( float inputIntRate=0)
	{
		loan->setIntRate(inputIntRate);
	}
};

//creator of loan builder
class Admin{
		
};
int main()
{
	Admin admin;
	
	LoanBuilder *lb= new RegLoanBuilder();
	LoanBuilder *lb1= new StudentLoanBuilder();
	lb->createLoan();
	lb->setType("Regular Loan");
	lb->setBalance(4.5);
	lb->setDueDate("04-05-2011");
	lb->setClosed(0);
	lb->setCurrency("INR");
	lb->setIntRate(12.0);
	Loan *loan=lb->getLoan();
	cout<<"Loan type is "<<loan->getType()<<endl;
	cout<<"loan due date is"<<loan->getDueDate()<<endl;
	cout<<"loan balance is"<<loan->getBalance()<<endl;

	lb1->createLoan();
	lb1->setType("Student Loan");
	lb1->setBalance(104.5);
	lb1->setDueDate("01-05-2011");
	lb1->setClosed(0);
	lb1->setCurrency("INR");
	lb1->setIntRate(2.0);
	loan=lb1->getLoan();
	cout<<"Loan type is "<<loan->getType()<<endl;
	cout<<"loan due date is"<<loan->getDueDate()<<endl;
	cout<<"loan balance is"<<loan->getBalance()<<endl;
	return 0;
}	
 
/*class LoanBuilder{
	Loan *loan ;
	public:
	void constructLoan(){		//only creation, no construction
		loan = new Loan();	
	}
	//now construction. methods only visible to the builder
	void BuildType(char *type)
	{
		loan->setType(type);
	}
	void BuildBalance(double *balance)
	{
		loan->setBalance(balance);
*/
