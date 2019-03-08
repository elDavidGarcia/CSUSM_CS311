// Note: Any attempt to follow a dangling pointer will cause a 
// segmentation fault.
// In some cases, it takes a while before the system realizes that
// the pointer is dangling.  
// Any acess to a non-existing cell will cause
// a segmentation fault.

// What will this do?  Try on empress and then on your PC

#include <iostream>
using namespace std;

int main()
{
  int *P;
  
  P = new int;
  cout << "Address of existing pointer: " << P << endl;
  delete P;

  cout << "Adress of deleted pointer: " << P << endl;

  P = NULL;

  cout << "Adress of NULL pointer: " << P << endl;
  
  *P = 3;  // going to a non-existing cell 

  cout << "Value of non-exisiting cell: " << *P << endl;
}
