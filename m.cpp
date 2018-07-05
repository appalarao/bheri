#include<iostream>
#include<map>
using namespace std;
int main()
{
map<int ,char>m;
m.insert(pair<int ,char > (1,'a'));
m.insert(pair<int , char> (2,'b'));
map <int, char > :: iterator i;
    
for (i = m.begin(); i != m.end(); ++i)
{
    cout<<  '\t' << i->first<<'\t'<<i->second<<'n';
}
//cout<<"1 value is "<<m.count()<<"\n";
return 0;
}
