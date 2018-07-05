#include<iostream>
#include<list>
using namespace std;
int main()
{
list <int> l;
list<int>::iterator itr;
l.push_back(1);
l.push_back(2);
for(itr=l.begin();itr!=l.end();itr++)
        cout<<*itr<<"\t";
return 0;
}

