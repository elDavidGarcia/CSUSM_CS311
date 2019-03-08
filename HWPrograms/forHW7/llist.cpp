//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//  DO NOT DELETE my descriptions but USE them.
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: David Garcia
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;//No need to put std:: in front of everything

#include<iostream>//To display things on the screen
#include"llist.h" //Include header file

//Constructor
//PURPOSE: Initialize Front and Rear to be NULL and Count = 0.
//         This does not create any node.  The new list is empty.
llist::llist()
{
  Front = Rear = NULL; //sets both front and rael equal to NULL when constructing the list
  Count = 0; //Sets llist counter equal to zero when constructing the list
  cout << "...in the llist Conctructor\n";
}//Close: Constructor  

//Destructor
//PURPOSE: Deconstructs list made 
//ALGORITHIM: While the list is not empty, call deleteFront to delete all nodes.
//            Please place a cout in this function "calling the llist desctructor."
llist::~llist()
{
  el_t x; //Variable to hold elememts passed back from deleteFront()
  while(!isEmpty()) deleteFront(x); //Deletes everything inside the list one by one
  cout << "...in the llist Destructor\n"; //Let user know desctructor was called
}//Close: destructor

//PURPOSE: Returns true if Front and Rear are both pointing to NULL and Count is 0.
//(all 3 conditions must be checked)
bool llist::isEmpty()
{
  if(Front == NULL && Rear == NULL && Count == 0) return true; //If there is nothing in the list
  else return false;
}//Close: isEmpty()

/* Sensei's Notes for displayAll()
Special case: if the list is empty, display [ empty ] ).
Regular: displays each element of the list horizontally starting from Front in [ ].*/

//PURPOSE: Displays all elements in the list inside a brackets "[]" 
//ALGORITHYM: If the list is empty it displays "[ empty ]", else if there are elements it 
//            displays the elements one by one using a for loop, setting pointer P equal to 
//            Front and while P is not Null (meaning its at the end of the list) it displays
//            the current P's element and moves P to the next Node.
void llist::displayAll()
{
  if(isEmpty()) cout << "[ empty ]\n"; //List is empty so display it to the user
  else //List has some elements inside 
    {
      cout << "[ "; //Start the bracket container
      Node *P = Front; //Pointer that is set to the Front so that Front is not moved
      for(P; P != NULL; P = P->Next) //Loop goes through the list one by one
	cout << P->Elem << " "; //Displays the current element inside the P element
      cout << "]"; //Close the bracket container
    }//Close: else
}//Close: displayAll()

/*Sensei's Notes for addRear()
  2 cases:
  - Special case: if this is going to be the very first node, you must
  create a new node and make Front and Rear point to it. Place NewNum and
  Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
  of this new node. Count is updated.

  if (// special case)
  {}
  else
  {
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    }*/

//PURPOSE: Adds elememt in the rear of the list
//PARAMETERS: Pass the element (NewNum by value) that is to be added to the rear of the list
//ALGOTRITHYM: If the list is empty (calls isEmpty()) then it makes a new node that front and
//             rear point to, adds the element to the element section of the node, and sets 
//             the Node's next section equal to NULL. If it is not empty then it It makes 
//             rear Next point to a new node, sets rear equal to this new Node, adds an 
//             element to the new Node's element section, and sets Rear's Next equal to 
//             Null. Finally it increments the counter.
void llist::addRear(el_t NewNum) 
{
  if(isEmpty()) //There are no Node's in the linked list
    {
      Rear = Front = new Node; //Make new Node and point to it with Front and Rear
      Rear-> Elem = NewNum; //Pass the element added by client to Rear's Element (also Front's element)
      Rear->Next = NULL; //Set the Rear's Next (also Front's next) to NULL
    }//Close: if(isEmpty())
  else  //There is at least one Node in the linked list
    {
      Rear->Next = new Node; //Make Rear's next point ot a new Node
      Rear = Rear->Next; //Move the Rear pointer to the new Node created
      Rear->Elem = NewNum; //Pass th new element into Rear's Element section
      Rear->Next = NULL; //Set rear's next equal to NULL
    }//Close: else
  Count++; //Increment the list counter by one
}//Close: addRear(el_t NewNum)

/*Sensei's Notes for addFront
2 cases:
- Special case: if this is going to be the very first node, you must
create a new node and make Front and Rear point to it. Place NewNum and
Count is updated.
- Regular: add a new node to the front of the list and
Count is updated.

Regular case:
Node *x;
x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;*/

