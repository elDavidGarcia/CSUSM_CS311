// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.

/*
  
int main()
{ 0.Declare table object
1.fillTable()
2.displayGraph()
while (the user does not want to stop)
a.the user will specify which vertex     
b.findOutDegree of the vertex and display the result
c.catch exception but do not exit

while (the user does not want to stop)
a.the user will specify which vertex
b.findAdjacency of the vertex and display the result (see Hint)
c.catch exception but do not exit
}


Hint:
slist l1;
l1 = G.findAdjacency('a');
// how do you display l1?  Hint: it is an slist from HW3.

*/
#include "dgraph.h"
using namespace std;

//PURPOSE: Test Dgraph and allows for the search for Out Degree and
//         Adjacent One(s) list.
//ALGORITHYM: Initialize a Dgraph structure (table), a char (ans)
//            for user input, and a slist (l1) for receiving adjacent
//            ones list. Fill the Table by using the FillTable.() function
//            (fills the table with "table.txt" input), display the table
//            by calling the display function. Make a do-while loop to ask
//            the user for a vertex (store it in ans) and display the out 
//            degree of that vertex inside a try catch statement in case it 
//            it returns a bad vertex. Stay in the loop while the user does
//            not enter 0. For the second do-while loop itis the same as the 
//            first except you have to store the adjacent one list into l1
//            then use l1's display function to display the list. Exit out
//            of the program
int main()
{
  dgraph table;//Initailizes a dgraph named "table"
  char ans;//To store the user's input
  slist l1;//To store adjacent ones list
  table.fillTable();//Fill the dgraph
  cout << "________________________________________________________\n\n";
  table.displayGraph();//Display the dgraph
  cout << "________________________________________________________\n\n";
  do{//Ask for vertex from user
    cout << "Enter a vertex to find out its degree (Enter 0 to stop)\n";
    cin >> ans;//Store input in ans
    if(ans != '0'){//The user has entered a vertex, try to find it
      try{cout << "Degree: " << table.findOutDegree(toupper(ans)) << endl;}
      //Invalid vertex was entered, let user know
      catch(dgraph::BadVertex){cerr << "Invalid Vertex\n";}}
  }while(ans != '0');//As long as '0' was not entered
  cout << "________________________________________________________\n\n";
  do{//Ask for vertex from user
    cout << "\nEnter a vertex to see vertex adjacency (Enter 0 to stop)\n";
    cin >> ans;//Store input in ans
    if(ans != '0'){//The user has entered a vertex, try to find it
      try{cout << "Adjacent one(s): \n"; 
	l1 = table.findAdjacency(toupper(ans));//Store the list in l1 when returned
	l1.displayAll();}//Display the ajacent ones list
      //Invalid vertex was entered, let user know
      catch(dgraph::BadVertex){cerr << "Invalid Vertex\n";}}
  }while(ans != '0');//As long as '0' was not entered
  cout << "________________________________________________________\n\n";
  return 0;//Close Program
}
