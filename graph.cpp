#include<iostream>
#include<queue>
#define INF 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
int color[5];

int findmin(int *val,int *mstset)
{
int i;
int min_val=INF;
for(i=0;i<5;i++)
{
if((mstset[i]==0)&&val[i]<=min_val)
	min_val=i;
}
return min_val;
}

int printMST(int parent[], int n, int g[5][5])
{
int i;
   for (i = 1; i < 5; i++)
     cout<<parent[i]<<"-"<<i<<" "<< g[i][parent[i]]<<endl;
}

void PRIMS_SPANNING_TREE(int g[5][5])
{
int parent[5];
int val[5];
int mstset[5];
int i,v;

for(i=0;i<5;i++)
{
	val[i]=INF;
	mstset[i]=0;
	parent[i]=0;
}
parent[0]=-1;
val[0]=0;
for(i=0;i<5;i++)
{
	int u=findmin(val,mstset);
	mstset[u]=1;
	for(v=0;v<5;v++)
	{	
		if((g[u][v]!=0)&&(mstset[v]==0)&&g[u][v]<val[v])
			{
				val[v]=g[u][v];	
				parent[v]=u;
			}
	}
}

printMST(parent,5,g);
}

void DFS_VISIT(int g[5][5],int );
void DFS(int g[5][5])
{
int i;
for(i=0;i<5;i++)
	color[i]=WHITE;
for(i=0;i<5;i++)
{
	if(color[i]==WHITE)
		DFS_VISIT(g,i);
}
}
void DFS_VISIT(int g[5][5],int i)
{
color[i]=GRAY;

cout<<i<<"\t";
int k;

for(k=0;k<5;k++)
{
if(g[i][k]&&color[k]==WHITE)
	DFS_VISIT(g,k);
}
color[i]=BLACK;
}


void BFS(int g[5][5])
{
int source,i,j,temp;
queue<int>q;
for(i=0;i<5;i++)
	color[i]=WHITE;

cout<<"enter source vertex ";
cin>>source;
q.push(source);
color[source]=GRAY;
while(!q.empty())
{
	temp=q.front();
	for(i=0;i<5;i++)
	{
		if(g[temp][i])
		{
			if(color[i]==WHITE)
			{
				q.push(i);
				color[i]=GRAY;
			}
		}
	}
	cout<<temp<<"\t";
	color[temp]=BLACK;
	q.pop();
}

}

void create(int g[][5],int n)
{
	int i,j,temp,data,wt;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		g[i][j]=0;
	}

	for(i=0;i<n;i++)
	{
		cout<<"enter number of vertices to node "<<i<<"\t";
		cin>>temp;
		{
			for(j=0;j<temp;j++)
			{
			cout<<"enter data && wight "<<j<<endl;
			cin>>data;
			cin>>wt;
			g[i][data]=wt;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<g[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
int n;

int g[5][5];
int i,j;
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
		g[i][j]=0;
}
//create(g,n);

g[0][1]=2;
g[0][3]=6;
g[1][0]=2;
g[1][2]=3;
g[1][3]=8;
g[1][4]=5;
g[2][1]=3;
g[2][4]=7;
g[3][0]=6;
g[3][1]=8;
g[3][4]=9;
g[4][1]=5;
g[4][2]=7;
g[4][3]=9;
cout<<"\n------------BFS traversal is----------\n";
BFS(g);
cout<<"\n----------DFS traversal is----------\n";
DFS(g);
cout<<"\n calling prims\n";
PRIMS_SPANNING_TREE(g);
return 0;
}
