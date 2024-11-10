#include<iostream>

using namespace std;

class TrieWorld;
struct trie{
	char c;
	trie *child;
	trie *neighbor;
	bool is_word;
	public:
	friend TrieWorld;
	trie(char inputChar):c(inputChar),child(NULL),neighbor(NULL) {}
};
class TrieWorld{
	trie root;	//root character is the first character of first word;
	public:
		TrieWorld(char word[]){
			if(root==NULL)
			{
				root(word[0]);
				insertWord( word+1);
			}
			else
				insertWord( word);
		}
			
		int insertWord(char word[]);
		int findWord(char word[]);
};

int TrieWorld::findWord(char word[])
{
	int i=0;
	trie *temp=root;
	while(true)
	{
		if(temp->c == word[i])          //process child if char matched
		{
			if(word[i+1]=='\n')
			{
				if(is_word==true)
					cout<<"Word found\n";
				else
				{
					cout<<"Word not found\n"
					return 0;
				}
				return 0;
			}
			if(temp->child)		//pattern found until now and child present, go to child
			{
				temp=temp->child;
				continue;
			}
		}		
		else if(temp->neighbor)		//search thru neighbors
		{
			temp1=temp->neighbor;
			while(temp1)
			{
				if(temp1->c==word[i])	//char match found
				{
					temp=temp1;
					int flag=1;
					break;
				}
				else
					temp=temp1;
					temp1=temp1->neighbor;
			}
		}
		if(flag==1)	//neigbhor found, good proceed next
		{
			cout<<"pattern found until "<<word[i]<<endl;
			continue;
		}
		else
		{
			cout<<"Pattern not found\n";
			return 0;
		}
	}
	return 0;

}
int TrieWorld::insertWord(char word[])
{
	int i=0;
	trie *temp=root;
	bool flag=0;
	while(temp)
	{
		if(temp->c == word[i])		//process child if char matched
		{
			if(word[i+1]=='\n')
			{
				if(is_word=true)
					cout<<"Word already present\n";
				else
				{
					is_word=true;
					cout<<"Word Created\n";
				}
				return 0;
			}
			if(temp->child)		//pattern found until now and child present, go to child
			{
				temp=temp->child;
				continue;
			}
		}
		else if(temp->neighbor)		//search thru neighbors
		{
			temp1=temp->neighbor;
			while(temp1)
			{
				if(temp1->c==word[i])	//char match found
				{
					temp=temp1;
					int flag=1;
					break;
				}
				else
					temp=temp1;
					temp1=temp1->neighbor;
			}
		}
		if(flag==1)	//neigbhor found, good proceed next
		{
			cout<<"pattern found until "<<word[i]<<endl;
			continue;
		}
		if(flag==0)	//neighbor does not exist, char not found, create a neighbor
		{
			trie newtrie(word[i]);
			if(temp->child==NULL)	//if child does not exist, create one
				temp->child=newtrie;
			else			//create a neighbor
				temp->neighbor=newtrie;
			temp=newtrie;
		}
		i++;
	}
	return 0;

}
		
int main()
{
	trie tr1('r');
	cout<<"trie char is "<<tr1.c<<endl;
	TrieWorld trieworld("ram");
	trieworld.insertWord("is");
	trieworld.insertWord("good");
	trieworld.insertWord("boy");
	return 0;

}

