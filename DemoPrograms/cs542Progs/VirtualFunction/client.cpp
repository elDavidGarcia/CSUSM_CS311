
// this demo program shows how inheritance and virtual functions work
// when you do not use pointers to objects 
 

#include "girl.h"
#include <iostream>

// girl inherits from person

int main()
{

  // Even with the virtual function doit, we get the same 
  // result as with a regular function doit 

  girl G;    // calls person const first before girl const 
  G.doit();  // girls doit is called

  person P;
  P.doit();  // persons doit is called

  P = G;  //   person gets girl works!
          //   but girl gets person does NOT work  
  P.doit();  // persons doit is called because P's type is person 

  // now P is destroyed  (person destructor)
  // then G is destroyed (girl destructor and then person destructor)
}
