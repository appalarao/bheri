#include<iostream>
#include<stack>
using namespace std;


class Stack
{
	public:
		void insert(stack<int> *,int);
		void disp(stack<int>);
};
void Stack::insert(stack<int> *s,int data)
{
	s->push(data);
}
void Stack::disp(stack<int> s)
{
	cout<<"size is "<<s.size()<<endl;
	cout<<"top is "<<s.top()<<endl;
}

int main()
{
	Stack obj;
	stack<int> s;
	obj.insert(&s,1);
	obj.insert(&s,2);
	cout<<"top is "<<s.top()<<endl;
	obj.disp(s);
	return 0;
}
