#include<iostream>
using namespace std;

	typedef struct node
	{
		int data;
		struct node * next;
	}node;

	node *list;
	void insert(int data)
	{
		node *temp=new node;
		temp->data=data;
		temp->next=NULL;
		if(list==NULL)
			list=temp;
		else
		{
			node *walk=list;
			while(walk->next)
				walk=walk->next;
			walk->next=temp;
		}
	}
	void disp()
	{
		node *walk=list;
		while(walk)
		{
			cout<<"\t"<<walk->data;
			walk=walk->next;
		}
	}
	node * greverse(node *l,int k)
	{
		node *cur,*prev,*nxt;
		cur=l;
		prev=NULL;
		int cnt=0;
		while(cur&&cnt<k)
		{
			nxt=cur->next;
			cur->next=prev;
			prev=cur;
			cur=nxt;
			cnt++;
		}
		if(l!=NULL)
		l->next=cur;
		
		cnt=0;
		while(cur!=NULL&&cnt<k-1)
		{
			cur=cur->next;
			cnt++;
		}
		
		if(cur!=NULL)
		{
			cur->next=greverse(cur->next,k);
		}
		return prev;
	}
int main()
{
	int i,data;
	for(i=1;i<=9;i++)
	{
		cout<<"\n enter node "<<i<<"-> ";
		cin>>data;
		insert(data);
	}
	cout<<"\n-----before reverse---------\n";
	disp();
	int k;
	cout<<"\nenter grp size ";
	cin>>k;
	node * l=greverse(list,k);
	cout<<"\n--------after reverse---------\n";
	node *t=l;
	while(t)
	{
		cout<<t->data<<"\t";
		t=t->next;
	}
}
