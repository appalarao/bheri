#include<iostream>
#include<string.h>
using namespace std;
class LCS
{
	public:
		void fun(char *s,char *t,int l1,int l2);
		int maxi(int a,int b);
};
int LCS::maxi(int a, int b)
{
/*	int val;
	a>b?val=a:val=b;
	return val;
*/
if(a>b)
	return a;
else
	return b;
}
void LCS::fun(char s[],char t[],int l1,int l2)
{
	int a[l1+1][l2+1]={0};
int i,j;
for(i=0,j=0;i<l1+1||j<l2+1;i++,j++)
{
a[i][0]=0;
a[0][j]=0;
}
cout<<"\n\n------------------\n\n";
for(i=0;i<=l1;i++)
{
	for(j=0;j<=l2;j++)
		cout<<a[i][j]<<"\t";
	cout<<endl;
}
cout<<"\n\n------------\n\n";
for(i=1;i<=l1;i++)
{
	for(j=1;j<=l2;j++)
	{
		if(s[i-1]==t[j-1])
		{
			cout<<s[i-1]<<endl;
			a[i][j]=a[i-1][j-1]+1;
		}
		else
		{
			cout<<s[i-1]<<"\t"<<t[j-1]<<"\t";
			int x=maxi(a[i-1][j],a[i][j-1]);
			cout<<x<<endl;
			a[i][j]=x;
		}
	}
}
cout<<"\n\n--------------------\n\n";
//cout<<"\n value is =="<<a[l1-1][l2-1]<<"\t==="<<a[l1-1][l2-1];
for(i=0;i<=l1;i++)
{
	for(j=0;j<=l2;j++)
		cout<<a[i][j]<<"\t";
	cout<<endl;
}
char str[a[l1][l2]+1];
int k=a[l1][l2]-1;
i=l1;
j=l2;
while(i>=0&&j>=0)
{
	if(s[i-1]==t[j-1])
	{
		str[k]=s[i-1];
		k--;
		i--;
		j--;
	}
	else
	{
		if(a[i-1][j]>a[i][j-1])
			i--;
		else
			j--;
	}
	cout<<"i= "<<i<<"\t"<<"j= "<<j<<endl;
}

cout<<"\n-------------final output is ---------\n";
cout<<"val is "<<a[l1+1][l2+1]<<"\t"<<a[l1][l2]<<"\n";
for(k=0;k<a[l1][l2];k++)
	cout<<str[k]<<"\t";
}

int main()
{
char x[]="abcdef";
char y[]="abcdefghij";
LCS obj;
int l1=strlen(x);
int l2=strlen(y);
obj.fun(x,y,l1,l2);
return 0;
}
