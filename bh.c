#include<stdio.h>
#include<math.h>
int power(int x,int y)
{
int val=1;
int i;
for(i=1;i<=y;i++)
{
	val*=x;
}
return val;
}
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
int i,cnt,sum,k=0;
i=9;
while(i>=0)
{
	cnt=0;
	sum=0;
	k=0;
	while(cnt<4&&i>=0)
	{
//		printf("\n POW val is = %d",power(2,k));
		sum+=a[i]*power(2,k);
	//	printf("\n sum is =%d ",sum);
		i--;
		cnt++;
		k++;
	}
//	printf("\n------------\n");
//	printf("\nnew sum is=%d",sum);
//	printf("\n-----------\n");
	if(sum>9)
	printf("%c",fun(sum));
	else
	printf("%d",sum);
}
return 0;
}
