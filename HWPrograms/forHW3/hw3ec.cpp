//===========================================================
//HW#: HW3P3 slist
//Your name: David Garcia
//Complier:  g++
//File type: Extra Credit :) (tester)
//===========================================================
#include <iostream>
#include <iomanip>
#include "slist.h"
using namespace std;

//PURPOSE: To test the overloaded equivalent (==) operator in slist. Makes use
//         of displayAll, addRear, deleteRear, and deleteIth functions in slist.
//         outputs the result and contents of each list neatly.  
int main()
{
  slist L1, L2;//Initailize two list of the slist class
  int temp;//Temproary value to be used when deleting an element
  
  //Makes a nice template with case on left and result on right
  cout << setw(40) << left << "Case: " << "Result:\n";
  //Case 1: L1 is empty and L2 is empty (should be True), output result. 
  cout << setw(40) << "1.L1 is empty and L2 is empty";
  if(L1 == L2) cout << "True\n"; 
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll();
  //Case 2: L1 is empty and L2 has 2 elements (should be False), output result and
  //        contents of each list. 
  cout << endl << setw(40) << "2.L1 is empty and L2 has 2 elements";
  L2.addRear(1); L2.addRear(2);
  if(L1 == L2) cout << "True\n";
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll();
  //Case 3: L1 has 2 elements and L2 is empty (should be False), output result and
  //        contents of each list. 
  cout << endl << setw(40) << "3.L1 has 2 elements and L2 is empty";
  while(!L2.isEmpty()) L2.deleteRear(temp);
  L1.addRear(1); L1.addRear(2);
  if(L1 == L2) cout << "True\n";
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll();
  //Case 4: L1 has 1,2,3 and L2 has 1,2,3 (should be True), output result and
  //        contents of each list.
  cout << endl << setw(40) << "4.L1 has 1,2,3 and L2 has 1,2,3";
  L1.addRear(3); L2.addRear(1); L2.addRear(2); L2.addRear(3);
  if(L1 == L2) cout << "True\n";
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll();
  //Case 5: L1 has 1,2,3 and L2 has 1,2 (should be False), output result and
  //        contents of each list.
  cout << endl << setw(40) << "5.L1 has 1,2,3 and L2 has 1,2";
  L2.deleteRear(temp);
  if(L1 == L2) cout << "True\n";
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll();
  //Case 6: L1 has 1,2,3 and L2 has 1,2,3,4 (should be False), output result and
  //        contents of each list.
  cout << endl << setw(40) << "6.L1 has 1,2,3 and L2 has 1,2,3,4";
  L2.addRear(3); L2.addRear(4);
  if(L1 == L2) cout << "True\n";
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll();
  //Case 7: L1 has 1,2,3 and L2 has 1,2,4 (should be False), output result and
  //        contents of each list.
  cout << endl << setw(40) << "7.L1 has 1,2,3 and L2 has 1,2,4";
  L2.deleteIth(3, temp);
  if(L1 == L2) cout << "True\n";
  else cout << "False\n";
  cout << "L1: "; L1.displayAll(); cout << "L2: "; L2.displayAll(); cout << endl;
  return 0;
}//End of program
