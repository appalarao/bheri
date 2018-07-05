#include<iostream>
#define max_val 99999
#define INT_MAX  1000000
using namespace std;
int main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	int m[n][n]={0};
	int i,j,k,gap,val;
	for(i=1;i<n;i++)
	m[i][i]=0;

	for(gap=2;gap<n;gap++)
	{
		for(i=1;i<n-gap+1;i++)
		{
			j=i+gap-1;
			m[i][j]=max_val;
			for(k=i;k<=j-1;k++)
			{
				val=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];

				if(val<m[i][j])	
				m[i][j]=val;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<m[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
