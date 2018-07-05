#include<iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

typedef struct node 
{
struct node *left, *right;
int data;
}node;

void insert_bst(node **root, int data)
{
node *temp=new node;
temp->data=data;
temp->left=temp->right=NULL;
if(*root==NULL)
{
*root=temp;
}
else if(data<(*root)->data)
{
insert_bst(&((*root)->left),data);
}
else if(data>(*root)->data)
{
insert_bst(&((*root)->right),data);
}
}

void inorder(node *root)
{
if(root)
{
inorder(root->left);
cout<<root->data<<"\t";
inorder(root->right);
}
}

void inorder_with_stack_1(node *root)
{
	stack<node *> s;
	node *temp;

	int flag=0;
	while(!flag)
	{
		if(root!=NULL)
		{
		s.push(root);
		root=root->left;
		}
		else
		{
			if(!s.empty())
			{
				temp=s.top();
				s.pop();
				cout<<temp->data<<"\t";
				root=temp->right;
			}
			else
			{
				flag=1;
			}
		}
	}
}



void morris_inorder(node *root)
{
	node *pred,*temp,*cur;
	cur=root;
	while(cur)
	{
		if(cur->left==NULL)
		{
			cout<<cur->data<<"\t";
			cur=cur->right;
		}
		else
		{
			pred=cur->left;
			while(pred->right!=NULL&&pred->right!=cur)
			pred=pred->right;
		
			if(pred->right==NULL)
			{
				pred->right=cur;
				cur=cur->left;
			}
			if(pred->right==cur)
			{
				pred->right=NULL;
				cout<<cur->data<<"\t";
				cur=cur->right;
			}
		}
	}
}
void morris_preorder(node *root)
{
	node *pred,*temp,*cur;
	cur=root;
	while(cur)
	{
		if(cur->left==NULL)
		{
			cout<<cur->data<<"\t";
			cur=cur->right;
		}
		else
		{
			pred=cur->left;
			while(pred->right!=NULL&&pred->right!=cur)
			pred=pred->right;
		
			if(pred->right==NULL)
			{
				cout<<cur->data<<"\t";
				pred->right=cur;
				cur=cur->left;
			}
			if(pred->right==cur)
			{
				pred->right=NULL;
				cur=cur->right;
			}
		}
	}
}


void preorder(node *root)
{
if(root)
{
cout<<root->data<<"\t";
preorder(root->left);
preorder(root->right);
}
}
void preorder_with_stack_1(node *root)
{
	stack<node *>s;
	node *temp;
	int flag=0;
	while(!flag)
	{
		if(root)
		{
			cout<<root->data<<"\t";
			s.push(root);
			root=root->left;
		}
		else
		{
			if(!s.empty())
			{
				temp=s.top();
				s.pop();
				root=temp->right;
			}
			else
			{	
				flag=1;
			}
		}
	}
}

/*void morris_preorder(node *root)
{
	node *pred,*cur,*temp;
	cur=root;
	while(cur)
	{
		if(cur->left==NULL)
		{
		cout<<cur->data<<"\t";
		cur=cur->right;
		}
		else
		{
			pred=cur->left;
			while(pred->right!=NULL&&pred->right!=cur)
			pred=pred->right;
			if(pred->right==NULL)
			{
				cout<<cur->data<<"\t";
				pred->right=cur;
				cur=cur->left;
			}
			if(pred->right==cur)
			{
				pred->right=NULL;
				cur=cur->right;
			}
		}
	}
}
*/
void postorder(node *root)
{
if(root)
{
postorder(root->left);
postorder(root->right);
cout<<root->data<<"\t";
}
}

void post_order_with_stack(node *root)
{
	stack <node *> s1,s2;
	s1.push(root);
	node *temp;
	while(!s1.empty()||!s2.empty())
	{
		while(!s1.empty())
		{
		temp=s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
		s1.push(temp->left);
		if(temp->right)
		s1.push(temp->right);
		}
		while(!s2.empty())
		{
		temp=s2.top();
		s2.pop();
		cout<<temp->data<<"\t";
		}
	}
}

void insert_bt(node **root,int data)
{
*root=new node;
(*root)->left=(*root)->right=NULL;
(*root)->data=data;
}

int is_bst(node * root,int min,int max)
{
if(root->data>max||root->data<min)
return 0;
else
return is_bst(root->left,min,root->data)&&is_bst(root->right,root->data,max);
}

int max(int a, int b)
{
return a>b?a:b; 
}

int hieght(node * root)
{
if(root==NULL)
return 0;
if(root->left==NULL&&root->right==NULL)
return 0;
else 
return 1+max(hieght(root->left),hieght(root->right));
}


int Diameter(node *root)
{
node *temp;
int l_height,r_height;

if(root==NULL)
return 0;
l_height=hieght(root->left);
r_height=hieght(root->right);

int l_diameter=Diameter(root->left);
int r_diameter=Diameter(root->right);

return max(l_height+r_height+1,max(l_diameter,r_diameter));
}

void d_path(node *root,int d,map <int,vector<int> > &m)
{
	if(!root)
	return;
	
	m[d].push_back(root->data);

	d_path(root->left,d,m);

	d_path(root->right,d+1,m);

}

