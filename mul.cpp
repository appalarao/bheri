#include<iostream>
using namespace std;
class Mul
{
public :
virtual void fun(){}
};
class Mul_1:public Mul
{
private:
	void fun()
	{
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int b[3][2]={0,1,1,0,0,1};
	int c[3][2]={0};
	int i,j,k,sum=0;
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	{
		sum=0;
		for(k=0;k<3;k++)
		{
			sum+=a[i][k]*b[k][j];
		}
		c[i][j]=sum;
	}
	}
	cout<<"\n=====res====\n";
	for(i=0;i<3;i++)
	{
	for(j=0;j<2;j++)
	{
	cout<<c[i][j]<<"\t";
	}
	cout<<endl;
	}
	}
};
class Dummy:public Mul
{
private:
	void fun()
{
cout<<"\n---------vir--\n";
}
};
int main()
{
Mul *ptr;
Mul_1 obj;
ptr=&obj;
ptr->fun();
Dummy dum;
ptr=&dum;
ptr->fun();
return 0
