#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (52)
// Converts key current character into index
// use only 'a' through 'z' and lower case
//upper case not handled
#define CAPITAL_CHAR_TO_INDEX(c) ((int)c - (int)'A')
#define SMALL_CHAR_TO_INDEX(c) ((int)c - (int)'a'+26)
 
struct trie_node
{
    int exact_match_id;
    int prefix_match_id;
    //int case;	//1-upper case, 2-lower case, 3-both
    trie_node *children[ALPHABET_SIZE];
};
 
class trie
{
    	trie_node *root;
    	trie_node* getNode(void);
	public:
	trie();
	void insert(char key[],int id,bool type);	//type is for exact or prefix match;type=0-exact,1-prefix
	int search(char key[],bool type);
	
};
 
// Returns new trie node (initialized to NULLs)
trie_node* trie::getNode(void)
{
    trie_node *pNode = NULL;
 
    pNode = (trie_node *)malloc(sizeof(trie_node));
 
    if( pNode )
    {
        int i;
 
        pNode->exact_match_id = 0;
        pNode->prefix_match_id = 0;
	//pNode->case=-1;
 
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
 
    return pNode;
}
 
// Initializes trie (root is dummy node)
trie::trie()
{
    root = getNode();
    root->exact_match_id = 0;
    root->prefix_match_id = 0;
}
 
// If not present, inserts key into trie
void trie::insert(char key[],int id,bool type)	//type is for exact or prefix match;type=0-exact,1-prefix
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pCrawl = root;
 
    for( level = 0; level < length; level++ )
    {
		
	if(key[level]>='A' && key[level]<='Z')
	        index = CAPITAL_CHAR_TO_INDEX(key[level]);
	if(key[level]>='a' && key[level]<='a')
	        index = SMALL_CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
	    
        }
 
        pCrawl = pCrawl->children[index];
    }

	if(type==0)
		pCrawl->exact_match_id=id;
	else if(type==1)
		pCrawl->prefix_match_id=id;
}
 
// Returns non zero, if key presents in trie
int trie::search(char key[],bool type)
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pCrawl = root;
    int id=0; 
	cout<<"searching for "<<key<<endl;
    for( level = 0; level < length; level++ )
    {
	if(key[level]>='A' && key[level]<='Z')
	        index = CAPITAL_CHAR_TO_INDEX(key[level]);
	if(key[level]>='a' && key[level]<='a')
	        index = SMALL_CHAR_TO_INDEX(key[level]);
        //index = CHAR_TO_INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            break;
        }
	if(type==1 && pCrawl->children[index]->prefix_match_id)
	{
		id=pCrawl->children[index]->prefix_match_id;
	}
 
        pCrawl = pCrawl->children[index];
    }
    if(type==1 && id)
	return id;
    if(type==0 && pCrawl->exact_match_id )
	return pCrawl->exact_match_id;
    return 0;
}
 
// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"abc", "fas", "abc","Abc"};
    int id[]={908,907,901,900};
    trie Trie;
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    //Trie.initialize();
 
    // Construct trie
    /*for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i],908,0);
    }*/
    Trie.insert(keys[0],id[0],0);
    Trie.insert(keys[1],id[1],0);
    Trie.insert(keys[2],id[2],1);
    Trie.insert(keys[3],id[3],0);
 
    // Search for different keys
    printf("%s --- %d\n", "abc", Trie.search("abc",0) );
    printf("%s --- %d\n", "abc", Trie.search("abcd",1) );
    printf("%s --- %d\n", "abc", Trie.search("Abc",0) );
    printf("%s --- %d\n", "fas", Trie.search("fas",0) );
    printf("%s --- %d\n", "fast", Trie.search("fast",1) );
 
    return 0;
}
