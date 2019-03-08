//=========================================================
//HW#: HW1P1 queue
//Your name: David Garcia
//Complier:  g++
//File type: client program for queue
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include "queue.h"


//Purpose of the program: Uses queue to make an on going list of the diffrent
//                        combinations that can be made with the strings
//                        "A", "B", and "C". 
//Algorithm: Adds "A", "B", and "C" to the queue to start it off. Then it goes into
//           an infinate loop that removes the front string to add it to "A", "B",
//           and "C" to create diffrent combinations of the strings and adds them
//           into myQueue. Then displays the contents of the queue. It does this
//           until the queue throws an overflow, meaning queue is full and no more 
//           string combinations can be added. 

int main()
{ 
  queue myQueue; //Make a string queue
  el_t elem; //Variable to store element removed from queue
  
  //Add "A", "B", "C" to queue to start combinations
  myQueue.add("A"); 
  myQueue.add("B");
  myQueue.add("C");
  while(1 == 1)// loop -- indefinitely
    {
      try
	{ 
	  myQueue.displayAll(); //Display the contents of the queue
	  myQueue.remove(elem); //Remove the front elem and store it into elem
	  cout << elem << endl; //Display the element removed from queue
	  //Add the element removed to "A", "B", and "C" to make new combinations
	  myQueue.add(elem + "A");
	  myQueue.add(elem + "B");
	  myQueue.add(elem + "C");
	}
      //Catch the overflow thrown when queue filled up, let user know queue is full
      //and end program
      catch(queue::Overflow)
	{
	  cout << "Cannot add anymore \n";
	  return 0;
	}
    }//Close while loop
}// end of program

