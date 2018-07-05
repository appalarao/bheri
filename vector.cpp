#include<iostream>
#include<vector>
using namespace std;

class Vector 
{
public:
	void insert(vector<int> *,int);
	void disp(vector<int>);
};
void insert(vector<int> *vect,int data)
{
vect->push(data);
}
void disp(vector<int> vect)
{
cout<<vect.size()<<endl;
}
int main()
{
Vector obj;
vector<int> vect;
obj.insert(&vect,10);
obj.disp(vect);
return 0;
}

