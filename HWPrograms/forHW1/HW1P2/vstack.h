// =======================================================
// HW#: HW1P2 vector stack
// Your name: David Garcia
// Compiler:  g++ 
// File type: header file for vstack.h
//=======================================================

//----- Globally setting up the aliases ----------------
#include <vector>     //Using the vector class to make stack

typedef int el_t;     // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  std::vector<el_t> el;       // el is a vector of el_t's
  
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: Enters an element at the top
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (pass by ref)
  void pop(el_t&);
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: Return top by pass by refrence
  void topElem(el_t&);
  //PURPOSE: If there are no elements inside returns true else
  //         returns false.
  bool isEmpty();
  //PURPOSE: If not empty displays all contents of stack;
  //         Otherwise displays "[ empty ]"
  void displayAll();
  //PURPOSE: Clears all element of stack 
  void clearIt();
};  

// Note: semicolon is needed at the end of the header file

