#include<iostream>
using namespace std;

void perm(char *str,int st,int ed)
{
if(st==ed)
	cout<<str<<"\t";
else
{
int i;
char temp;
for(i=st;i<ed;i++)
{
temp=str[st];
str[st]=str[i];
str[i]=temp;

cout<<"\n-->"<<str<<"-->st and ed are "<<st<<"\t"<<ed<<endl;
perm(str,st+i+1,ed);

temp=str[st];
str[st]=str[i];
str[i]=temp;
//cout<<"\n-->"<<str<<endl;
cout<<"\n-->"<<str<<"-->st and ed are "<<st<<"\t"<<ed<<endl;
perm(str,st+i,ed);
}
}
}

int main()
{
char str[]="abc";
perm(str,0,2);
return 0;
}
