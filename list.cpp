#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void reverse(Node **head)
{
Node *fir,*last;
fir=*head;
last=fir->next;
if(last==NULL)
	return;
//if(last->next==NULL)
//	return last;
reverse(&last);

fir->next->next=fir;
fir->next=NULL;
*head= last;
}
 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printlist(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    Node *head1 = newNode(1);
    head1->next = newNode(2);
/*    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = newNode(8);
  */  cout << "Given linked list\n";
    printlist(head1);
  reverse(&head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}
