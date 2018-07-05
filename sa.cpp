#include<iostream>
using namespace std;
class P
{
	public:
P()
{
	cout<<"\n-parent con--\n";
}
};
class C:public P
{
public:
int a;
	C(int a){
this->a=a;
cout<<"\n---value of a is---- "<<a<<endl;
}
};
int main()
{
C obj(10);
return 0;
}
