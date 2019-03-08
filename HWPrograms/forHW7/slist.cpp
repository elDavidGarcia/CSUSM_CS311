//=========================================================
//HW#: HW3P3 slist
//Your name: David Garcia
//Complier:  g++
//File type: slist implementation file
//===========================================================
#include "slist.h"//Only include slist, no need for llist
#include <iostream>
using namespace std;

//PURPOSE: Constructor of slist, sets Front and rear equal to NULL to indicate
//         an empty list and makes count equal to zero  
slist::slist()
{
  Front = Rear = NULL;
  Count = 0;
}

//PURPOSE: Copy constructor to be called when a linked list is passed by
//        value. Makes a copy of original list.
//PARAMETERS: Pass original list by reference (do not modify original
//            so make it constant)
//ALGORITHYM: First initialize the new List's Front(NULL), Rear(NULL), and Count(0). 
//            Then initialize a pointer (P)to the original's front so that the original
//            list stays intact. Make P go throught the original List while it adds
//            each element at the P node (using add rear function of the new list and
//            P's element that points to the contents in original list). 
slist::slist(const slist& Original)
{
  this->Front = this->Rear = NULL;//New list's Front and Rear equal NULL (empty list)
  this->Count = 0; //New list's count equal to zero (empty list)
  Node *P = Original.Front;//Pointer P will point to original list's Front
  //Go through original list and copy elements to new list
  for(P; P != NULL; P = P-> Next) this->addRear(P->Elem);
}//Close: slist::slist(const slist& Original)

//PURPOSE: Overloads equals operator so that you can use "=" to set the
//         elements in a linked list equal to another linked list's
//         elements. Returns copied list.
//PARAMETERS: Pass original list by reference (do not modify original
//            so make it constant). The other will be passed by refrence
//            as well when it calls the function.
//ALGORITHYM: First it checks the addresses of the list to make sure they are not 
//            the same list. If they are not, delete everything from the list that 
//            will be changed ( while the list is not empty, calls list is empty function, 
//            use the delete rear function to clear it). Now that the list is empty 
//            initialize a pointer (P) that is equal to the list that is to be copied 
//            (OtherOne) so that OtherOne list stays intact. Go through the OtherOne 
//            list using P and copying the elements in the list and storing them into
//            the new list (while P does not equal NULL make P go to next Node and 
//            use the new list's add rear function to store P's element. After the 
//            if statement return the list this-> unconditionally points to, even if 
//            it didn't go throught the if statement
slist& slist::operator=(const slist& OtherOne)
{
  if(&OtherOne != this)//compares addresses of the two list
    {//List are not the same so go through if statement
      el_t x;//To be used when deleteRear is called
      while(!this->isEmpty()) this->deleteRear(x);//Clear elements in this list
      Node *P = OtherOne.Front;//Initialize P to OtherOne's front
      //Go throught OtherOne list, using P, and copy elements to new list
      for(P; P != NULL; P = P-> Next) this->addRear(P->Elem);
    }//Close: if(&OtherOne != this)
  return *this;//return result unconitionally
}//Close: slist& slist::operator=(const slist& OtherOne) 

//PURPOSE: Overloads the equivalent operator to check if two linked
//         list are equal to one and other, returns true or false.
//PARAMETERS: Pass one of the  list by reference (do not modify original
//            so make it constant). The other will be passed by refrence
//            as well when it calls the function.
//ALGORITHYM: First check both list's size, if they are not the same size return
//            false as they cannot be the same if they are diffrent sizes. If they 
//            are the same size inialize a pointer (F) for the "First List" (being
//            pointed by this->) and another pointer (P) for SecondList (This keeps 
//            both list's front pointer intact). Make a for loop that moves both 
//            pointers F and P through both list checking their elements with an if
//            statement, returning false if the elements are not equal. If all the 
//            elements are equal it will get out of the for loop without returning
//            false, so return true, as the list are equivalent.
bool slist::operator==(const slist& SecondList)
{
  if(this->Count != SecondList.Count)return false;//Not the same size = not the same
  else //Lists are the same size, need to compare lists' contents  
    { 
      Node *F = this->Front; //Initialize F pointer to "First" list's front
      Node *P = SecondList.Front;//Initalize P pointer to SecondList's front
      //Go through both list, using F and P, moving both pointers to next Node
      for(F,P; F != NULL || P != NULL; F = F->Next, P = P->Next)
	if(F->Elem != P->Elem)return false;//If an element does not match, return false
      return true;//Size and all elements are the same, return true :)
    }//Close: else 
}//Close: bool slist::operator==(const slist& SecondList) 

//PURPOSE: Search through the list to see if any node contains the key.
//         If so, return its position (>=1). Otherwise, return 0.
//PARAMETERS: Pass element to be searched by value.
//ALGORYTHIM: Sets a new pointer (P) equal to front and intializes the position
//            counter (i) (that will be passed back to client). It use s P to go 
//            through the list, incrementing i and moving the P pointer to the next
//            Node, until either it returns position to client or it goes through
//            the whole list(P would equal NULL). If it goes through the whole list
//            without returning to client then return 0 because number was not found.  
int slist::search(el_t key)
{
  Node *P = Front;//Initialize pointer P to Front
  int i = 1;//Position/counter that will be passed back o client if number is found
  for(P,i; P != NULL; P = P->Next, i++)//Go through all Nodes in the list, increment i
    if(key == P->Elem) return i;//Element was found, return position (i)
  return 0;//Element was not found return a zero
}//Close: search(el_t key)

//PURPOSE: Go to the Ith node (if I is between 1 and Count) and
//         replace the element there with the new element.
//         If I is an illegal value, throw OutOfRange.
//PARAMETERS: Pass the new element (newNum by value) that will replace current
//            element and position (I by value) of the current element
//ALGORYTHIM: Check if position passed by client is in range, if it is not throw 
//            an out of range exception. If the position is in range, initialize a 
//            pointer (P) that is equal to Front. Make it go to the position given
//            by decrementing I until it is no longer greater than 1 so that it 
//            makes the P pointer (P is also moving by making it equal to the next 
//            Node every time it goes through the loop) point to the Node with given 
//            position. Then replace the old element with the new by setting P's 
//            element equal to newNum. 
void slist::replace(el_t newNum, int I)
{ //If position is not in range, throw Underflow
  if(I < 1 || I > Count) throw OutOfRange();
  else{//Position is in Range
    Node *P = Front;//New pointer P is set equal to Front 
    for(P, I; I > 1; P = P->Next, I--);//Go through list to find position
    P->Elem = newNum;//Replace the old element with the new one
  }//Close: else
}//Close: replace(el_t newNum, int I)

//End of Implementaion file 
