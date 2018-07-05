#include<iostream>
using namespace std;
int main()
{
int a[]={7,3,2,9,4};
int i=0,j=4,small=0;

int length=j-i+1;
int mid=0;
if(length%2==1)
{
mid=length/2;
a[mid]++;
}
if(length%2==0)
{
small=a[mid]<a[mid+1]?a[mid]:a[mid+1];
a[mid]=a[mid+1]=small+1;
}

cout<<a[mid]<<a[mid+1]<<endl;


i=0;j=4;
while(i<j)
{
if(a[i]==a[j])
{
i++;j--;
}
else 
{
small=a[i]<a[j]?a[i]:a[j];

a[j]=a[i]=small;
i++;j--;
}
}
for(i=0;i<5;i++)
cout<<a[i]<<"\t";
}
