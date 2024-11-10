#include<stdio.h>
#include<string.h>

int main()
{
	//char    oprm[5][512];  
	//char strng[512]="Error spjobalis:Alias details not found in log file b_alias.log";
	//char strng[32]="name=RWDB";
	char strng[512]="parms=CTRA=N a=smurfx j=smurf ana=sis t=smurf~with~wrong c=J* syxc ";
	char kan[32];
	char kan1[32],kan2[32],kan3[32],kan4[32],kan5[32],kan6[32],kan7[2];
	int k=45;
	printf("k=%05d\n",k);
	
	int num=sscanf(strng,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^\n]", kan1,kan2,kan3,kan4,kan5,kan6,kan7);
	printf("strng=%s and kan1=%s,kan2=%s,kan3=%s,kan4=%s,kan5=%s,kan6=%s,kan7=%s,num=%d\n",strng,kan1,kan2,kan3,kan4,kan5,kan6,kan7,num);
	//int num=sscanf(strng,"%*[^=]=%s",kan1);
	char *pstrng=strng;
	char *pstrng_next,*pstrng_eq;
	char teststr[32]={NULL};
	char testopt[32]={NULL};
	while(pstrng_next=strchr(pstrng,' '))
	{
		memset(teststr,NULL,32);
		memset(testopt,NULL,32);
		strncpy(teststr,pstrng,pstrng_next-pstrng);
		printf("teststr is %s\n",teststr);
		if(!strchr(teststr,'='))
		{
			printf("!!!Error in Alias : Missing equal sign around parameter option %s\n",teststr);
			break;
		}
		pstrng_eq=strchr(teststr,'=');	
		strncpy(testopt,pstrng,pstrng_eq-pstrng);
		if(pstrng_eq-pstrng>1)
			printf("Invalid option >1 char %s\n",testopt);
		if(*pstrng != 'a' && *pstrng != 'c' && *pstrng != 't' && *pstrng != 'j')
			printf("Invalid option,not a,c,t,j %s\n",testopt);
		pstrng=pstrng_next;
		while(*pstrng==' ')
			pstrng++;
	}
	pstrng_next=strchr(pstrng,'\0');
	memset(teststr,NULL,32);
	strncpy(teststr,pstrng,pstrng_next-pstrng);
	printf("teststr=%s\n",teststr);
	if(strlen(teststr)>0 && !strchr(teststr,'='))
		printf("!!!Error in Alias : Missing equal sign around parameter option %s\n",teststr);
	

	//printf("kan1=%s,num=%d\n",kan1,num);

	return 0;
}
