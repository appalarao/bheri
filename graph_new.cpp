#include<iostream>
#include<queue>
#define n 5
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define GREEN 3
#define RED 4
#define MAX 1000 
using namespace std;
typedef struct node
{
struct node * next;
int data,wt;
}node;
node *g[n];
int color[n];
int find_min(int val[n],int visit[n])
{
int min=MAX;
int i,res;
for(i=0;i<n;i++)
	{
		if(visit[i]==0&&val[i]<min)
			{
				min=val[i];
				res=i;
			}
	}
return res;
}

int is_bipartite()
{
int color[n];
int i;
for(i=0;i<n;i++)
	color[i]=WHITE;
queue<int >q;
int source,val,new_val;
node *temp;
cout<<"enter source between 0 and "<<n<<endl;
cin>>source;
q.push(source);
color[source]=GREEN;
while(!q.empty())
{
	val=q.front();
	q.pop();
	temp=g[val];
	while(temp)
	{
		new_val=temp->data;
		cout<<"\n val is "<<new_val<<" it's color "<<color[new_val]<<" it's parent's color "<<color[val]<<endl;
		if(color[new_val]==WHITE)
		{
			q.push(new_val);
			if(color[val]==GREEN)
				color[new_val]=RED;
			else
				color[val]=GREEN;
		}
		else
		{
			if(color[val]==color[new_val])
			{
				return 0;
			}
		}
		temp=temp->next;
	}
}
return 1;
}
void PRIMS()
{
int mst_set[n];
int val[n];
int visit[n];
int parent[n];
int i;
for(i=0;i<n;i++)
	{
		val[i]=MAX;
		visit[i]=0;
		parent[i]=-1;
	}
int source;
cout<<"\nenter source vertex\n";
	cin>>source;
val[source]=0;
parent[source]=-1;
int min_key,new_val;
node *temp;

for(i=0;i<n-1;i++)
{
	min_key=find_min(val,visit);
//	cout<<"\nval is "<<min_key<<endl;
		mst_set[i]=min_key;
		visit[min_key]=1;
	temp=g[min_key];
	while(temp)
	{
		new_val=temp->data;
		if(visit[new_val]==0)
		if(temp->wt<val[new_val])
		{	val[new_val]=temp->wt;
			//cout<<"\nval[ "<<new_val<<" ] is "<<val[new_val]<<endl;
			parent[new_val]=min_key;
		}
		temp=temp->next;
	}
}
cout<<endl;
for(i=0;i<n-1;i++)
{
cout<<mst_set[i]<<"\t";
}

cout<<"\n===============prim's algo===========\n";
node *walk;
for(i=0;i<n-1;i++)
{
	walk=g[mst_set[i]];
	while(walk->data!=mst_set[i])
		walk=walk->next;
	cout<<parent[i]<<"-"<<mst_set[i]<<"\t"<<walk->wt<<"\n";
}

}

void DFS_VISIT(int i)
{
	color[i]=GRAY;
	node *temp;
	int val;
	temp=g[i];
	cout<<i<<"\t";
	while(temp)
	{
		val=temp->data;
		if(color[val]==WHITE)
		{
			DFS_VISIT(val);
		}
		temp=temp->next;
	}
	color[val]=BLACK;
}
void DFS()
{
int source,i;
for(i=0;i<n;i++)
	color[i]=WHITE;
cout<<"\n enter source\n";
	cin>>source;
for(i=0;i<n;i++)
{
if(color[i]==WHITE)
	DFS_VISIT(i);
}
}


void init()
{
int i;
for(i=0;i<n;i++)
	g[i]=NULL;
}

void insert()
{
int i,j,w,data,adj;
node *temp,*walk;
for(i=0;i<n;i++)
{
	walk=g[i];
	cout<<"how many adj nodes to node "<<i<<"\t";
	cin>>adj;
	for(j=1;j<=adj;j++)
	{
		cout<<" enter data and wt for node "<<j<<"\t";
		cin>>data;
//		cin>>w;
		temp=new node;
		temp->data=data;
//		temp->wt=w;
		temp->next=NULL;
		if(g[i]==NULL)
		{
			walk=g[i]=temp;			
		}
		else
		{
			while(walk->next)
				walk=walk->next;
			walk->next=temp;
		}
	}
}
}
void BFS()
{
queue<int >q;
int val,new_val;
int source;
node *temp;
cout<<"\n enter source \n";
cin>>source;
int i;
for(i=0;i<n;i++)
	color[i]=WHITE;

q.push(source);
color[source]=GRAY;

while(!q.empty())
{
val=q.front();
temp=g[val];

	while(temp)
	{
		new_val=temp->data;
		if(color[new_val]==WHITE)
		{
			q.push(new_val);
			color[new_val]=GRAY;
		}
		temp=temp->next;
	}
cout<<val<<"\t";
q.pop();
color[new_val]=BLACK;
}

}

int main()
{
init();
insert();
//BFS();
//DFS();
//PRIMS();
if(is_bipartite())
	cout<<"\n-----bipartite-----\n";
else
	cout<<"\n-----un-bipartite graph---\n";
return 0;
}
