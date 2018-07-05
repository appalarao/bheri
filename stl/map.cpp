#include<iostream>
#include<map>
using namespace std;
int main()
{
map <int,int> m;
map<int,int>::iterator itr;
m.insert(pair<int,int> (1,50));
m.insert(pair<int,int> (2,70));
m.insert(pair<int,int> (2,60));
m.insert(pair<int,int> (4,50));//fine
m.insert(pair<int,int> (3,80));
cout<<"\n map size is "<<m.size()<<endl;
for(itr=m.begin();itr!=m.end();itr++)
        cout<<itr->first<<"\t"<<itr->second<<endl;

m.erase(2);
cout<<"\n map size is "<<m.size()<<endl;
for(itr=m.begin();itr!=m.end();itr++)
        cout<<itr->first<<"\t"<<itr->second<<endl;


return 0;
}


