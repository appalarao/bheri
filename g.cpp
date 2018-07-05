#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#define MAX 10
#define WHITE 1
#define GRAY  2
#define BLACK 3
using namespace std;

typedef struct node
{
    struct node* next;
    int data;
}node;

node *a[MAX];
int color[MAX];

class Graph
{
public:
    void create_directed_graph(int );
    void add(int );
    void BFS(int, int);
    void DFS(int,int);
    void DFS_VISIT(int,int);
    void topological_sort(int n);
    void aux_top_sort(int,stack <int> &,vector<int>&,int *);
};
void Graph::create_directed_graph(int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=NULL;
}
void Graph::add(int n)
{
    int i,anode,data,j;
    node *temp,*last;
    for(i=0;i<n;i++)
    {
    cout<<"how many links to node\t"<<i<<"\t";
    cin>>anode;
    for(j=1;j<=anode;j++)
    {
        cout<<"enter node value\t"<<j<<"\t";
        cin>>data;
        temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(a[i]==NULL)
    {
       a[i]=last=temp;
    }
    else
    {
       last->next=temp;
       last=temp;
    }
    }
    }
}

void Graph::aux_top_sort(int i,stack< int >&s,vector<int >&v,int vis[])
{
	vis[i]=1;
	node *temp;
	if(a[i]!=NULL)
	{
		temp=a[i];
		cout<<"loop-in recursion------"<<i<<endl;
		while(temp->next!=NULL)
		{
			aux_top_sort(temp->data,s,v,vis);				
		}
		s.push(i);	
		v.push_back(i);
	}
}

void Graph::topological_sort(int n)
{
stack<int> s;
vector<int >v;
vector<int>::iterator itr;
int vis[n];
int i;
for(i=0;i<n;i++)
	vis[i]=0;
	for(i=0;i<n;i++)
	{
		cout<<"\n iteration --"<<i<<endl;
		if(!vis[i])
		{
			aux_top_sort(i,s,v,vis);
		}
	}
cout<<"\n--------top sort is--------\n";
while(!s.empty())
{
	cout<<s.top()<<"\t";
	s.pop();
}
cout<<"\n-------from vector-------\n";
for(itr=v.end();itr!=v.begin();itr--)
	cout<<*itr<<"\t";
}

void Graph::BFS(int start,int n)
{
    queue<int> q;
    node *temp;
    int i,val1,val2;
    for(i=0;i<n;i++)
        color[i]=WHITE;
    color[start]=GRAY;
    q.push(start);
    while(!q.empty())
    {
        val1=q.front();
        temp=a[val1];
        while(temp)
        {
            val2=temp->data;
            if(color[val2]==WHITE)
            {
                q.push(val2);
                color[val2]=GRAY;
            }
            temp=temp->next;
        }
        cout<<val1<<"\t";
        color[val1]=BLACK;
    q.pop();
    }
}

void Graph::DFS(int start,int n)
{
int i,val1,val2;
node *temp;
stack<int> s;
for(i=0;i<n;i++)
color[i]=WHITE;

for(i=0;i<n;i++)
{
if(color[i]==WHITE)
DFS_VISIT(i,n);
}
}

void Graph::DFS_VISIT(int source, int n)
{
color[source]=GRAY;
int val1;
node *temp=a[source];
while(temp)
{
val1=temp->data;
if(color[val1]==WHITE)
DFS_VISIT(val1,n);
}
color[source]=BLACK;
cout<<"source \t";
}

int main()
{
    int n,i;
    cout<<"how many nodes in the graph ? ";
    cin>>n;
    Graph g;
    g.create_directed_graph(n);
    g.add(n);
   // cout<<"---bfs traversal---"<<endl;
    //g.BFS(0,n);
   // cout<<"\n---dfs traversal---"<<endl;
 //   g.DFS(0,n);
	cout<<"\n-----------topologiocal sorting is---------\n\n";
	g.topological_sort(n);
    return 0;
}