void diagonal_traversal(node *root)
{

	map<int ,vector<int> > m;
	d_path(root,0,m);
	map<int,vector<int> >::iterator it;

	for ( it = m.begin();it != m.end(); ++it)
	{
        	vector<int>::iterator itr;
	       for ( itr = it->second.begin();itr != it->second.end(); ++itr)
        	cout << *itr  << ' ';
 
	       cout << '\n';
        }
}
void spiral_order(node* root)
{
stack<node *>s1,s2;
s1.push(root);
node *temp;
while((!s1.empty())||(!s2.empty()))
{
	while(!s1.empty())
	{
		temp=s1.top();
		s1.pop();
		cout<<temp->data<<"\t";
		if(temp->left)
		s2.push(temp->left);
		if(temp->right)
		s2.push(temp->right);
	}
	while(!s2.empty())
	{
		temp=s2.top();
		s2.pop();
		cout<<temp->data<<"\t";
		if(temp->right)
		s1.push(temp->right);
		if(temp->left)
		s1.push(temp->left);
	}
}
}
/*
void alt_extream_nodes(node *root)
{
queue<node *> q;
node *temp;
q.push(root);
int flag=1,size;
while(!q.empty())
{
	size=q.size();
	while(size)
	{	
		temp=q.front();
		q.pop();
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
		if(flag==1&&size=n-1)
		{
			cout<<temp->data<<"\t";
			flag=0;
		}
		if(flag==0&&size=)
		{
			cout<<temp->data<<"\t";
			flag=1;
		}

}*/
/*
while(!q.empty())
{
	size=q.size();
	if(flag==1)//exteam left
	{	
		if(size>=1)
		{
			temp=q.front();
			q.pop();
			cout<<temp->data<<"\t";
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
			size--;
		}
		while(size)
		{
			temp=q.front();
			q.pop();
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
			size--;
		}
		flag=0;
	}
	else if(flag==0)
	{
		while(size>=2)
		{
			temp=q.front();
			q.pop();
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
			size--;
			
		}
		if(size==1)
		{
			temp=q.front();
			q.pop();
			cout<<temp->data<<"\t";
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
			size--;
		}
		flag=1;
	}
	
}

}
*/

int lca(node *root,int d1,int d2)
{
	if(root==NULL)
		return 0;
//	if(root->left==NULL&&root->right==NULL)
//		return 0;
	if(root->data==d1||root->data==d2)
		return 1;
	int l_val=lca(root->left,d1,d2);
	int r_val=lca(root->right,d1,d2);
	
	if(l_val&&r_val)
	{
		cout<<"\n lca is "<<root->data<<endl;
		return root->data;
	}
	
	l_val?cout<<l_val<<endl:cout<<r_val<<endl;
}

int main()
{

node * root=NULL;
node * broot=NULL;


insert_bt(&broot,10);
insert_bt(&(broot->left),15);
insert_bt(&(broot->right),20);
insert_bt(&(broot->left->left),100);
insert_bt(&(broot->left->right),200);
int val=lca(broot,100,200);
cout<<"final value of lca is "<<val<<endl;
/*cout<<"\n==========bt traversal=============\n";
inorder(broot);
cout<<"\n============================\n";
cout<<"val is "<<is_bst(broot,-1,10000);
if(is_bst(broot,-1,1000))
cout<<"\n===============the given btree is binary search tree====\n";
else
cout<<"\n===============it's not binary search tree===========\n";
*/
insert_bst(&root,10);
insert_bst(&root,5);
insert_bst(&root,15);
insert_bst(&root,3);
insert_bst(&root,7);
insert_bst(&root,-10);
insert_bst(&root,4);
insert_bst(&root,-7);
insert_bst(&root,1);
insert_bst(&root,6);
insert_bst(&root,9);
insert_bst(&root,8);

//cout<<"\n\n====inorder is======\n\n";
//inorder(root);
//cout<<"\n----------------------------\n";
//cout<<"\n-----------------diameter is--------------------\n";
//cout<<Diameter(root);
/*cout<<"\n-----------------------\n";
cout<<"\n------diagonal traversal-----------\n";
diagonal_traversal(root);
cout<<"\n----------------------------------------\n";
inorder_with_stack_1(root);
cout<<"\n---------------------\n";
inorder_with_stack_2(root);
cout<<"\n\n---------preorder with stack-----------\n\n";
preorder_with_stack_1(root);
cout<<"\n---------------------------\n";
cout<<"\n-----postorder-with stack-----------\n";
post_order_with_stack(root);
*/
/*
cout<<"\n\n-------------------\n\n";
cout<<"\n----------morris inorder------------\n";
morris_inorder(root);
cout<<"\n-----------------------------------\n";
cout<<"\n-----morris preorder-------------\n";
morris_preorder(root);
cout<<"\n-------------------------\n";
*/
/*cout<<"\n\n------------spiral order-----------\n\n";
spiral_order(root);
cout<<"\n\n-----------------------------------\n\n";
cout<<"\n\n------------------extream boundary traversal---------------\n\n";
alt_extream_nodes(root);
*/cout<<"\n--------------------------------------------------\n";
return 0;
}
