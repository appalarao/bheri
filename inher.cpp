#include<iostream>
using namespace std;
class Base
{
//public:
//int aa=10;
private:
int x;
public:
void fun()
	{
		int i=10;
//		aa=a;
//		cout<<"\nvalue of a is "<<aa<<endl;
//		cout<<"\naddess of base a is "<<&aa;
	}
};
class Deriv:public Base
{
int bb;
public:
void fun()
	{
	int j=20;
//		bb=b;
//		cout<<"\nvalue of b is "<<bb<<endl;
//		cout<<"\naddess of derived b is "<<&bb<<endl;
//		cout<<"\n addess of base(a) in derived is "<<&aa<<endl;
}
};
int main()
{
Base b;
Deriv d;
b.fun();
d.fun();
cout<<"\n-----------\n";
cout<<"\n size of base class is "<<sizeof(Base)<<endl;
cout<<"\n size of derived class is "<<sizeof(Deriv)<<endl;

return 0;
}