//PURPOSE: Adds elememt in the front of the list
//PARAMETERS: Pass the element (NewNumby value) that is to be added to the front of the list
//ALGOTRITHYM: If the list is not empty, it must create the first node of the list,
//             it makes Front and Rear equal to a new Node, stores the element passed by 
//             the client in Front's/Rear's new element, and sets Front's/Rear's next 
//             equal to NULL. If it is not empty it makes a new pointer (P) point to a 
//             new Node, set's P's element equal to the element passed by the client, P's
//             next is equal to front, and Front is then equal to P. Finally the list's
//             counter is updated.
void llist::addFront(el_t NewNum)
{
  if(isEmpty()) //Checks if list has any nodes
    {
      Front = Rear = new Node; //Creates new Node and makes front and rear point ot it
      Front-> Elem = NewNum; //Store the element passed by client to Front's Element (also Rear's element)
      Front->Next = NULL; //Make Front's Next (also Rear's Next) equal to NULL
    }//Close: if(isEmpty())
  else //List has at least one Node in linked list
    {
      Node *P = new Node; //Declare a Pointer P that is equal to a new Node
      P->Elem = NewNum; //Store the element passed by the client in P's Element
      P->Next = Front;//Set P's Next equal to Front so it connects P to the rest of the list
      Front = P; //Move Front to P's Node to make it the front of the element again
    }//Close: else
  Count++; //Increment the counter
}//Close: addFront(el_t NewNum)

/*Sensei's Notes on deleteFront() 
  3 cases:
  - Error case: if the List is empty, throw Underflow
  - Special case: if currently only one Node,
  give back the front node element through OldNum (pass by reference) and
  make sure both Front and Rear become NULL. Count is updated.
  - Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
  
  if (//error case)
  {}
  else if {//special case)
  {}
  else
  {
  
  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
  }*/

//PURPOSE: Passes front element back to client then deletes it 
//PARAMETERS: Pass the varable (OldNum by reference) where the element being deleted will 
//            be stored   
//ALGORITHYM: If the Linked list is empty then throw an Underflow exception to let
//            client know a number cannot be added. Else if there is only one Node, set
//            OldNum (storage given by client) equal to the Front's element, delete the 
//            front, and set the Front and Rear Equal to Null. Else if there is more than 
//            one Node store  the front's elements inside Oldum, make a new pointer (P)that 
//            is equal to front, move front to the next node, and delete P pointer. Finally
//            update counter
void llist::deleteFront(el_t& OldNum)
{
  if(isEmpty())throw Underflow(); //If list is empty throw an Underflow exception
  else if(Count == 1) //There is one Node inside the list 
    {
      OldNum = Front->Elem; //Store Front's element inside OldNum to pass back to client
      delete Front; //Delete the front node 
      Front = Rear = NULL; //Set Front & Rear = to NULL (There are no more nodes in the list)
    }//Close: else if(Count == 1)
  else //There are more than one Node 
    {
      OldNum = Front-> Elem; //Store Front's element inside OldNum to pass back to client
      Node *P = Front; //Initialize a new pointer (P) and set it equal to front
      Front = Front-> Next; //Move front to next Node to be able to delete Current
      delete P; // Delete the previous Front Node (P)  
    }//Close: else
  Count--; //Decerement linked list's count
}//Close: deleteFront(el_t& OldNum)

/*Sensei's Notes on deleteRear()
  3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p;
      if (//error case)
        {}
        else if {//special case)
          {}
          else
            {*/

//PURPOSE:Gives the element in the rear back to client, deletes the rear node after and moves
//PARAMETERS: Pass variable (OldNum by reference) to store element that will be deleted
//ALGORITHYM: If the list is empty throw an undeflow exception because the list is empty. If 
//            there is one Node in the list store the rear's element in OldNum (to send back 
//            to client), delete the rear, and set Front and Rear equal to NULL (there are no
//            more Nodes inside the list). If there is more than one Node, store the Rear's
//            element in OldNum, make a new pointer (P) that is equal to front, use the the 
//            pointer P to go throught the list one by one by making a for loop that makes 
//            P equal to the next Node while the Next P is not equal to the rear. When the 
//            loop stops P will be set to Node before Rear, delete rear, make Rear eual to P
//            and Make the Rear's next equal to NULL. Finally decrement counter.  
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty()) throw Underflow(); //Nothing in the list to delete, throw an Underflow
  else if(Count == 1)// There is one Node in the List
    {
      OldNum = Rear->Elem; //Store Rear's element into OldNum to send back to client
      delete Rear; //Delete the rear Node
      Rear = Front = NULL; //Set Rear and Front equal to NULL (No more Nodes in list)
    }//Close: else if(Count ==1)
  else //There is more than one node in the list 
    {
      OldNum = Rear->Elem; //Store Rear's element into OldNum to send back to client
      Node *P = Front; //Initialize a pointer (P) equal to the Front pointer
      for(P; P->Next != Rear; P = P->Next); //Go to the second to last node in the list
      delete Rear; //Delete the rear Node
      Rear = P; //Set Rear equal to P (previous Node)
      Rear->Next = NULL; //Make Rear's next NULL to signify it is the end of the list
    }//Close: Else
  Count--; //Decrement List's counter
}//Close: deleteRear(el_t& OldNum)

