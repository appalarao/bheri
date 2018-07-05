#include<iostream>
#include<string.h>
using namespace std;
#define ROW 4
#define COL 4
int a[ROW][COL]={1,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0};
int color[ROW][COL];
int i,j;
//for(i=0;i<ROW;i++)
//for(j=0;j<COL;j++)
//	color[i][j]=0;	


int is_valid(int i,int j)
{
//	cout<<"\n i= "<<i<<"\t j= "<<j<<"\n";
	if(a[i][j]&&color[i][j]==0&&(i>=0&&i<ROW)&&(j>=0&&j<COL)) 
		return 1; 
	else
		 return 0;
}
void dfs(int i,int j)
{
	is_valid(i,j);
	int t1[8]={-1,-1,-1,0,0,1,1,1};
        int t2[8]={-1,0,1,-1,1,-1,0,1};
	int c1=0;
	for(c1=0;c1<8;c1++)
	{
		if(is_valid(i+t1[c1],j+t2[c1]))
		{
			color[i+t1[c1]][j+t2[c1]]=1;
			dfs(i+t1[c1],j+t2[c1]);
		}
	}

}
int cnt_island()
{
int i,j,cnt=0;
memset(color,0,ROW*COL);

for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++)
		{
			if(a[i][j]&&color[i][j]==0)
			{
				dfs(i,j);
				cnt++;
			}
		}
}
return cnt;
}
int main()
{
cout<<"number of islands are "<<cnt_island();
return 0;
}
