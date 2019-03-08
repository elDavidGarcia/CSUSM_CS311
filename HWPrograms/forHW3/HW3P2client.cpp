//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line

//=========================================================
//HW#: HW3P2 slist
//Your name: David Garcia
//Complier:  g++
//File type: client program (tester)
//===========================================================
using namespace std;
#include <iostream>
#include "slist.h"

//PURPOSE: Test slist which inherits everything from llist. The program test add front, 
//         add rear, display all, search, and replace. Also, it test slist's replace
//         function's error case (OutOfRange), then ends program.
int main()
{ slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
try
  {
    //  1)add to front once (element 4)
    cout << counter << endl; counter++;
    L.addFront(4);
    //  2)add to rear 3 times (elements 6,7,8)
    cout << endl << counter << endl; counter++;
    L.addRear(6); L.addRear(7); L.addRear(8);
    //  3)displayAll    - 4 6 7 8
    cout << endl <<counter << endl; counter++;
    L.displayAll();
    //  4)search for 6, report the result  - found in pos 2
    cout << endl << counter << endl; counter++;
    foundPos = L.search(6); //Store position in foundPos
    if(foundPos == 0) cout << "Number not found!\n";
    else cout << "The number 6 is in position: " << foundPos << endl;
    //  5)replace the 6 with 0 using the search result
    cout << endl << counter << endl; counter++;
    L.replace(0, foundPos); 
    //  6)search for 8 and report the result . found in pos 4
    cout << endl << counter << endl; counter++;
    foundPos = L.search(8);//Store position in foundPos
    if(foundPos == 0) cout << "Number not found!\n";
    else cout << "The number 8 is in position: " << foundPos << endl;
    //  7)replace the 8 with 2 using the search result
    cout << endl << counter << endl; counter++;
    L.replace(2, foundPos); 
    //  8)displayAll                       - 4 0 7 2
    cout << endl << counter << endl; counter++;
    L.displayAll();
    //  9)search for 5 and report the result   - not found
    cout << endl <<  counter << endl; counter++;
    foundPos = L.search(5);//Store position in foundPos
    if(foundPos == 0) cout << "Number not found!\n";
    else cout << "The number 5 is in position: " << foundPos << endl;
    // 10) replace postion 7 with 10
    cout << endl <<  counter << endl; counter++;
    L.replace(10, 7);
    }//end of try
 catch(slist::OutOfRange)
   { cerr << "ERROR: Bad position was given" << endl; return 0;}
}//end of program
