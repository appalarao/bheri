#include<iostream>
using namespace std;
int findmin(int a[],int n)
{
int i,min;
min=0;
for(i=1;i<n;i++)
{
if(a[i]<a[min])
min=i;
}
return min;
}
int findmax(int a,int b,int c)
{
return a>b?(a>c?a:c):(b>c?b:c);
}
int fun(int arr[],int st,int ed)
{
if(st==ed)
return arr[st];
else
{
int n=ed-st;
int max,min;
if(n==2)
{
max=(arr[st]>arr[ed])?arr[st]:arr[ed];
min=(arr[st]<arr[ed])?arr[st]:arr[ed];
return max>(min*n)?max:(min*n);
}
{
int a,b,c;
int m=findmin(arr,n);
a=fun(arr,st,m-1);
b=fun(arr,m+1,ed);
c=arr[m]*n;
int res=findmax(a,b,c);
return res;
}
}
}

int main()
{
int a[]={4,4,7,6};
int res=fun(a,0,3);
cout<<"\nresult is "<<res<<endl;
return 0;
}
