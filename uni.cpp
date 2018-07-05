#include<iostream>
using namespace std;
 
class S
{
   int *ptr;  // Actual pointer
public:
   // Constructor: Refer http://www.geeksforgeeks.org/g-fact-93/
   // for use of explicit keyword 
   explicit S(int *p = NULL) { ptr = p; } 
 
   // Destructor
   ~S() { delete(ptr); }  
 
   // Overloading dereferencing operator
  int &operator +() {  return *ptr; }
};
 
int main()
{
    S ptr(new int());
    +ptr = 20;
    cout << +ptr;
 
    // We don't need to call delete ptr: when the object 
    // ptr goes out of scope, destructor for it is automatically
    // called and destructor does delete ptr.
 
    return 0;
}
