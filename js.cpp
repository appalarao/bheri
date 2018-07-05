#include<iostream>
using namespace std;
typedef struct job
{
char j;
int st,ed,pf;
}job;
int maxi(int a, int b)
{
if(a>b)
	return a;
else
	return b;
}
int non_overlap_job(job a[4],int i)
{
int j;
	for(j=i-1;j>=0;j--)
		if(a[j].ed<=a[i].st)
			return j;
return -1;
}
void js(job a[4],int n)
{
int i,sum,val;
int temp[n];
temp[0]=a[0].pf;
for(i=1;i<4;i++)
{
	sum=a[i].pf;
	val=non_overlap_job(a,i);
	if(val!=-1)
		sum+=temp[val];
	
	temp[i]=maxi(temp[i-1],sum);
}
for(i=0;i<4;i++)
	cout<<a[i].j<<"-->"<<temp[i]<<"\t";
}
int main()
{
job a[4]={{'1',3, 10, 20}, {'2',1, 2, 50}, {'3',6, 19, 100}, {'4',2, 100, 200}};
js(a,4);
return 0;
}
