#include<iostream>
#include<vector>
using namespace std;
/*class pal
{
public:
	virtual void fun(char *str,int n);
};
*/
//class pal_seq : public pal
class pal_seq
{
public:
void fun(char *str,int n)
{
	int a[n][n]={0},i,j,gap;
	for(i=0;i<n;i++)
	{
		a[i][i]=1;
	}
	for(gap=2;gap<=n;gap++)
	{
		for(i=0;i<n-gap+1;i++)
		{
			j=gap+i-1;
			if(str[i]==str[j]&&gap==2)		
			{
				a[i][j]=2;
			}
			if(str[i]==str[j])
			{
				a[i][j]=2+a[i+1][j-1];
			}
			else
			{
				if(a[i][j-1]>a[i+1][j])
					a[i][j]=a[i][j-1];
				else
					a[i][j]=a[i+1][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"\n result is ======"<<a[0][n-1]<<endl;
}
};
int main()
{
//pal *obj;
pal_seq new_obj;
//obj=&new_obj;
char str[5]={'g','a','e','e','g'}; 
new_obj.fun(str,5);
return 0;
}
