// ===============================================================
//HW#: HW7 dgraph
//Your name: David Garcia
//Complier:  g++
//File type: Implementation file
//================================================================

// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

/* note that Gtable[i].adjacnentOnes is a slist, so you can use
   any slist function on it
   
   Hint on filltable::
   
   Set up fin stream to read from table.txt
   while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
   { fin >> Gtable[coutUsed].outDegree;
   // Then for the outDegree times do the following: (use a for-loop)
   {
   fin >> X;
   (Gtable[coutUsed].adjacentOnes).addRear(x); 
                      // this uses a slist function from HW3
		      }//end of for
		      // increment the countUsed
		      }//end of while
		      close fin
		      
		      Hint on displaygraph::
		      
		      Make the following couts better with labels.
		      for (int i = 0; i < coutUsed; i++}
		      {  
		      cout << Gtable[i].vertexname << endl;
		      cout << Gtable[i].outdegree << endl;
		      (Gtable[i].adjacentOnes).displayAll();
		      }  
		      
		      Instruction on findOutDegree and findAdjacency::
		      
		      For this HW, you must use a loop.
		      Do not go through all the slots of the table
		      Just go through the used slots.
		      
*/

// initialize vertexName (blank) and visit numbers (0)
// initialize countUsed to be 0
#include "dgraph.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
//PURPOSE: Constructor initializes vertexName (blank), visit
//         numbers (0), and countUsed (0)
//ALGORITHYM: Uses for loop that initializes a counter (lion) to 0
//            and until lion reaches SIZE of the array it increments
//            lion to go through all the slots. Inside the loop it
//            makes every vertexName ' ' (blank) and visit 0. After 
//            loop makes countUsed 0.
dgraph::dgraph()
{ //For loop to go through array
  for(int lion = 0; lion < SIZE; lion++)
    {//Make every name blank and visit 0 
      Gtable[lion].vertexName = ' ';
      Gtable[lion].visit = 0;
    }//CLOSE: for(int lion = 0; lion < SIZE; lion++)
  countUsed = 0;//No slots have been used
}//CLOSE: dgraph() 

// do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor
// be called automatically??? Try it.
//PURPOSE: No need for a dgraph deconstructor, calls llist deconstructor
//         automatically 
dgraph::~dgraph()
{
  /*el_t x;
  for(int hippo = 0; hippo < countUsed; hippo++){
      while(!(Gtable[hippo].adjacentOnes).isEmpty()){
	  (Gtable[hippo].adjacentOnes).deleteRear(x);
	  cout << "...deleting rear\n";}}*/
}//CLOSE: ~dgraph() 

// read from the input file table.txt and fill GTable
//PURPOSE: Fills dgraph from a file ("table.txt") 
//ALGORITHYM: Initialize a variable of el_t type and open file
//            ("table.txt"). While the name can still be read into
//            current vertexName (being pointed by countUsed), get  
//            next character in file and store it in current outDegree.
//            Make a for loop with a variable (dog) initialized to 0 that
//            increments by one until it reaches the character in the 
//            current outDegree (number of adjacentOnes). Inside the loop
//            get next character in the file (store it in x) and add it to 
//            the rear of adjacentOnes by calling addRear. After for loop 
//            update countUsed so that it goes to next loop. After while
//            loop close the file.
void dgraph::fillTable()
{
  el_t x;//Variable to store element to be added to adjacentOnes
  ifstream fin("table.txt", ios::in);//Open the stream with "table.txt" file
  while(fin >> Gtable[countUsed].vertexName)//While it can still read the name
    {
      fin >> Gtable[countUsed].outDegree;//Next char in the file goes to outDegree
      //loop will make a list as big as outdegree for that vertex
      for(int dog = 0; dog < Gtable[countUsed].outDegree; dog++)
	{
	  fin >> x;//gets next char in file and stores it in x
	  (Gtable[countUsed].adjacentOnes).addRear(x);//adds x to the list
	}//CLOSE: for(int dog = 0; dog...
      countUsed++;//Update count
    }//CLOSE: while(fin >> Gtable[countUsed].vertexName)
  fin.close();//CLOSE: File stream
}//CLOSE: fillTable()

