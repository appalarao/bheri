#include<iostream>
#include<queue>
using namespace std;
int main()
{
priority_queue <int> pq;
pq.push(-1);
pq.push(7);
pq.push(-2);
pq.push(0);
cout<<"count is "<<pq.size()<<endl;
return 0;
}
