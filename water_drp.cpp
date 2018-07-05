#include<iostream>
#include<stack>
using namespace std;
int fun(int *,int);
int main()
{
stack<int> s;
int arr[7]={6,2,5,4,5,1,6};
int i,key ;
i=0;
while(i<7)
{
if(s.isempty())
{
s.push(ar[i]);
i++;
}
key=s.top();
if(arr[i]<key)
{
	i++;
}
}
return 0;
}
