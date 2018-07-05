#include<iostream>
#include<list>
using namespace std;
typedef struct node
{
int key,value
}node;
class map
{
public:
//int size;
list<node> l;
/*map(int size)
{
this.size=size;
}*/
void insert(int k,int v);
int find(int k);
};
void map::insert(int k,int v)
{
l.push_back(k,v);
//l.push_back().value=v;
}
void map::find(int k)
{
}
int main()
{
map m;
m.insert(1,10);
m.insert(2,20);
}
