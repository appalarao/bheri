#include<iostream>
#include<map>

using namespace std;
typedef struct node 
{
int data,rank;
struct node *parent;
}node ;

typedef struct node
{
int data,wt;
struct node * link
}gnode;

map <int,node * > m;
node * arr[MAX];

void add(int i, data,int cost)
{
gnode* walk=arr[i];
gnode* temp=new gnode;
temp->data=data;
temp->wt=cost;
gnode->link=NULL;
if(walk==NULL)
{
walk=temp;
}
else
{
while(walk->next!=NULL)
	walk=walk->link;

walk->link=temp;
}
void sort_edges(int n)
{

}
}
	void makeset(int data)
	{
		node* n=new node;
		n->data=data;
		n->parent=n;
		n->rank=0;
		m.insert(make_pair(data,n));
	}


node * findset(node * n)
{
node *p=n->parent;
if(p==n)
{
return p;
}
n->parent=findset(n->parent);
return n->parent;
}
/*
int find(int d)
{
	return findset(m.find(d));
}
*/

void unin (int d1,int d2)
{
node * n1=m.at(d1);
node * n2=m.at(d2);
node *p1=findset(n1);
node *p2=findset(n2);
if(p1->data==p2->data)
{
return;
}
if(p1->rank>=p2->rank)
{
p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
p2->parent=p1;
}
else
{
p1->parent=p2;
}
}

int main()
{
	makeset(1);
	makeset(2);
	makeset(3);
	makeset(4);
//unin(1,2);
unin(2,3);
unin(1,4);
node * n1=m.at(4);
//node * n2=m.at(d2);
cout<<"\n--------------------"<<n1->data<<"------------\n";
node *temp=findset(n1);
cout<<"\n==============data is ===========\t"<<n1->data<<"\n rank is "<<temp->rank<<"\n parent is "<<temp->parent->data<<endl;
return 0;
}
