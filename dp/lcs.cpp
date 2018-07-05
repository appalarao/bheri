#include<iostream>
#include<vector>
using namespace std;

class lcs_1
{
public:
void fun(char *x,char *y,int l1,int l2)
{

	int a[l1+1][l2+1]={0},i,j;

	for(i=0,j=0;i<l1||j<l2;i++,j++)
	{
		a[i][0]=0;
		a[0][j]=0;
	}

	for(i=1;i<l1+1;i++)
	{
		for(j=1;j<l2+1;j++)
		{
			if(x[i-1]==y[j-1])
			{
				a[i][j]=a[i-1][j-1]+1;
			}	
			else
			{
				if(a[i-1][j]>a[i][j-1])
					a[i][j]=a[i-1][j];
				else	
					a[i][j]=a[i][j-1];
			}
		}
	}	
cout<<"result is --------"<<a[l1][l2]<<endl;
cout<<"\n------------mat is--------\n";
for(i=0;i<l1+1;i++)
{
        for(j=0;j<l2+1;j++)
                cout<<a[i][j]<<"\t";
        cout<<endl;
}

vector<char> v;
	i=l1;
	j=l2;
	while(i>=0||j>=0)
	{
		if(x[i-1]==y[j-1])
		{
			v.push_back(x[i-1]);
			i=i-1;
			j=j-1;
		}
		else if (a[i-1][j]>a[i][j-1])
			i--;
		else
			j--;
		
	}

vector<char>::iterator itr;

for(itr=v.end();itr!=v.begin()-1;itr--)
	cout<<*itr<<"\t";
}
};
int main()
{
	char x[]={'a','b','d','a','b','c'};
	char y[]={'f','d','e','b','c'};
	try
	{
		lcs_1 d;
		d.fun(x,y,6,5);
	}catch(...)
	{
		cout<<"exception caught"<<endl;
	}
	return 0;
}
