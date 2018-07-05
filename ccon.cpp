#include<iostream>
using namespace std;
class Hai
{
int i;
public:
	Hai(int i)
	{
		this->i=i;
		cout<<"\n-----nor const val is "<<this->i<<"\n";
	}
virtual Hai(const Hai &obj)
{
this->i=obj.i;
cout<<"\n------copy constructor-----\n"<<endl;
cout<<"\n--val in c con is "<<this->i<<endl;
}
};
class Hello:public Hai
{
	int j=20;
	Hai(const Hai &obj)
	{
		cout<<"\n virtual constructor "<<endl;
	}
};
int main()
{
Hai o1(10);
Hai * o2(o1);
Hello he;
o2=&he;
return 0;
}
