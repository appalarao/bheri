#include<stdio.h>
char fun(int v)
{
char val;
	switch(v)
	{
		case 10:
			val='A';
			break;
		case 11:
			val='B';
			break;
		case 12:
			val='C';
			break;
		case 13:
			val='D';
			break;
		case 14:
			val='E';
			break;
		case 15:
			val='F';
			break;
	}
	return val;
}
int main()
{
int a[]={1,0,1,0,1,0,1,0,0,0};
int i,cnt,sum;
i=9;
while(i>=0)
{
	cnt=0;
	sum=0;
	while(cnt<4&&i>=0)
	{
		sum+=a[i]*2;
		i--;
		cnt++;
	}
	if(sum>9)
	printf("%c",fun(sum));
	else
	printf("%d",sum);
}
return 0;
}
