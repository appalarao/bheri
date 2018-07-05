#include<iostream>
#include<list>
#include<vector>
#include<map>
using namespace std;
int main()
{
int v1,v2,weight;
vector< list< pair<int, int> > > arr(6);
 for (int i = 1; i <= 5; ++i) {
          cin>>v1>>v2>>weight;
        arr[v1].push_back(make_pair(v2, weight));
        arr[v2].push_back(make_pair(v1, weight));
    }
for (int i = 1; i < arr.size(); ++i) {
       cout<<"\n adjacencyList["<<i<<"] ";
          
        list< pair<int, int> >::iterator itr = arr[i].begin();
          
        while (itr != arr[i].end()) {
            cout<<" -> "<<(*itr).first<<"("<<(*itr).second<<")"<<"\t";
            ++itr;
        }
       cout<<endl;
    }


return 0;
}
