/*
http://www.geeksforgeeks.org/auto-complete-feature-using-trie/
Auto-complete feature using Trie
===================================
We are given a Trie with a set of strings stored in it.
Now the user types in a prefix of his search query, we need to give him all recommendations to auto-complete
his query based on the strings stored in the Trie. We assume that the Trie stores past searches by the users.

Example:- if the Trie store {“abc”, “abcd”, “aa”, “abbbaba”} and
the User types in “ab” then he must be shown {“abc”, “abcd”, “abbbaba”}.

*/
#define NO_STL_CODE 1

#include<iostream>
#include<string>
#if NO_STL_CODE
#else
#include<vector>
#include<map>
#endif

using namespace std;
#if NO_STL_CODE
namespace NS87_NOSTL
{
	/************************************************************************************/
	template<typename T>
	class Array
	{
	public:
		Array(int _capacity = 2) : capacity(_capacity), size(0), arr(NULL)
		{
			arr = new T[capacity];
		}
		~Array()
		{
			if (arr != NULL) delete[] arr;
		}
		int length() { return size; }
		void clear() { size = 0; }
		T& operator[](int index)
		{
			if (index < 0 || index >= size) return T();
			return arr[index];
		}
		void push_back(const T& data)
		{
			if (size == capacity)
			{//resize
				capacity = capacity * 2;
				T* new_arr = new T[capacity];
				// We can't do memcopy as array header infortmation will be copied
				//memcpy(new_arr+1, arr, size * sizeof(T)); 
				for (int i = 0; i < size; i++)
					new_arr[i] = arr[i];
				delete[] arr;
				arr = new_arr;
			}
			arr[size++] = data;
		}
	private:
		int capacity;
		int size;
		T* arr;
	};
	inline int getIndex(char c)
	{
		int index = -1;
		if (c >= 'A' && c <= 'Z') index = (c - 'A');
		if (c >= 'a' && c <= 'z') index = (26 + c - 'a');
		return index;
	}
	inline char getChar(int index)
	{
		int res = '\0';
		if (index >= 0 && index < 26) res = 'A' + index;
		if (index >= 26 && index < 52) res = 'a' + index - 26;
		return res;
	}
	/************************************************************************************/
	class Node
	{
	public:
		Node(bool _isWord = false) : is_a_word(_isWord), child_count(0)
		{
			for (int i = 0; i < 52; i++)
				children[i] = NULL;
		}
		int size() { return child_count; }
		void setIsWord(bool _isWord = true) { is_a_word = _isWord; }
		bool getIsWord() { return is_a_word; }

		Node* getChild(char c)
		{
			int index = getIndex(c);
			return index != -1 ? children[index] : NULL;
		}
		Node* getChildAt(int index)
		{
			return (index < 0 && index >= 52) ? NULL : children[index];
		}
		void addChild(char c, Node* child)
		{
			int index = getIndex(c);
			if (index != -1)
			{
				if (children[index] == NULL)
				{
					children[index] = child;
					child_count++;
				}
			}
		}
		void removeChild(char c)
		{
			int index = getIndex(c);
			if (index != -1)
			{
				if (children[index] != NULL)
				{
					children[index] = NULL;
					child_count--;
				}
			}
		}
	private:
		bool is_a_word;
		int child_count;
		Node* children[52];
	};

	/************************************************************************************/
	class Trie
	{
	public:
		Trie() { root = new Node(); }
		void insert(const string& word);
		void remove(const string& word);
		bool findWord(const string& word);
		void findPrefix(const string& prefix, Array<string>& result);
	private:
		Node* root;
		void findPrefixUtil(string prefix, Node* current, Array<string>& result);
		bool removeUtil(const string& word, int index, Node* current);
	};
	void Trie::insert(const string& word)
	{
		Node* current = root;
		int n = word.length();
		if (n == 0) return;
		for (int i = 0; i < n; i++)
		{
			Node* find = current->getChild(word[i]);
			if (find == NULL)
			{
				find = new Node();
				current->addChild(word[i], find);
			}
			current = find;
		}
		current->setIsWord(true);
	}

