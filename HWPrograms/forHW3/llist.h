//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P2 slist
// Your name: David Garcia
// Compiler:  g++ 
// File type: header file of llist
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be **

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected://Updated to protected for slist 
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes in list
  
 public:

  // Exception handling classes 
  class Underflow{};   //throws underflow when there are no elements in the list
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //PURPOSE: Checks if Front & Rear = NULL & Count = 0. If true, returns (true
  //         as the list is empty) else returns false (There are elements inside)
  bool isEmpty();
    
  //PURPOSE: Dispalys all elements in the list. If empty displays "[ empty ]"
  void displayAll();

  //PURPOSE: Adds elememt in the front of the list, and moves front pointer to new node.
  //Parameters: Pass the element (by value) you wish to add to the front of the list 
  void addFront(el_t);
    
  //PURPOSE: Adds elememt in the rear of the list, and moves rear pointer to new node.
  //PARAMETERS: Pass the element (by value) you wish to add to the rear of the list 
  void addRear(el_t);

  //PURPOSE: Gives the element in the front back to client, deletes the front node after 
  //         and moves front pointer to next node.
  //PARAMETERS: Give a location where the element is stored to pass back to the 
  //            client (by reference)
  void deleteFront(el_t&);
    
  //PURPOSE: Gives the element in the rear back to client, deletes the rear node after 
  //         and moves rear pointer to next node.
  //PARAMETERS: Give a location where the element is stored to pass back (by reference)
  //            to the client 
  void deleteRear(el_t&);
    
  //PURPOSE: Looks for a position (given by the client) and deletes the node found in 
  //         that position, once it deletes the node it bypasses the node so it does not 
  //         have an empty node 
  //PARAMETERS: Pass the position that is to be deleted and a  location where the element 
  //            is stored to pass back (by refrence) to the client
  void deleteIth(int, el_t&);

  //PURPOSE: Looks for a position (given by the client) and integrates a node in front 
  //         of given position
  //PARAMETERS: Pass the position that the new node is going infront of and a location 
  //            where the element is stored to pass back (by refrence) to the client    
  void addbeforeIth(int, el_t);
    
};//End of header file
