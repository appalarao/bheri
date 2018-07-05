#include<iostream>
using namespace std;
void fib(int n)
{
int a[n+1]={0},i;
a[0]=1;
a[1]=1;
a[2]=2;
for(i=3;i<=n;i++)
{
	a[i]=a[i-1]+a[i-2];
}
cout<<"value is "<<a[n]<<endl;
}
int main()
{
int n;
cin>>n;
fib(n);
return 0;
}
