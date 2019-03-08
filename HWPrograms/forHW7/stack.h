// =======================================================
// HW#: HW1P1 stack
// Your name: David Garcia
// Compiler:  g++ 
// File type: header file for stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef char el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
  el_t     el[MAX];       // el is  an array of el_t's
  int      top;           // top is index to the top of stack
  
 public: // prototypes to be used by the client
  // Note that no parameter variables are given
  
  // exception handling classes  
  class Overflow{};   // thrown when the stack overflows
  class Underflow{};  // thrown when the stack underflows
  
  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
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
  //PARAMETER: N/A
  bool isEmpty();
  //PURPOSE: If stack reaches MAX size returns true else
  //         returns false.
  //PARAMETERS: N/A
  bool isFull();
  //PURPOSE: Displays the contents of the stack from most
  //         recent element added on top and oldest element
  //         added on the bottom
  void displayAll();
  //PURPOSE: Clears all element of stack making count 0 again
  void clearIt();
};  

// Note: semicolon is needed at the end of the header file

