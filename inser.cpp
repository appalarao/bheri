#include<iostream>
using namespace std;

int main()
{
int a[5]={7,3,-1};
int i,j,t;
for(i=0;i<3;i++)
	cout<<a[i]<<"\t";

cout<<"\n=======\n";
for(i=1;i<3;i++)
{
	t=a[i];
	for(j=i;j>=0;j--)
	{
		if(a[j]>t)
		{
			a[j+1]=a[j];
		}
		
	}
	a[j+1]=t;
}
for(i=0;i<3;i++)
	cout<<a[i]<<"\t";
return 0;

}
