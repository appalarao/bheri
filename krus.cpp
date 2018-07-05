#include<iostream>
#include<map>
using namespace std;
typedef struct edge
{
int src,dest;
int wt;
}edge;
edge arr[10];

struct dset
{
int rank;
edge data;
struct dset* parent ;
}dset;
map<edge, dset * >

void makeset(edge e)
{
dset *node=new dset;
node->data=e;
node->rank=0;
node->parent=node;
m.insert(makepair<e,node>);
}


dset * findset(dest * e)
{
 if(e->parent==e)
	return e;
  e->parent=findset(e->parent);
  return e.parent;
}

void unin(edge e1,edge e2)
{
   dset *n1=m.find(e1);
   dset *n2=m.find(e2);
   dset *p1=findset(n1);
   dset *p2=findset(n2);
   
   if(p1==p2)
   {
	return;
   }
   else
   {
	if(p1->rank>=p2->rank)
        {
		p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
		p2->parent=p1;
	}
	else
	{
		p1->parent=p2;
	}
   }
}

void krusk()
{

int i;
for(i=0;i<10;i++)
	makeset(arr[i]);


}