	void Trie::remove(const string& word)
	{
		if (word.length() == 0)
			return;
		removeUtil(word, 0, root);
	}
	bool Trie::removeUtil(const string& word, int index, Node* current)
	{
		if (current == NULL)
			return false;
		if (index == word.length())
		{
			if (!current->getIsWord()) // this word is not present 
				return false;
			if (current->size() == 0)
			{
				delete current;
				return true;
			}
			current->setIsWord(false);
			return false;
		}
		Node* next = current->getChild(word[index]);
		bool removeFromMap = removeUtil(word, index + 1, next);
		if (removeFromMap)
		{
			current->removeChild(word[index]);
			if (current->size() == 0 && !current->getIsWord()) // if it not word itself and hand no child
			{
				delete current;
				return true;
			}
		}
		return false;
	}
	bool Trie::findWord(const string& word)
	{
		int n = word.length();
		Node* curr = root;
		for (int i = 0; i < n; i++)
		{
			curr = curr->getChild(word[i]);
			if (curr == NULL)
				return false;
		}
		return curr->getIsWord();
	}
	void Trie::findPrefix(const string& prefix, Array<string>& result)
	{
		int n = prefix.length();
		Node* curr = root;
		for (int i = 0; i < n; i++)
		{
			curr = curr->getChild(prefix[i]);
			if (curr == NULL)
				return;
		}
		findPrefixUtil(prefix, curr, result);
	}
	void Trie::findPrefixUtil(string prefix, Node* current, Array<string>& result)
	{
		if (current == NULL)
			return;
		if (current->getIsWord())
			result.push_back(prefix);
		for (int i = 0; i < 52; i++)
		{
			Node* child = current->getChildAt(i);
			if (child != NULL)
			{
				findPrefixUtil(prefix + getChar(i), child, result);
			}
		}
	}
	/************************************************************************************/
	void test()
	{
		Trie T;
		T.insert("abc");
		T.insert("abcd");
		T.insert("abce");
		T.insert("aa");
		T.insert("abbbaba");

		Array<string> result;
		T.findPrefix("ab", result);
		for (int i = 0; i < result.length(); i++)
		{
			cout << result[i] << endl;
		}

		result.clear(); cout << "\n\n\n\n";
		T.remove("abcd");
		T.findPrefix("ab", result);
		for (int i = 0; i < result.length(); i++)
		{
			cout << result[i] << endl;
		}
		cout << "\n\n\n";
	}
}

#else
namespace NS87
{
	class Trie
	{
		struct node
		{
			bool isWord;
			std::map<char, node*>children;
			node(bool _isWord = false) : isWord(_isWord) {}
			node* getChild(char c)
			{
				std::map<char, node*>::iterator it = children.find(c);
				if (it != children.end())
					return it->second;
				return NULL;
			}
			void addChild(char c, node* child)
			{
				children[c] = child;
			}
		};
	public:
		Trie() { root = new node(); }
		void insert(const string& word);
		void remove(const string& word);
		bool findWord(const string& word);
		void findPrefix(const string& prefix, vector<string>& result);
	private:
		node* root;
		void findPrefixUtil(string prefix, node* current, vector<string>& result);
		bool removeUtil(const string& word, int index, node* current);
	};
	void Trie::insert(const string& word)
	{
		node* current = root;
		int n = word.length();
		if (n == 0) return;
		for (int i = 0; i < n; i++)
		{
			node* find = current->getChild(word[i]);
			if (find == NULL)
			{
				find = new node();
				current->addChild(word[i], find);
			}
			current = find;
		}
		current->isWord = true;
	}
	void Trie::remove(const string& word)
	{
		if (word.length() == 0)
			return;
		removeUtil(word, 0, root);
	}
	bool Trie::removeUtil(const string& word, int index, node* current)
	{
		if (current == NULL)
			return false;
		if (index == word.length())
		{
			if (!current->isWord) // this word is not present 
				return false;
			if (current->children.size() == 0)
			{
				delete current;
				return true;
			}
			current->isWord = false;
			return false;
		}
		node* next = current->getChild(word[index]);
		bool removeFromMap = removeUtil(word, index + 1, next);
		if (removeFromMap)
		{
			current->children.erase(current->children.find(word[index]));
			if (current->children.size() == 0 && !current->isWord) // if it not word itself and hand no child
			{
				delete current;
				return true;
			}
		}
		return false;
	}
	bool Trie::findWord(const string& word)
	{
		int n = word.length();
		node* curr = root;
		for (int i = 0; i < n; i++)
		{
			curr = curr->getChild(word[i]);
			if (curr == NULL)
				return false;
		}
		return curr->isWord;
	}
	void Trie::findPrefix(const string& prefix, vector<string>& result)
	{
		int n = prefix.length();
		node* curr = root;
		for (int i = 0; i < n; i++)
		{
			curr = curr->getChild(prefix[i]);
			if (curr == NULL)
				return;
		}
		findPrefixUtil(prefix, curr, result);
	}
	void Trie::findPrefixUtil(string prefix, node* current, vector<string>& result)
	{
		if (current == NULL)
			return;
		if (current->isWord)
			result.push_back(prefix);
		std::map<char, node*>::iterator it;
		for (it = current->children.begin(); it != current->children.end(); it++)
			findPrefixUtil(prefix + it->first, it->second, result);
	}
	void test()
	{
		Trie T;
		T.insert("abc");
		T.insert("abcd");
		//T.insert("abce");
		T.insert("aa");
		T.insert("abbbaba");

		vector<string> result;
		T.findPrefix("ab", result);
		for each (string word in result)
		{
			cout << word << endl;
		}

		result.clear(); cout << "\n\n\n\n";
		T.remove("abcd");
		T.findPrefix("ab", result);
		for each (string word in result)
		{
			cout << word << endl;
		}
		cout << "\n\n\n";
	}
}
#endif

int main_87()
{

#if NO_STL_CODE
	NS87_NOSTL::test();
#else
	NS87::test();
#endif
	return 0;
}