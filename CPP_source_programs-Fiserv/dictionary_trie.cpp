#include<iostream>
#include<cstring>
#include<vector>
#incelude<algorithm>
#include<iterator>
using namespace std;

#define NUM_OF_CHARS 26
#define VAL 97

struct trie{
	bool IsWord;
	trie *next[NUM_OF_CHARS];
	string meaning;
	trie(bool is_word=NULL):IsWord(is_word) {
		for(int i=0;i<NUM_OF_CHARS;i++)
			next[i]=NULL;
		
	}
};

void Insert(char word[],int index,trie* dict)
{
	int word_len=strlen(word);
	int i=0;
	if(dict->next[word[index]-VAL]==NULL)	//if character does not exist, then create trie, otherwise move forward to next character
		dict->next[word[index]-VAL]=new trie;
	if(word_len==index+1)
		dict->next[word[index]-VAL]->IsWord=true;
	else
		Insert(word,index+1,dict->next[word[index]-VAL]);
	return;
}
void display_words(trie* dict,vector<char>& svec)
{
	if(dict->IsWord)				//show all words
	{
		copy(svec.begin(),svec.end(),ostream_iterator<char> (cout,""));				
		cout<<endl;
	}
	for(int i=0;i<NUM_OF_CHARS;i++)
	{
		if(dict->next[i])
		{
			//there may by more words with this word as prefix.
			svec.push_back(char(i+VAL));
			display_words(dict->next[i],svec);
			svec.pop_back();
		}
	}
}

int main()
{
	char words[][10]={"a","an","ant","angry","and","april","apron","ass","bat","battle","battery"};
	//char words[][10]={"a","an"};	//,"ant","angry","and","april","apron","ass","bat","battle","battery"};
	int sz=sizeof(words)/sizeof(words[0]);
	cout<<"number of words="<<sz<<endl;
	trie* dict=new trie;
	for(int i=0;i<sz;i++)
		Insert(words[i],0,dict);
	vector<char> svec;
	display_words(dict,svec);
	return 0;
}
