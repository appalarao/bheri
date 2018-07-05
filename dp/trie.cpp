#include<iostream>
#include<map>
using namespace std;

typedef stuct node
{
	multimap<char,node *> m;
	int isend;
}mnode;

typedef struct node
{
	struct node* arr[26];
	int isend;
}node;
class Trie
{
mnode *root;
public:
	Trie()
	{
		root= new mnode;
		root->isend=0;		
	}
	mnode *getnode();
};


mnode*	Trie::getnode()
{
	mnode *temp=new mnode();
	temp->isend=0;
}


/*
class Distributed_trie
{
};
*/

void Trie::insert()
{
	int i,idx;
	char str[]={'a','b','c'};
	int len=3;
	mnode *walk=root;
	for(i=0;i<len;i++)
	{
		if(m.count(str[i]==0)
		{
			mnode *temp=getnode();
			walk->m[idx]=temp;
		}
	{
		 x->a[ s[i] ] = new Node;
        }
        x = x->a[ s[i] ];


		walk=walk->m[idx];	
		if(i==len-1)
		{
			walk->isend=1;
		}
	}
}

int Trie_with_map::find()
{
}
/*
class Trie
{
node *root;
public:
	Trie()
	{
		int i;
		root=new node;
		for(i=0;i<26;i++)
		{
			root->arr[i]=NULL;
		}
		root->isend=0;
	}
	node *getnode();
	void insert();
	int find();
};
*/
node * Trie:: getnode()
{
	node *temp;
	temp=new node;
	int i;
	for(i=0;i<26;i++)
		temp->arr[i]=NULL;
	temp->isend=0;
}

void Trie::insert()
{
	int i,idx;
	char str[]={'a','b','c'};
	int len=3;
	node *walk=root;
	for(i=0;i<len;i++)
	{
		idx=str[i]-(char)'a';
		if(walk->arr[idx]==NULL)
		{
			node *temp=getnode();
			walk->arr[idx]=temp;
		}
			walk=walk->arr[idx];	
		if(i==len-1)
		{
			walk->isend=1;
		}
	}
}

int Trie::find()
{
	char str[]={'a','b','c','d'};
	node *walk=root;
	int i,idx,val=1,len=4;
	for(i=0;i<len;i++)
	{
		idx=str[i]-(char)'a';
		if(walk->arr[idx]==NULL)
		{
			val=0;
			break;
		}
		walk=walk->arr[idx];
	}
	return val;
}

int main()
{
	Trie trie;

	trie.insert();
	if(trie.find())
		cout<<"obj is present "<<endl;
	else
		cout<<"obj is not present"<<endl;
	return 0;
}
