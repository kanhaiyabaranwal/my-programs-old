#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
//upper case not handled
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
struct trie_node
{
    int exact_match_id;
    int prefix_match_id;
    //int case;	//1-upper case, 2-lower case, 3-both
    trie_node *children[ALPHABET_SIZE];
};
 
struct trie
{
    trie_node *root;
};
 
// Returns new trie node (initialized to NULLs)
trie_node *getNode(void);
void initialize(trie *pTrie);
void insert(trie *pTrie, char key[],int id,bool type);	//type is for exact or prefix match;type=0-exact,1-prefix
int search(trie *pTrie, char key[],bool type);
trie_node *getNode(void)
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
void initialize(trie *pTrie)
{
    pTrie->root = getNode();
    pTrie->root->exact_match_id = 0;
    pTrie->root->prefix_match_id = 0;
}
 
// If not present, inserts key into trie
void insert(trie *pTrie, char key[],int id,bool type)	//type is for exact or prefix match;type=0-exact,1-prefix
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
		
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
	    
        }
 
        pCrawl = pCrawl->children[index];

	if(type==0)
		pCrawl->exact_match_id=id;
	else if(type==1)
		pCrawl->prefix_match_id=id;
}
 
// Returns non zero, if key presents in trie
int search(trie *pTrie, char key[],bool type)
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pCrawl = pTrie->root;
    int id=0; 
	cout<<"searching for "<<key<<endl;
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
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
/*int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"abc", "fas", "abc"};
    int id[]={908,907,901};
    trie Trie;
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    initialize(&Trie);
 
    // Construct trie
    //for(int i = 0; i < ARRAY_SIZE(keys); i++)
    //{
     //   insert(&trie, keys[i],908,0);
    //}
    insert(&Trie, keys[0],id[0],0);
    insert(&Trie, keys[1],id[1],0);
    insert(&Trie, keys[2],id[2],1);
 
    // Search for different keys
    printf("%s --- %d\n", "abc", search(&Trie, "abc",0) );
    printf("%s --- %d\n", "abc", search(&Trie, "abcd",1) );
 
    return 0;
}*/
