#include<iostream>
#define MAX 100000;

using namespace std;
int maxi(int a, int b)
{
int val;
a>b?val=a:val=b;
return val;
}
int main()
{
int eggs,floors;
cout<<"enter no of egss and floors"<<endl;
cin>>eggs>>floors;
int a[eggs][floors];
int i,j,k,min,val;
for(i=0;i<floors;i++)
	a[0][i]=i+1;
for(i=1;i<eggs;i++)
{
	for(j=0;j<floors;j++)
	{
		if(i>=j)
		{
			a[i][j]=a[i-1][j];
		}
		else
		{
			min=MAX;
			for(k=1;k<j;k++)
			{
				val=1+maxi(a[i-1][k-1],a[i][j-k]);
				if(val<min)
				{
					min=val;
				}
			}
			a[i][j]=min;
		
	}
}

cout<<"\n\n---------------\n\n";
for(i=0;i<eggs;i++)
{
	for(j=0;j<floors;j++)
		cout<<a[i][j]<<"\t";
	cout<<endl;
}
return 0;
}
