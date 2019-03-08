
// this demo program shows how inheritance and virtual functions 
// lead to a reusable program
 
#include "girl.h"
#include "boy.h"
#include <iostream>

// girl inherits from person
// boy inherits from person

// this function is independent of girl or boy
// and thus is re-usable
int general(person* P)
{
  P->doit();
}


int main()
{
  person* P = new girl;
  person* Q = new boy; 

  general(P);  // girls doit is called
  general(Q);  // boy doit is called

}
