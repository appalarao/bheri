#include<iostream>
using namespace std;
int main()
{
int a[7]={6, 2, 5, 4, 5, 1, 6};
int b[7],i,j,cnt,nax;

for(i=0;i<7;i++)
{
	cnt=1;
	for(j=0;j<7;j++)
	{
		if(i!=j && a[j]<=a[i])
			cnt++;	
	}
	b[i]=a[i]*cnt;
}
for(i=0;i<6;i++)
{
	cout<<"val of "<<a[i]<<"  is "<<b[i]<<endl;
}
return 0;
}
