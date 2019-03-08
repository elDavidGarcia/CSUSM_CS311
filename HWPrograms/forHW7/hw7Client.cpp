// ===============================================================
//HW#: HW7 
//Your name: David Garcia
//Complier:  g++
//File type: Client File 
//================================================================

#include <iostream>
#include "dgraph.h"
#include "stack.h"
using namespace std;

//PURPOSE: Test dgraph with visit numbers 
//ALGORTHIM: Fills the table using fill table function and displays it. Inside the 
//           do-while it adds elements from the graph into the stack (if they have not been 
//           marked yet. It does this by getting the adjacent verteces, from the one that
//           has been currently been poped into vertex,while the list is not empty. Then
//           it pops the nest vertex into vertex until stack is empty. Displays the graph
//           with new visit numbers.
int main()
{
  dgraph table;//Initailaize a new graph
  slist tempList;//Holds list given from adjacent vertex function 
  stack tableStack;//Stack for holding vertex pushed from the graph
  int visitNum = 0;//Indicates the current slot in the graph
  el_t vertex;//Temporary variable to hold a vertex, either from stack or list

  table.fillTable();//Fill the graph
  table.displayGraph();//Display without assigned visit numbers 
  tableStack.push('A');//Start with A
  do{//Start the loop
    tableStack.pop(vertex);//Pop next vertex in the stack
    cout << "Visiting Vertex " << vertex << endl;
    if(!table.isMarked(vertex))//If vertex poped is not marked 
      {
	visitNum++;//increment the visit num
	table.visit(visitNum, vertex);//Give the new visit num to the poped vertex
	tempList = table.findAdjacency(vertex);//Find the adjacent list from popped vertex
	while(!tempList.isEmpty())//Push the adjacent verteces until list is empty
	  {
	    tempList.deleteRear(vertex);//Store rear vertex into vertex
	    if(!table.isMarked(vertex))//Check if the vertex was already marked
	      tableStack.push(vertex);//Push it into the stack
	  }//CLOSE: while(!tempList.isEmpty())
      }//CLOSE: if(!table.isMarked...
    tableStack.displayAll();//Display the new stack
  }while(!tableStack.isEmpty());//Do while stack is not empty
  table.displayGraph();//Display the new graph with assigned visit numbers
  return 0;//End program
}//CLOSE: Main()
