#include<iostream>
using namespace std;
int main()
{
int a[]={-4,-1,-2,-11};
int cur_sum=0,max_sum=0;
int i;
for(i=0;i<4;i++)
{
cur_sum+=a[i];
if(cur_sum<=0)
	cur_sum=0;
if(cur_sum>max_sum)
	max_sum=cur_sum;
}
int min=a[0];
if(max_sum==0)
{
for(i=1;i<4;i++)
if(min<a[i])
	min=a[i];
max_sum=min;
}
cout<<"result is "<<max_sum<<endl;
}
