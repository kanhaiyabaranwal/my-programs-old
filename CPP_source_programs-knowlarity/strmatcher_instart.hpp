/********************************************************************
Description	:	Header File for Prefix and exact string matching 
Author	  	:	Kanhaiya P. Baranwal 
Date		:	07-FEB-2016
********************************************************************/


#ifndef STRINGMATCHER_H
#define STRINGMATCHER_H

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
    trie_node *children[ALPHABET_SIZE];
};
 
class trie
{
    	trie_node *root;
    	trie_node* getNode(void);
	bool deleteUtil(trie_node *pNode, const char* key, int level, int len,bool type);
	int leafNode(trie_node *pNode);
	int isItFreeNode(trie_node *pNode);
	public:
	trie();
	void insert(const char *key,int id,bool type);	//type is for exact or prefix match;type=0-exact,1-prefix
	int search(const char* key,bool type) const;
	bool deleteKey(const char* key,bool type);
	
};

int trie::leafNode(trie_node *pNode)
{
    return (pNode->exact_match_id || pNode->prefix_match_id);
}
 
int trie::isItFreeNode(trie_node *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}

bool trie::deleteUtil(trie_node *pNode, const char* key, int level, int len,bool type)
{
   if( pNode )
    {
        // Base case
        if( level == len )
        {
            // Unmark leaf node
            if(type==0 && pNode->exact_match_id)
	    {
		pNode->exact_match_id = 0; 
	     }
	    if(type==1 && pNode->prefix_match_id)
	    {
                pNode->prefix_match_id = 0;
	     }
 
              // If empty, node to be deleted
             if( pNode->exact_match_id==0 && pNode->prefix_match_id==0 && isItFreeNode(pNode) )
                    return true;
 
              return false;
        }
        else // Recursive case
        {
            	int index ;
		if(key[level]>='A' && key[level]<='Z')
	        	index = CAPITAL_CHAR_TO_INDEX(key[level]);
		if(key[level]>='a' && key[level]<='z')
		        index = SMALL_CHAR_TO_INDEX(key[level]);
 
            if( deleteUtil(pNode->children[index], key, level+1, len,type) )
            {
                // last node marked, delete it
		free(pNode->children[index]);
		pNode->children[index]=NULL;
 
                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }
    return false;
}

bool trie::deleteKey(const char* key,bool type)
{
	int len = strlen(key);
	bool res=true; 
	if( len > 0 )
    	{
		res=deleteUtil(root, key, 0, len,type);
    	}
	return res;
}
 
// Returns new trie node (initialized to NULLs)
trie_node* trie::getNode(void)
{
    trie_node *pNode = NULL;
 
    pNode = (trie_node *)malloc(sizeof(trie_node));
 
    if( pNode )
    {
 
        pNode->exact_match_id = 0;
        pNode->prefix_match_id = 0;
 
        for(int i = 0; i < ALPHABET_SIZE; i++)
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
}
 
// If not present, inserts key into trie
void trie::insert(const char* key,int id,bool type)	//type is for exact or prefix match;type=0-exact,1-prefix
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl=root;
 
    for( level = 0; level < length; level++ )
    {
		
	if(key[level]>='A' && key[level]<='Z')
	        index = CAPITAL_CHAR_TO_INDEX(key[level]);
	if(key[level]>='a' && key[level]<='z')
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
int trie::search(const char* key,bool type) const
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl;
 
    pCrawl = root;
    int id=0; 
    //cout<<"searching for "<<key<<endl;
    for( level = 0; level < length; level++ )
    {
	if(key[level]>='A' && key[level]<='Z')
	        index = CAPITAL_CHAR_TO_INDEX(key[level]);
	if(key[level]>='a' && key[level]<='z')
	        index = SMALL_CHAR_TO_INDEX(key[level]);
 
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
    if(level==length && type==0 && pCrawl->exact_match_id )
	return pCrawl->exact_match_id;
    return -1;
}
 
/// Header for a class that manages the mapping between a
/// string of alphabets and an id.
class StringMatcher
{
	trie Trie;
public:
	/// Constructor/Destructor
	StringMatcher() {}
	~StringMatcher() {}
	
	/// Add an exact string match, i.e. “abc” in
	/// the documentation above. Adding an exact match for an
	/// existing `exact_str` will overwrite the previous `id`.
	/// @param exact_str string to match with the id.
	/// @param id (>=0) that is mapped to this string.
	void add_exact_match(const char* exact_str, int id);
	
	/// Add a prefix string match i.e. “fas” in
	/// the documentation above. Adding a prefix match for an
	/// existing `prefix_str` will overwrite the previous `id`.
	/// @param prefix_str to match with the id.
	/// @param id (>=0) that is mapped to this string.
	void add_prefix_match(const char* prefix_str, int id);
	
	/// Get the id for the specified string.
	/// @param input to lookup the id for
	/// @returns -1 if there is no match or the id
	int lookup(const char* input) const;
	
	/// Delete the exact matches for the given string, i.e. if we have
	/// an add_exact_match(“str”, 2), delete_exact_match will remove the
	/// match of “str” to 2.
	/// @param exact_str exact match to delete.
	/// @return true if a match was deleted.
	bool delete_exact_match(const char* exact_str);
	
	/// Delete the prefix matches for the given string, i.e. if we have
	/// a add_prefix_match(“str”, 2), delete_prefix_match will remove the
	/// match of “str” to 2.
	/// @param prefix_str prefix match to delete.
	/// @return true if a match was deleted.
	bool delete_prefix_match(const char* prefix_str);

};
#define EXACT_MATCH 0
#define PREFIX_MATCH 1
void StringMatcher::add_exact_match(const char* exact_str, int id)
{
	Trie.insert(exact_str,id,EXACT_MATCH);
}
void StringMatcher::add_prefix_match(const char* prefix_str, int id)
{
	Trie.insert(prefix_str,id,PREFIX_MATCH);
}
int StringMatcher::lookup(const char* input) const
{
	int id=Trie.search(input,EXACT_MATCH);
	if(id==-1)
	{
		id=Trie.search(input,PREFIX_MATCH);
	}
	return id;
}
bool StringMatcher::delete_exact_match(const char* exact_str)
{
	return Trie.deleteKey(exact_str,EXACT_MATCH);
}
bool StringMatcher::delete_prefix_match(const char* prefix_str)
{
	return Trie.deleteKey(prefix_str,PREFIX_MATCH);

}

#endif // STRINGMATCHER_H
