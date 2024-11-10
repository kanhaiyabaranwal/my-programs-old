//Q9.10_CTCI.count ways of boolean expression for given result
#include<iostream>
#include<cstring>
using namespace std;

int f(char *exp,bool result)
{
	int count;
	int len=strlen(exp);
	if(len==1)				//terminating condition
	{ 
		cout<<"inside exp len=1,exp="<<*exp<<endl;
		if((*exp=='1' && result) || (*exp=='0' && !result))
		{
			cout<<"got result"<<endl;
			return 1;
		}
		else
			return 0;
	}
	char *c=exp+1;
	char exp1[len],exp2[len];
	char oper;
	int n=0;
	while(*c)
	{
		cout<<"n="<<n<<endl;
		memset(exp1,NULL,sizeof(exp1));
		memset(exp2,NULL,sizeof(exp2));
		strncpy(exp1,exp,c-exp);
		strncpy(exp2,c+1,strlen(c+1));
		oper=*c;
		if(*c != '|' && *c != '&' && *c != '^')
		{
			cout<<"fatal error,*c="<<*c<<endl;
			return -1;
		}
		cout<<"exp1="<<exp1<<", exp2="<<exp2<<endl;
		if(result==true)
		{
			switch(oper)
			{
				case '|':
					count+=f(exp1,true)*f(exp2,true)
							+f(exp1,true)*f(exp2,false)
							+f(exp1,false)*f(exp2,true);
					break;
				case '&':
					count+=f(exp1,true)*f(exp2,true);
					break;
				case '^':
					count+=f(exp1,true)*f(exp2,false)
							+f(exp1,false)*f(exp2,true);
			}
		}
		else		//when result should be false
		{
			switch(oper)
			{
				case '|':
					count+=f(exp1,false)*f(exp2,false);
					break;
				case '&':
					count+=f(exp1,false)*f(exp2,false)
							+f(exp1,true)*f(exp2,false)
							+f(exp1,false)*f(exp2,true);
					break;
				case '^':
					count+=f(exp1,true)*f(exp2,true)
							+f(exp1,false)*f(exp2,false);
			}
		}
		c+=2;
	}
	return count;
}

int main()
{
	char exp[]="1^0|0|1";
	//char exp[]="0|0|1";
	bool result=true;
	cout<<"count ways of boolean expression "<<exp<<" for given result "<<result<<endl;
	int count=f(exp,result);
	cout<<"Total count of boolean expressions="<<count<<endl;
	return 0;
}