// displays in an easy to read format
//PURPOSE: Displays dgraph in an easy to read format
//ALGORITHYM: Make a for loop, initialze variable (cat) to 0 and increment by 1
//            while it is less than countUsed (number of used slots). Inside 
//            the loop display the vertex name, out degree, and if adjacent ones
//            is not empty (use slist's isEmpty() function) use the displayAll()
//            function to display contents. 
void dgraph::displayGraph()
{//Goes only through the used slots
  cout << left << setw(15) << "Vertex Name" << setw(15) << "Out Degree" 
       << setw(15) << "Visit Number" << "Adjacent Ones\n";
  for(int cat = 0; cat < countUsed; cat++)
    {//Display: name, outDegree, adjacentOnes list
      cout << setw(15) << Gtable[cat].vertexName << setw(15) 
	   << setw(15) << Gtable[cat].outDegree << setw(15) << Gtable[cat].visit;
      if(!(Gtable[cat].adjacentOnes).isEmpty())//Check if adjacent ones list is Empty
	(Gtable[cat].adjacentOnes).displayAll();//Display list if it is not empty
      cout << endl;//make it look nice
    }//CLOSE: for(int cat = 0; cat...
}//CLOSE: displayGraph()

//PURPOSE: Returns the out degree of a given vertex - may throw BadVertex if
//         the vertex is not found in the table
//PARAMETERS: Pass the desired vertex from the Client (Key)
//ALGORITHYM: Initialize a variable (koala) that is set to 0 and increments
//            (goes through each slot) while it is less than countUsed (no
//            need to check empty slots). Inside the for loop it checks if 
//            the current slot, being pointed by koala, is equivalent to the
//            key passed by the client. If it is it returns the out degree for
//            the current slot. Else it will keep going until it finds the key
//            or it will throw a bad vertex exception, in which the vertex was 
//            not in the graph.
int dgraph::findOutDegree(char key)
{ //Loop goes through used slots of the graph
  for(int koala = 0; koala < countUsed; koala++)
    //Compares the current slot to the key, returns out degree if equivalent
    if(Gtable[koala].vertexName == key) return Gtable[koala].outDegree;
  throw BadVertex();//Vertex was not found inside the graph throw BadVertex
}//CLOSE: findOutDegree(char key)

//PURPOSE: Returns the adjacency list of a given vertex - may throw BadVertex
//         if the vertex is not found in the table
//PARAMETERS: Pass the desired vertex from the Client (Key)
//ALGORITHYM:Initialize a variable (bear) that is set to 0 and increments
//            (goes through each slot) while it is less than countUsed (no
//            need to check empty slots). Inside the for loop it checks if
//            the current slot (being pointed by bear) is equivalent to the
//            key passed by the client. If it is it returns the adjacency list 
//            for the current slot. Else it will keep going until it finds the 
//            key or it will throw a bad vertex exception, in which the vertex
//            was not in the graph.
slist dgraph::findAdjacency(char key)
{//Loop goes through used slots of the graph
  for(int bear = 0; bear < countUsed; bear++)
    //Compares the current slot to the key, returns adjacency list if equivalent
    if(Gtable[bear].vertexName == key) return Gtable[bear].adjacentOnes;
  throw BadVertex();////Vertex was not found inside the graph throw BadVertex
}//CLOSE: findAdjacency(char key)

//PURPOSE: Enters a given visit number for a given vertex, the visit number
//         indicates the order in which the vertices were visited
//PARAMETERS: Give the visit number to be stored into visit and the vertex that
//            the visit number will go into
//ALGORITHIM: If the vertex has not been marked already it assigns the visit number
//            given by the client to teh vertex, else if it already marked nothing
//            changes
void dgraph::visit(int visitNum, char vertex)
{//Check if it's marked else assign given visit number
  if(!isMarked(vertex)) Gtable[vertex-65].visit = visitNum;
}//CLOSE: visit(int, char)

//PURPOSE: Checks to see if a visit number has been assigned to a vertex, returns
//         0 if it has already been visited
//PARAMETERS: Give the Vertex that is to be checked
//ALGORITHIM: Checks if the vertex's visit is zero, if ot is it returns true (1)
//            else by default it returns 0
bool dgraph::isMarked(char vertex)
{//Compare the vertex's visit with zero, return true if it's not 0
  if(Gtable[vertex-65].visit != 0) return true; 
}//Close: isMarked(char)

//End of Implementation file
