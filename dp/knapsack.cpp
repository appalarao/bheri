#include<iostream>
#include<vector>
using namespace std;
int maxi(int a,int b)
{
return a>b?a:b;
}
int main()
{
int pf[] = {1,4,3,7};
int wt[] = {2,3,4,5};
int  W = 7;
int a[5][W+1],i,j;
for(i=0;i<=4;i++)
	a[i][0]=0;

for(j=0;j<=W;j++)
	a[0][j]=0;

for(i=1;i<=4;i++)
{
	for(j=1;j<=W;j++)
	{
		if(wt[i-1]>j)
		{	
			a[i][j]=a[i-1][j];
		}
		else
		{
			a[i][j]=maxi(pf[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);
		}	
	}
}

cout<<"value is "<<a[4][W]<<endl;
for(i=0;i<5;i++)
{
	for(j=0;j<=W;j++)
		cout<<a[i][j]<<"\t";
	cout<<endl;
}

vector<int> v;
vector<int>::iterator itr;
i=4;
j=W;
cout<<"\n---------\n";
while(i>0&&j>0)
{
	if(a[i][j]==a[i-1][j])
	{
		i--;
	}
	else
	{
		v.push_back(wt[i-1]);
	//	cout<<wt[i-1]<<"\t";
		j=j-wt[i-1];
	}
//	cout<<"\ni= "<<i<<"\t j= "<<j<<endl;
}
for(itr=v.begin();itr!=v.end();itr++)
{
	cout<<*itr<<"\t";
}

}
