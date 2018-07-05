#include<iostream>
#include<vector>
using namespace std;
int main()
{
vector <int> v;
vector<int>::iterator itr;
v.push_back(1);
v.push_back(2);
for(itr=v.begin();itr!=v.end();itr++)
	cout<<*itr<<"\t";
return 0;
}
