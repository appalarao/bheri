#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct node
{
int st,ed,pf;
}node;

bool comp(vector<node> v1,vector<node> v2)
{
return v1.ed<v2.ed;
}
int main()
{
vector<node> v;
vector<node>::iterator itr;
v.insert(1,3,20)
v.insert(4,8,10)
v.insert(9,7,40)
v.insert(1,3,30)


sort(v.begin,v.end,comp);
for(itr=v.)

}

