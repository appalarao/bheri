#include<iostream>
#include<set>
using namespace std;
int main()
{
multiset <int> s;
multiset <int>::iterator itr;
s.insert(1);
s.insert(2);
s.insert(3);
s.insert(4);
cout<<"\n set size is "<<s.size()<<endl;
for(itr=s.begin();itr!=s.end();itr++)
        cout<<*itr<<endl;

/*m.erase(2);
cout<<"\n map size is "<<m.size()<<endl;
for(itr=m.begin();itr!=m.end();itr++)
        cout<<itr->first<<"\t"<<itr->second<<endl;
*/

return 0;
}
