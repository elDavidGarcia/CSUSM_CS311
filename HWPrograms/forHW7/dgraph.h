// ===============================================================
//HW#: HW7 dgraph
//Your name: David Garcia
//Complier:  g++
//File type: Header file
//================================================================

// ============ for the dgraph.h file =================================
// INSTRUCTION:
// You need to comment this file completely using the How to Comment file.
// You have seen many examples so far.
// We will check to see how well you have commented it.

// I am using hw3p3.h which is the most up to date slist.h
// You can change it to your "slist.h"

#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;   // for the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;    //stores the vertex Name
  int outDegree;      //stores the Out degree
  slist adjacentOnes; //stores the adjecent vertices in an slist
  int visit;          // This will hold the visit number in HW7 
};

class dgraph
{
  
 private:
  Gvertex Gtable[SIZE];// a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used
  
 public:
  
  class BadVertex {};// thrown when the vertex is not in the graph
  //PURPOSE: Constructor initializes vertexName (blank), visit
  //         numbers (0), and countUsed (0)
  dgraph(); 
  //PURPOSE: Deconstructor, 
  ~dgraph();   // do we have to delete all nodes of slists in table??
	       // Question: If we do not do this, will the llist destructor
               // be called automatically??? Try it.
  
  //PURPOSE: Read from the input file table.txt and fill GTable
  void fillTable();  
  
  //PURPOSE: Displays dgraph in an easy to read format 
  void displayGraph(); 
  
  //PURPOSE: Returns the out degree of a given vertex - may throw BadVertex
  //         if the vertex is not found in the graph
  //PARAMETER: Pass the desired vertex to get the degree for that specific
  //           Vertex
  int findOutDegree(char);  
  
  //PURPOSE: Returns the adjacency list of a given vertex - may throw 
  //         BadVertex if the vertex is not found in the graph
  //PARAMETER: Pass the desired vertex to get the adjacent list for that 
  //           specific Vertex  
  slist findAdjacency(char);  
  
  //PURPOSE: Enters a given visit number for a given vertex, the visit number
  //         indicates the order in which the vertices were visited
  //PARAMETERS: Give the visit number to be stored into visit and the vertex that
  //            the visit number will go into
  void visit(int, char);

  //PURPOSE: Checks to see if a visit number has been assigned to a vertex, returns 
  //         0 if it has already been visited
  //PARAMETERS: Give the Vertex that is to be checked
  bool isMarked(char);
};
