#include<iostream>
#include<vector>
#define val 9999
using namespace std;
int maxi(int a,int b)
{
return a>b?a:b;
}
int main()
{
int floors,eggs;
cout<<"enter eggs\n";
cin>>eggs;
cout<<"enter floors \n";
cin>>floors;
int i,j,a[eggs+1][floors+1]={0},k,new_val;
for(i=0;i<=floors;i++)
	a[0][i]=0;
for(i=0;i<=eggs;i++)
	a[i][0]=0;
for(i=1;i<=floors;i++)
	a[1][i]=i;
for(i=1;i<=eggs;i++)
	a[i][1]=1;

for(i=2;i<=eggs;i++)
{
	for(j=2;j<=floors;j++)
	{
		a[i][j]=val;
		for(k=1;k<=j;k++)
		{
		
			new_val=1+maxi(a[i-1][k-1],a[i][j-k]);
			if(new_val<a[i][j])
			{
				a[i][j]=new_val;					
			//	cout<<"i,j "<<i<<","<<j<<"\t are"<<a[i][j]<<"\n";
			}
		}
	}
}

cout<<"\n-result is--------\n";
for(i=0;i<=eggs;i++)
{
for(j=0;j<=floors;j++)
{
	cout<<a[i][j]<<"\t";
}
cout<<endl;
}
return 0;
}
