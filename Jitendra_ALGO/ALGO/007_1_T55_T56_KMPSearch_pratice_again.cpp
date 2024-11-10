#include<iostream>
using namespace std;

namespace NS7_1
{

	int matchKMP(const string& text, const string& pattern)
	{
		int pattern_len = pattern.length();
		int text_len = text.length();

		int matchIndex = -1;
		int* LSP = new int[pattern_len];
		LSP[0] = 0;
		int j = 0;
		int i = 1;
		while (i < pattern_len)
		{
			while (j > 0 && pattern[j] != pattern[i])
			{
				j = LSP[j - 1];
			}
			if (pattern[j] == pattern[i])
			{
				LSP[i] = j + 1; i++; j++;
			}
			else
			{
				LSP[i] = 0; i++;
			}
		}
		for (int k = 0; k < pattern_len; k++)
			cout << LSP[k] << "  ";
		i = 0; j = 0;
		bool found = false;
		while (i < text_len && !found)
		{
			while (j > 0 && text[i] != pattern[j])
			{
				j = LSP[j - 1];
			}
			if (text[i] == pattern[j]) // here either j==0 or text match
			{
				i++; j++;
				if (j == pattern_len)
				{
					matchIndex = i - pattern_len;
					found = true;
					break;
				}
			}
			else
			{
				i++; // just incrimate text index and start matching with it; as with j=0 it didnt match
			}
		}
		delete[] LSP;
		return matchIndex;

	}
	void test()
	{
		string patten("babaaa");
		string text("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba");
		int firstMatch = matchKMP(text, patten);
		cout << "index: " << firstMatch << endl;
	}
}


int main_007_1()
{
	NS7_1::test();
	return 0;
}