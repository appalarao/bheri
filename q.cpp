#include<iostream>
#include<stack>
using namespace std;
stack<int> s1;
stack<int> s2;
void add(int i)
{
s1.push(i);
}
int del()
{
while(!s1.empty())
{
int i=s1.top();
s1.pop();
s2.push(i);
}
int y=s2.top();
s2.pop();
return y;
}
int main()
{
add(1);
add(2);
add(3);
int val=del();
cout<<"\n value is ------"<<val<<endl;
 val=del();
cout<<"\n value is ------"<<val<<endl;
 val=del();
cout<<"\n value is ------"<<val<<endl;

return 0;
}
