//=========================================================
//HW#: HW1P2 vector stack
//Your name: David Garcia
//Complier:  g++
//File type: vector stack implementation file
//=========================================================

using namespace std;

#include <iostream>
#include "vstack.h"

//PURPOSE: Nothing to initialize because using vector class
stack::stack()
{
}

//PURPOSE: Clear the vstack to release the stored data, uses 
//         clear function in vector library.
stack::~stack()
{ 
  el.clear();
}

//PURPOSE:  Checks vector size and returns true if empty, 
//          false otherwise. The stack is empty if size equals 0.
//          Uses size from vector class.
bool stack::isEmpty()
{ 
  //If size is 0 it means there is no elements in stack
  if (el.size() == 0) return true;
  
  //Size is not 0 which means there is elements in the stack
  else return false; 
}

//PURPOSE: Adds elem to "top" of the stack by using 
//         push_back function in vector library. Cannot
//         overflow as it is using a vector which can grow in size.
//PARAMETER: Provide the element (elem) being pushed in stack.
void stack::push(el_t elem)
{ 
  el.push_back(elem); //Pushes elem into vector stack using existing function   
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
  //If it's empty there is nothing to pop, throw an Underflow exception
  if(isEmpty()) throw Underflow();
  
  //There is something to pop in the stack so store the top
  //element inside elem to pass by refrence and call function
  //pop_back from vector library. Use size-1 to get top slot 
  else 
    { 
      elem = el[el.size()-1]; //Store top elem in elem
      el.pop_back(); //Remove the top elem
    }
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ 
  //If it's empty there is nothing to return, throw an underflow exception
  if(isEmpty()) throw Underflow();

  //There is at least one element in stack, return the top element
  //by storing in elem and pass by refrence. Use size-1 to get top slot.
  else elem = el[el.size()-1]; 
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGORITHM: Uses for loop to display contents of vector one by one
//           by going through each slot and displaying them on the screen
void stack::displayAll()
{  
  //If it's empty display empty 
  if (isEmpty()) cout << ".[ empty ].\n";

  //There are one or more elements inside the stack. Display them one  by one 
  //by setting a new int variable (i) equal to size-1 and decrement until it 
  //gets to zero. Use the same variable to display the content of array.
  else for (int i= (el.size()-1); i>=0; i--) cout << el[i] << endl;
  cout << "--------------\n";
}

 
//PURPOSE: Clears the vstack using clear function in vector library
void stack::clearIt()
{
  el.clear();
}


