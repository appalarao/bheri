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

void inorder(node *root)
{
if(root)
{
inorder(root->left);
cout<<root->data<<"\t";
inorder(root->right);
}
}

void insert_bt(node **root,int data)
{
*root=new node;
(*root)->left=(*root)->right=NULL;
(*root)->data=data;
}
void fun(node *root,int i,int cnt)
{

if(cnt==i)
	cout<<root->data<<"\t";
if(root->left)
	fun(root->left,i,cnt-1);
if(root->right)
	fun(root->right,i,cnt+1);

}
void vertical_travesal(node *root,int left,int right)
{
int i;
for(i=left;i<=right;i++)
{
	cout<<"\n"<<i<<"-->";
	fun(root,i,0);
}
}
int main()
{

node * root=NULL;
node * broot=NULL;


insert_bt(&broot,1);
insert_bt(&(broot->left),2);
insert_bt(&(broot->right),3);
insert_bt(&(broot->left->left),4);
insert_bt(&(broot->left->right),5);
insert_bt(&(broot->left->right->right),50);
insert_bt(&(broot->right->left),6);
insert_bt(&(broot->right->left->right),10);
insert_bt(&(broot->right->right),7);
insert_bt(&(broot->left->right->left),8);
insert_bt(&(broot->right->right->right),9);
inorder(broot);
vertical_travesal(broot,-2,3);
cout<<"\n--------------------------------------------------\n";
return 0;
}
