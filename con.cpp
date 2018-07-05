#include<iostream>
using namespace std;
class A
{
public:
int a;
	A()
	{
		cout<<"\n-A--1-\n";
	}
	A(int a)
	{
		cout<<"A--2-"<<a<<endl;
	}
	A(const A &obj)
	{
		a=obj.a;
		cout<<"\nA-3 "<<a<<endl;
	}
	void fun()
	{
		cout<<"\n fun in base class--\n";
	}
	~A()
	{
		cout<<"A--4--\n";
	}
};
class B: public A
{
public: int b;
	B()
	{
		cout<<"\n--B--1-\n";
	}
	B(int b)
	{
		cout<<"\n-B--2-"<<b<<endl;
	}
	B(const B &o)
	{
		b=o.b;
		cout<<"\n-B--3-"<<b<<endl;
	}
	~B()
	{
		cout<<"\n-B--4-\n";
	}
};
int main()
{
//B obj1(10);
B obj;//=new B;
obj.fun();
} 
