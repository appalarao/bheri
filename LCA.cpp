#include<iostream>
#include<queue>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *left, *right;
}node;
Node* newNode(int data)
{
    Node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
/*
void LCA_bst(node * root,int d1,int d2)
{
if(d1<(root->data)&&d2>(root->data))
{
cout<<"val is      ->   "<<root->data;
return;
}
else if(d1>(root->data)&&(d2>root->data))
LCA_bst(root->right,d1,d2);
else if(d1<(root->data)&&d2<(root->data))
LCA_bst(root->left,d1,d2);
}
node *lca(node *root,int data1,int data2)
{
if(root==NULL)
return NULL;

}*/
/*int dis_btw_2nodes(node *root,int data1,int data2)
{
//node* lca_node=lca(root,data1,data2);
node *lca_node=root;
queue<node *>q,q1,q2;
node *temp;
int d=0,d1=0,d2=0,size=0;
node *root1,*root2,*root3;
root1=root;
q.push(root);
int flag=1;
while(!q.empty()&&flag)
{
	size=q.size();
	
	while(size!=0)
	{
		temp=q.front();
		q.pop();
		if(temp->data==lca_node->data)
			{
//				cout<<"temp data is "<<temp->data<<"\t and lca node is "<<lca_node->data<<endl;
				flag=0;
			break;
			}
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		size--;
	}
	d++;
}
flag=1;
size==0;
q1.push(root);
temp=NULL;
//cout<<"size is "<<q1.size()<<endl;
while(!q1.empty()&&flag)
{
	size=q1.size();
	
	while(size!=0)
	{
		temp=q1.front();
		q1.pop();
		if(temp->data==data1)
		{
			cout<<"temp data is "<<temp->data<<"\t and lca node is "<<data1<<endl;
			flag=0;
			break;
		}
		if(temp->left)
			q1.push(temp->left);
		if(temp->right)
			q1.push(temp->right);
		size--;
	}
	d1++;

}
flag=1;
q2.push(root);
size=0;
temp=NULL;
while(!q2.empty()&&flag)
{
	size=q2.size();
	
	while(size!=0)
	{
		temp=q2.front();
		q2.pop();
		if(temp->data==data2)
		{
			cout<<"temp data is "<<temp->data<<"\t and lca node is "<<data2<<endl;
			flag=0;
			break;
		}
		if(temp->left)
			q2.push(temp->left);
		if(temp->right)
			q2.push(temp->right);
		size--;
	}
	d2++;
}
cout<<"\n\nd1= "<<d1<<"\t d2= "<<d2<<"\t d= "<<d<<endl;
cout<<"\n\ndistance bwerween "<<data1<<" and "<<data2<<" is "<<d1+d2-2*d<<endl;
}
*/
int LCA(node *root,int d1,int d2)
{
	if(root==NULL)
		return 0;
	if(root->data==d1||root->data==d2)
		return 1;
	if(root->left==NULL&&root->right==NULL&&(root->data!=d1||root->data!=d2))
		return 0;
	if(LCA(root->left,d1,d2)&&LCA(root->right,d1,d2))
	{
		cout<<"\n"<<root->data<<"\n";
		return 0;
	}
	else
	{
		return LCA(root->left,d1,d2)||LCA(root->right,d1,d2);
	}
}
int main()
{
    Node *root = newNode(5);
    root->left = newNode(8);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(2);
    root->right->left = newNode(6);
    root->right->right = newNode(18);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(10);

    cout << "LCA IS \n";
    int d1,d2;
	cout<<"\n enter d1 and d2 "<<endl;
    cin>>d1;
    cin>>d2;
   int val=LCA(root,d1,d2);

    return 0;
}
