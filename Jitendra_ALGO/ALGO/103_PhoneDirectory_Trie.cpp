/*
https://www.geeksforgeeks.org/implement-a-phone-directory/
Implement a Phone Directory
---------------------------
Given a list of contacts which exist in a phone directory. The task is to implement search query for the phone directory. 
The search query on a string ‘str’ displays all the contacts which prefix as ‘str’. 
One special property of the search function is that, when a user searches for a contact from the contact list 
then suggestions (Contacts with prefix as the string entered so for) are shown after user enters each character.

Note : Contacts in the list consist of only lower case alphabets.
Example:

Input : contacts [] = {“gforgeeks” , “geeksquiz” }
Query String = “gekk”

Output : Suggestions based on "g" are
geeksquiz
gforgeeks

Suggestions based on "ge" are
geeksquiz
No Results Found for "gek"
No Results Found for "gekk"

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
namespace NS103
{	 
	struct TrieNode
	{
		using TrieMap = unordered_map<char, TrieNode*>;
		TrieMap children;
		bool isLastNode;

		TrieNode() : isLastNode(false)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				children[c] = nullptr;
			}
		}
	};

	TrieNode* root = nullptr;
	void insert(string str)
	{
		TrieNode* itr = root;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			TrieNode* nextPtr = itr->children[c];
			if (nextPtr == nullptr)
			{
				nextPtr = new TrieNode();
				itr->children[c] = nextPtr;
			}

			itr = nextPtr;
			if (i == str.length() - 1)
				itr->isLastNode = true;
		}
	}

	void insertIntoTrie(string contacts[], int n)
	{
		root = new TrieNode();
		for (int i = 0; i < n; i++)
			insert(contacts[i]);
	}

	void displayContactsUtil(TrieNode *curNode, string prefix)
	{
		if (curNode->isLastNode)
			cout << prefix << endl;
		for (char c = 'a'; c <= 'z'; c++)
		{
			if (curNode->children[c] != nullptr)
				displayContactsUtil(curNode->children[c], prefix + c);
		}
	}

	void displayContacts(string str)
	{
		TrieNode* prevNode = root;
		string prefix = "";
		int len = str.length();

		for (int i = 0; i < len; i++)
		{
			prefix += str[i];
			char lastChar = str[i];

			TrieNode* curNode = prevNode->children[lastChar];
			if (curNode == nullptr)
			{
				cout << "\nNo Results Found for \"" << prefix << "\" \n";
				break;
			}
			cout << "\nSuggestions based on \"" << prefix << "\" are : \n";
			displayContactsUtil(curNode, prefix);

			prevNode = curNode;
		}
	}


	void test()
	{
		// Contact list of the User
		string contacts[] = { "gforgeeks" , "geeksquiz" };

		// Size of the Contact List
		int n = sizeof(contacts) / sizeof(string);

		// Insert all the Contacts into Trie
		insertIntoTrie(contacts, n);

		string query = "gekk";

		// Note that the user will enter 'g' then 'e', so
		// first display all the strings with prefix as 'g'
		// and then all the strings with prefix as 'ge'
		displayContacts(query);
	}
}

//int main()
int main_103()
{
	NS103::test();
	return 0;
}
