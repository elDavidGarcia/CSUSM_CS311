
#include "girl.h"
#include <iostream>

// This demo program demostrates how pointers and references work
// with objects
int main()
{

  girl G;    // calls person const first before girl const 

  girl* F;  // F is a pointer to an girl object

  // *F = G;    causes segmentation fault but
  F = new girl;  // F does point to something - new returns a pointer
  *F = G;        // so where it points can now be assigned G

	       cout << "hello" << endl;

  //  F = G;   mismatch  pointer = object
  F = &G;       // works because &G is an address

  F->doit();
  
  // destructor is called for G
}
