#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool swap_word(char *str,char* newword)		//swaps word at specified position
{
	//if(strlen(str)<strlen(newword))
	//	return false;
	int i=0;
	while(i<strlen(newword))
	{
		str[i]=newword[i];	
		i++;
	}
	return true;
}
bool word_found(char *str,char* word)
{
	int i=0;
	while(word[i] && word[i]==str[i])
		i++;
	if(word[i]=='\0')
		return true;
	else 
		return false;
}
			
bool replace_word(char *str,char* oldword,char* newword,char *&newstr)
{
	int len=strlen(str);
	int old_len=strlen(oldword);
	int new_len=strlen(newword);

	//find count of occurences of old word.
	char *ptr=str;
	int count=0;
	vector<char*> cvec;
	while(*ptr)
	{
		if(word_found(ptr,oldword))
			count++;
		cvec.push_back(ptr);
		ptr++;
	}
	if(!count)
	{
		cout<<"No word replacement needs to be done"<<endl;
		return false;
	}
	int newlen=len+count*(new_len-old_len)+1;
	//newstr=(char*)realloc(str,newlen);
	newstr=(char*)malloc(sizeof(char)*newlen);
	if(!newstr)
	{
		cout<<"Failed to allocate new size!"<<endl;
		return false;
	}
	int diff=new_len-old_len;
	if(old_len>=new_len)	//guaranteed in-place replacement
	{
		//newptr is new string, oldptr is old string
		char* newptr=newstr, *oldptr=str;
		while(*oldptr)
		{
			if(word_found(oldptr,oldword))
			{
				if(swap_word(newptr,newword)==false)
				{
					cout<<"Failed to swap word"<<endl;
					return false;
				}
				newptr+=new_len;
				oldptr+=old_len;
			}
			else
			{
				*newptr++=*oldptr++;
			}
		}
		*newptr='\0';
	}
	else	//newword is larger than old oldword
	{
		char* oldptr=str+len;
		int temp_len=len;
		char* newptr=newstr+newlen;
		//*newptr--='\0';			//null terminated
		while(temp_len>=0)
		{
			if(word_found(oldptr,oldword))
			{
				newptr-=diff;
				if(swap_word(newptr,newword)==false)
				{
					cout<<"Failed to swap word"<<endl;
					return false;
				}
				//newptr--,oldptr--;
			}
			else
			{
				*newptr=*oldptr;
				newptr--,oldptr--;
			}
			temp_len--;
		}
	

	}
	free(str);
	return true;
}


int main()
{
	char *str=(char*)malloc(17*sizeof(char));
	strcpy(str,"Gandhi was Gandhi");
	char oldword[]="Gandhi";
	//char newword[]="Prasad";
	char newword[]="Mahatma";
	cout<<"Word before replacement: "<<str<<endl;
	char* newstr=NULL;
	if(replace_word(str,oldword,newword,newstr))
	{
		cout<<"Word after replacement: "<<newstr<<endl;
		cout<<"Word after replacement: "<<*(newstr+1)<<endl;
	}
	else
		cout<<"Word could not be replaced"<<endl;
		
	return 0;
}


