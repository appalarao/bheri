#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	set<string> setOfNumbers;
 	set<string>::iterator it;
	// Lets insert four elements
	setOfNumbers.insert("second");
	setOfNumbers.insert("ahird");
	setOfNumbers.insert("first");
	//setOfNumbers.insert("first");
 
	// Only 3 elements will be inserted
	cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;
 
	// Iterate through all the elements in a set and display the value.
	for (it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
	    cout << ' ' << *it;
	cout<<"\n";
	return 0;
}