/*Sensei's Notes on deleteIth 
  4 cases:
- Error case:
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>*/

//PURPOSE: Looks for a position (given by the client) and deletes the node 
//         found in that position
//PARAMETERS: Pass the position (I) that is to be deleted and a location 
//            where the element is stored (OldNum) to pass back 
//            (by refrence) to the client
//ALGORITHYM: If the position I is less than the range (Range is 1 - Count) 
//            throw a OutOfRange exception. Else  I is equivalent to one 
//            it is refering to the first Node so delete front Node by 
//            calling the deleteFront() function. Else if I is equivelent 
//            to count then it is refering to the last node so delete it 
//            by calling deleteRear() function. Else if I is in between one
//            and count then it is refering to one of the middle nodes so to
//            find which one it is refering to, make a for loop that makes 
//            P equal to the next node while decrementing I until I is no 
//            longer greater than 1 meaning that it will move the p pointer 
//            to the position of the node that is before the Node that is to
//            be deleted. Once there initialize a new pointer (Q) which will
//            will equal the node that is going to be deleted, the Node after 
//            the Node P is pointing to. Then make P's next point to two Nodes
//            ahead so it can bypass the Node that is to be deleted, meaning that
//            it can safely be recycled after storing Q's elements insde OldNum to
//            send back to the client. Finally update counter. 
void llist::deleteIth(int I, el_t& OldNum)
{
  if(I < 1 || I > Count) throw OutOfRange();//Position is not in the range, throw Underflow
  else if(I == 1) deleteFront(OldNum);//Refers to first Node in list, delete front Node 
  else if(I == Count) deleteRear(OldNum);//Refers to the Last Node, delete Rear Node
  else//Position refers to one of the middle nodes
    { 
      Node *P = Front;//Initialize P to equal Front
      for(P, I; I > 2; P = P->Next, I--);//Stop at the Node before the one to be deleted
      Node *Q = P->Next;//Initalize Q to Node that will be deleted
      P->Next = P->Next->Next; //Make P's Next point 2 Nodes ahead, bypassing Q
      OldNum = Q->Elem;//Store Q's element in Old Num to pass back to client
      delete Q;//Safely recycle Q
      Count--;//Decrement count
    }//Close: Else
}//Close: deleteIth(int I, el_t& OldNum)

/*Sensei's Notes on addbeforeIth()
  4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>*/

//PURPOSE: Looks for a position (given by the client) and integrates a node in front 
//         of given position
//PARAMETERS: Pass the position (I) that the new node is going infront of and a location 
//            where the element is stored to pass back (by refrence) to the client
//ALGORYTHYM: If the position passed is greater less than 1 or the position is 
//            greater than one more than count (*count+1 is in the range beacuse this 
//            would mean client wants to add to the end of list) then throw an out of range 
//            exception. If position is one it is refering to the first Node so call the
//            add to front function else if position is equevalent to count plus one, then 
//            the client wants to add to the rear of the list so call add to rear function.
//            If it is none of these then it is refering to a Node in the middle so 
//            initialize a pointer (P) equal to front (use this one to go throught the list)
//            and another pointer to a new Node. Make the P pointer go through the linked
//            list until it reaches the Node previous to the one declared by the position
//            by using I as a counter and decrementing as long as it's greater than two.
//            Next make Q's next equal to P's next and P's next point to Q (this integrates)
//            Q into the Linked list. Store the new element passed by the client into Q's
//            element space and increment the counter.
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I < 1 || I > (Count+1)) throw OutOfRange();//Not in Range so let the client know
  else if(I == 1) addFront(newNum);//Refers to the first Node,call delete front 
  else if(I == (Count+1)) addRear(newNum);//Refers to the last Node, call delete rear
  else//Position refers to a middle node
    {
      Node *P = Front;//Pointer will go to position in list
      Node *Q = new Node;//Pointer will be new Node to be integrated in list
      for(P, I; I > 2; P = P->Next, I--);//Make P go to Node before given position
      Q->Next = P->Next;//Set Q's next equal to P's Next to start integration of Q 
      P->Next = Q;//Make P's Next point to Q, this fully integrates Q in the list 
      Q->Elem = newNum;//Add element given by client in Q's element section
      Count++;//Increment counter
    }//Close: else
}//Close: addbeforeIth(int I, el_t newNum)

//End of Implementation File :)
