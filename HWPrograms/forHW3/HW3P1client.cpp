//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: David Gracia
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

//PURPOSE: Checks the is empty, display all, add rear, 
//         delete front, delete rear, and deconstructor
void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element

  //1 check empty and report the result  
  cout << endl << 1 << endl;
  if(L.isEmpty()) cout << "List is Empty\n";
  else cout << "List is not Empty\n";
  //2 display the list  
  cout << endl << 2 << endl;
  L.displayAll();
  //3 add 4 integers 1,2,3,4    
  cout << endl << 3 << endl;
  L.addRear(1); L.addRear(2); L.addRear(3); L.addRear(4);
  //4 display the list  
  cout << endl << 4 << endl;
  L.displayAll();
  //5 remove from front twice (and display the elements removed)
  cout << endl << 5 << endl;
  L.deleteFront(x); cout << "Removed: " << x << endl;
  L.deleteFront(x); cout << "Removed: " << x << endl;
  //6 display the list
  cout << endl << 6 << endl;
  L.displayAll();
  //7 check empty and report the result 
  cout << endl << 7 << endl;
  if(L.isEmpty()) cout << "List is Empty\n";
  else cout << "List is not Empty\n";
  //8 remove from the rear twice (display the element removed)
  cout << endl << 8 << endl;
  L.deleteRear(x); cout << "Removed: " << x << endl;
  L.deleteRear(x); cout << "Removed: " << x << endl;
  //9 check empty again and report the result
  cout << endl << 9 << endl; 
  if(L.isEmpty()) cout << "List is Empty\n";
  else cout << "List is not Empty\n";
}//end of case 1 
 
//PURPOSE: Checks the add front, delete front, add rear
//         display all, add before Ith, and delete before 
//         Ith, and destructor
void caseTwo()
{ 
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << endl << c << endl; c++;
  L2.addFront(5);
  // 2.add to front again  (element 4)
  cout << endl << c << endl; c++;
  L2.addFront(4);
  // 3.delete Front
  cout << endl << c << endl; c++;
  L2.deleteFront(x); cout << "Removed: " << x << endl;
  // 4.add to rear 3 times (elements 6,8,9)
  cout << endl << c << endl; c++;
  L2.addRear(6); L2.addRear(8); L2.addRear(9);
  // 5. display all
  cout << endl << c << endl; c++;
  L2.displayAll();
  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << endl << c << endl; c++;
  L2.addbeforeIth(1,4);
  cout << "Updated List: "; L2.displayAll();
  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << endl << c << endl; c++;
  L2.addbeforeIth(4,7);
  cout << "Updated List: "; L2.displayAll();
  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << endl << c << endl; c++;
  L2.addbeforeIth(7,10);
  cout << "Updated List: "; L2.displayAll();
  // 9.add before the 9th  (element 12) . error (out of range)
  cout << endl << c << endl; c++;
  try{L2.addbeforeIth(9,12);} 
  catch(llist::OutOfRange){cout << "Error: Out in Range!\n";}
  // 10.add before the 0th (element 0) . error (out of range)
  cout << endl << c << endl; c++;
  try{L2.addbeforeIth(0,0);} 
  catch(llist::OutOfRange){cout << "Error: Out in Range!\n";}
  // 11.displayAll
  cout << endl << c << endl; c++;
  L2.displayAll();
  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << endl << c << endl; c++;
  L2.deleteIth(1,x);
  cout << "Removed: " << x << endl;
  cout << "Updated List: "; L2.displayAll();
  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
  cout << endl << c << endl; c++;
  L2.deleteIth(6,x);
  cout << "Removed: " << x << endl;
  cout << "Updated List: "; L2.displayAll();
  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << endl << c << endl; c++;
  L2.deleteIth(3,x);
  cout << "Removed: " << x << endl;
  cout << "Updated List: "; L2.displayAll();
  // 15.delete Ith I==5 . error (out of range)
  cout << endl << c << endl; c++;
  try {L2.deleteIth(5,x); cout << "Removing: " << x << endl;}
  catch(llist::OutOfRange){cout << "Error: Out of range\n";}
  // 16.delete Ith I==0 . error (out of range)
  cout << endl << c << endl; c++;
  try {L2.deleteIth(0,x); cout << "Removing: " << x << endl;}
  catch(llist::OutOfRange){cout << "Error: Out of Range\n";}
  // 17.displayAll
  cout << endl << c << endl; c++;
  L2.displayAll();
  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << endl << c << endl; c++;
  while(!L2.isEmpty()){L2.deleteRear(x); cout << "Removed: " << x << endl;}
  // 19.displayAll  
  cout << endl << c << endl; c++;
  L2.displayAll();

}//end of case 2

//PURPOSE: Checks error cases when list is emmpty for adding a Node
//         and deleteing the front Node
void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << 1 << endl;;
  try {L3.addbeforeIth(0,0);}
  catch (llist::OutOfRange){cout << "Error: Out of Range!\n";}
  //2.delete front . error (underflow)
  cout << 2 << endl;
  try {L3.deleteFront(x);}
  catch (llist::Underflow){cout << "Error: No elements in the list\n";}
}   //end of case 3

//PURPOSE: It checks for error cases when list is empty and try to  
//         delete a Node.
void caseFour()
{
  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  //   1.delete 2nd . error (out of range)
  cout << 1 << endl;
  try {L4.deleteIth(2, x);}
  catch (llist::OutOfRange){cout << "Error: Out of Range\n";}
  //    2.delete rear . error (underflow)
  cout << 2 << endl;
  try {L4.deleteFront(x);}
  catch (llist::Underflow){cout << "Error: No elements in the list\n";}
} // end of case 4


//PURPOSE of the Program: Test linked list with 4 cases
//Algorithm/Design: 4 test cases are divided into 3 functions and 
//                  while the user does not input zero, the program 
//                  does not end.
int main()
{
  int selection; // this will indicate what the user wants to do
  
  do
    {
      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Case 1  " << endl;
      cout << "   (2) Case 2  " << endl;
      cout << "   (3) Case 3  " << endl;
      cout << "   (4) Case 4 " << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";
      
      cin >> selection;
      
      switch(selection)//Take the user to teh correcect case
	{
	case 1: caseOne(); break;
	case 2: caseTwo(); break;
	case 3: caseThree(); break;
	case 4: caseFour(); break;
	}
    }
  while(selection !=0);

}// end of main

