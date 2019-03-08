
// this demo program shows how inheritance and virtual functions work
// when you use pointers to objects

#include "girl.h"
#include <iostream>

// girl inherits from person

// With a pointer and a virual function, we get different results **
// What the pointer goes to is checked
int main()
{
  girl *G;   // G is now a pointer to a girl object
  G = new girl;
  G->doit();  // girls doit is called

  person *P;  // P is now a pointer to a person object
  P = new person;
  P->doit();  // persons doit is called

  P = G;  //   person gets girl works!
          //   but G = P does NOT work  
  P->doit();  //** girl doit is called because P points to a girl!!!!
  (*P).doit();  // ** girl doit is called

  // ** desctructors are not called
}
