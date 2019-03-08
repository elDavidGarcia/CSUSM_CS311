// =======================================================
// HW#: HW1
// Your name: Alejandro Monje
// Compiler:  g++
// File type: headher file
//=======================================================
#include <iostream>
using namespace std;

const int SIZE = 20;

//struct for PCB
struct PCB
{
  int Pnum;//Priority number
  int ID;//ID number
  string state;//Ready, running, waiting, terminated
};

class pq
{
 private:
  PCB Q[SIZE];// array holding jobs with the priority numbers 
  int count;// how many jobs are in the array
  int front;// where the front element of the queue is.
  int rear;// where the rear element of the queue is.
 public:
  class OverFlow{};
  class UnderFlow{};
  pq();// constructor to create an object
  ~pq();//destructor to destroy an object

  // Purpose: to insert a job into the queue
  // PRAMETER: provide the element to be added
  void insertJob(PCB);

  // Purpose: to remove a job from the queue
  // PRAMETER: none
  PCB returnHighestJob();

  // Purpose: to display the contents of the queue.
  // PRAMETER: none
  void displayQueue();

  // Purpose: to get the size of the queue
  // PRAMETER: none
  int size();
};
