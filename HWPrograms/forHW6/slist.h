//=========================================================
//HW#: HW3P3 slist
//Your name: David Garcia
//Complier:  g++
//File type: slist header file
//===========================================================
#include "llist.h"//have to include llist for inheritance

//slist inherits everything from llist and adds a search and replace function.
class slist: public llist//Public so client can use functions in llist
{
 public:
  //PURPOSE:constructor of slist
  slist();
  //PURPOSE: Copy constructor to be called when a linked list is passed by
  //        value. Makes a copy of original list. 
  //PARAMETERS: Pass original list by reference (do not modify original 
  //            so make it constant)
  slist(const slist&);
  //PURPOSE: Overloads equals operator so that you can use "=" to set the 
  //         elements in a linked list equal to another linked list's 
  //         elements.
  //PARAMETERS: Pass original list by reference (do not modify original
  //            so make it constant). The other will be passed by refrence
  //            as well when it calls the function. 
  slist& operator=(const slist&);
  //PURPOSE: Overloads the equivalent operator to check if two linked
  //         list are equal to one and other, returns true or false.
  //PARAMETERS: Pass one of the  list by reference (do not modify original
  //            so make it constant). The other will be passed by refrence 
  //            as well when it calls the function.
  bool operator==(const slist&);
  //PURPOSE: Search through the list to see if any node contains the key.
  //         If so, return its position (>=1). Otherwise, return 0.
  //PARAMETERS: Pass element to be searched by value.
  int search(el_t);
  //PURPOSE: Go to the Ith node (if I is between 1 and Count) and
  //         replace the element there with the new element.
  //         If I is an illegal value, throw OutOfRange.
  //PARAMETERS: Pass the new element (by value) that will replace current 
  //            element and position (by value) of the current element  
  void replace(el_t, int);
};//Close: class slist: public llist

//end of slist.h
