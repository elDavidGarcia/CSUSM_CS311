// =======================================================
// HW#: HW1
// Your name: Alejandro Monje
// Compiler:  g++
// File type: PQ.cpp file
//=======================================================
#include "shit.h"
using namespace std;

//constructor
pq::pq()
{
  count = 0;// set count to 0
  front = 0;// set count to 0
  rear = 0;// set count to 0
}

//destructor
pq::~pq()
{
}

// PURPOSE: to insert a job to the queue
// Algorithm: if count == 0 then there insert into the first slott 
// since the queue is empty else if its full then return. else we insert an item to the 
// rear of the queue
// PAREMETER: provide the element to be passed
void pq::insertJob(PCB E)
{
  //case1: if queue is empty 
  if(count == 0)
    {
      Q[0].ID = E.ID;         //if the queue is empty the first slot of the array holds 
                              //the ID
      Q[0].Pnum = E.Pnum;     //if the queue is empty the first slot of the array holds
                              //the Pnum
      Q[0].state = "Ready";   //if the queue is empty the first slot of the array holds
                              //the state ready
      count++;// increment the counter
    }
  else if(((rear+1)%SIZE) == front && count == SIZE) throw OverFlow();
  else
    {
      PCB temp;  
      int x = (rear+1)%SIZE;
      int B = rear; 
      Q[x].ID = E.ID; //Q[x].ID gets ID assigned
      Q[x].Pnum = E.Pnum; //Q[x].ID gets Pnum assigned
      Q[x].state = "Ready"; //Q[x].ID gets state is ready
      if(count > 0)// if the queue isnt empty
	{
	  while((Q[x].Pnum < Q[B].Pnum) && B > 0)//while Pnum is less then the rears Pnum
	    {
	      temp.ID = Q[B].ID;//temp gets rear values
	      temp.Pnum = Q[B].Pnum;//temp gets rear values
	      
	      Q[B].ID = Q[x].ID;//rear gets new value which is less in priority
	      Q[B].Pnum = Q[x].Pnum;//rear gets new value which is less in prority
	      
	      Q[x].ID = temp.ID;//Q[x} gets temps values
	      Q[x].Pnum = temp.Pnum;//Q[x] gets temps values
	      x = B;
	      if(B == 0)B = 19;//if the rear == 0 set R to 19
	      else B--;//else decrement R
	    }
	}
      count++;// increment the count
      rear = (rear+1)%SIZE; //wrap around
    }
}

//Purpose: to remove the highest priority of the queue
//Algorithm: we decrement the count and make temp hold the values of the front element
// then the front element is what will be removed. return temp
//Parameters: none
PCB pq::returnHighestJob()
{
  if(count < 1) throw UnderFlow();
  else
    {
      PCB temp;// temp variable
      count--;//decrement the count since we are removing
      temp.ID = Q[front].ID; //temp.Id gets the value from Q[front].ID;
      temp.Pnum = Q[front].Pnum;//temp.Pnum gets the value from Q[front].Pnum;
      temp.state = "Running"; //temp.state gets running state
      front = (front+1)%SIZE;//wrap around
      return temp;// this is the item removed
    }
}

//Purpose: to display the contents of the queue
//Algorithm: checks to see if it is empty and if it is it displays a message
//else it isn't empty. if it is the first thing then display the contents of the 
//slot 0; else it isn't the first item or empty then in a while loop it will display
//the contents at each index
//Parameters: none
void pq::displayQueue()
{
  if(count < 1)// if empty
    cout << "Empty!" << endl;//displays mesage
  else
    {
      int i = front;
      if(count == 1)// if first item display the first slott
	cout << "ID: " << Q[0].ID
	     << " Pnum: " << Q[0].Pnum
	     << " State: " << Q[0].state << endl;
      else
	{
	  while(i != rear)//while the i hasn't reached the rear it will 
	    {             //display the content at each index
	      cout << "ID: " << Q[i].ID 
		   << " Pnum: " << Q[i].Pnum 
		   << " State: " << Q[i].state << endl;
	      i = (i+1)%20;// wraps around
	    }
	}
    }
}

//Purpose: to get the size of the queue
//Algorithm: return the count
//Parameters: none
int pq::size()
{
  return count;
}
