#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

typedef struct node
{
int data;
struct node * link;
}node;

node * head=NULL;

void insert(int data)
{
node *temp=new node;
temp->data=data;
temp->link=head;
head=temp;
//cout <<"inserted data "<<data<<endl;
}

void display()
{
node *temp=head;
while(temp)
{
	cout<<temp->data<<"\t";
	temp=temp->link;
}
}


int main()
{
priority_queue<node> pq;
int i;
for(i=3;i<8;i++)
	insert(i);


pq.push(1);
pq.push(2);

display();
return 0;
}
