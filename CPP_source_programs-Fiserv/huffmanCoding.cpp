//Huffman coding for optimal representation of characters in a stream

#include<iostream>
#include<map>
#include<cstring>
using namespace std;


struct Node {
	char ch;
	Node* left;
	Node* right;
	public:
		Node(char input,Node* l=0, Node* r=0):ch(input),left(l),right(r) {
		}
};

void CreateHuffmanCode(Node* n,char ch[]);

int main()
{
	cout<<"huffman coding  using map and multimap"<<endl;
	multimap<int,Node*> mmap;
	//Node* n=new Node('a');
	mmap.insert(make_pair(45,new Node('a')));
	mmap.insert(make_pair(13,new Node('b')));
	mmap.insert(make_pair(12,new Node('c')));
	mmap.insert(make_pair(16,new Node('d')));
	mmap.insert(make_pair(9,new Node('e')));
	mmap.insert(make_pair(5,new Node('f')));
	map<int,Node*>::iterator iter,iter1;
	Node *n1,*n2,*temp;
	int val1=0,val2=0;
	//for(iter=mmap.begin();iter != mmap.end();iter++)
	int count=0;
	while(mmap.size()>1)
	{
		iter=mmap.begin();
		n1=iter->second;
		val1=iter->first;
		cout<<"first val="<<iter->first<<" second val="<<iter->second->ch<<endl;
		iter1=iter;
		iter++;
		cout<<"first val="<<iter->first<<" second val="<<iter->second->ch<<endl;
		val2=iter->first;
		n2=iter->second;
		temp = new Node(iter->second->ch,n1,n2);
		iter++;
		mmap.erase(iter1,iter);
		mmap.insert(make_pair(val1+val2,temp));		//let the node value be left most leaf character
		count++;
		if(count>8)
			break;
	}
	//now traverse root node created in the map
	iter=mmap.begin();
	cout<<"Total count of chars is "<<iter->first<<endl;
	
	temp=iter->second;	//this is root node
	char ch[1]={0};
	memset(ch,NULL,1+1);
	*ch='A';
	CreateHuffmanCode(temp,ch);
	return 0;
}
void CreateHuffmanCode(Node* n,char ch[])
{
	int leaffound=1;
	int len=strlen(ch);
	char newch[len+1];
	memset(newch,NULL,len+1+1);
	strcpy(newch,ch);
	if(n->left)
	{
		*(newch+len)='0';
		CreateHuffmanCode(n->left,newch);
		leaffound=0;
	}
	if(n->right)
	{
		*(newch+len)='1';
		CreateHuffmanCode(n->right,newch);
		leaffound=0;
	}
	if(leaffound)
		cout<<"char="<<n->ch<<" huffman code value="<<ch<<endl;
}
