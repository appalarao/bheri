#include<iostream>
#include<string.h>
using namespace std;
int fun(str[],int st,int ed)
{
if(st<ed)
{
	if(str[st]==str[ed])
	{
		return fun(str,st+1,ed-1);
	}
return max(fun(str,st+1,ed),fun(str,st,ed-1));
}
}
int main()
{
char str[]="abafa";
int cnt=
}
