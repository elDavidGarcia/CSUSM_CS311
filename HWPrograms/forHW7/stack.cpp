//=========================================================
//HW#: HW1P1 stack
//Your name: David Garcia
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;

#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ 
  top = -1; // indicate an empty stack 
}

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ // nothing to do 
}

//PURPOSE:  Checks top and returns true if empty, false otherwise.
//          The stack is empty if top is set to -1.
bool stack::isEmpty()
{ 
  //If top is -1 it means there is no elements in stack
  if (top == -1) return true;
  
  //Top is not -1 which means there is elements in the stack
  else return false; 
}

//PURPOSE: Checks top and returns true if full, false otherwise.
//         If top is one less than the MAX then it means stack is
//         full.
bool stack::isFull()
{ 
  //If top is equal to MAX-1 then stack is full 
  if (top == MAX-1) return true; 
  
  //Top is not equal to MAX-1 so there is still room
  else return false; 
}

//PURPOSE: Calls isFull and if true, throws an exception (Overflow)
//         otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
  //If it's full you cannot add anymore elements so throw an overflow
  if(isFull()) throw Overflow();
  
  //You can still add elements, increment top and add element 
  //inside the new slot 
  else 
    { 
      top++; //incrementing counter
      el[top] = elem; // Storing new element in new slot
    }
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
  //If it's empty there is nothing to pop, throw an Underflow exception
  if(isEmpty()) throw Underflow();
  
  //There is something to pop in the stack so store the top
  //element inside elem to pass by refrence and decrease counter
  else 
    { 
      elem = el[top]; //Store top elem in elem
      top--; //Decrease counter
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
  //by storing in elem and pass by refrence
  else elem = el[top]; 
}
 
//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGORITHM: Uses for loop to display contents of array one by one
//           by going through each slot and displaying them on the screen
void stack::displayAll()
{  
  //If it's empty display empty 
  if (isEmpty()) cout << ".[ empty ].\n";

  //There are one or more elements inside the stack. Display them one  by one 
  //by setting a new int variable (i) equal to top and decrement until it 
  //gets to zero. Use the same variable to display the content of array.
  //Don't use top so that you don't mess with the top position in array.
  else 
    for (int i=top; i>=0; i--) cout << el[i] << endl;
  cout << "--------------\n";
}

 
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//ALGORITHM: While the top is not equal to -1, which would make it empty.
//Use pop function to decrement top and "clear" the stack.
void stack::clearIt()
{
  el_t temp;//Temp will be used to store item poped when clearing stack
  while(top > -1) pop(temp);
}


