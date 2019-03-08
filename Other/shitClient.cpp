// =======================================================
// HW#: HW1
// Your name: DAG
// Compiler:  g++
// File type: Client file
//=======================================================
#include <iostream>
#include <cstdlib>
#include <time.h>
//#include <ctime>
//#include <ratio>
//#include <chrono>
#include "shit.h"
using namespace std;
//Purpose: to test the priority queue functions
//algorithm:will make a PCB table with 20 entries that has Id 1 - 20. then we will insert 
//4 elements into the queue display, remove from the queue, display, remove from the queue,
//display, then insert 5 more elements and remove them untilempty 

int main()
{
  srand(time(NULL));
  cout << "=================================================" << endl;
  cout << "Name: David Garcia\n" 
       << "Date: 2/12/17\n"
       << "Course: CS 433\n"
       << "This program will test the priority queue. It will use the functions insertjobs, displayqueue, returnHighestJob, and size." << endl;
  cout << "=================================================" << endl;
  cout << "Test 1" << endl;
  pq q1;
  PCB PTable[20];
  PCB u;
  for(int A = 0; A < 20; A++)
    {
      PTable[A].ID = A+1;
      PTable[A].Pnum = A + 1;
      PTable[A].state = "New";
    }
  cout << "\n\n\n";
  q1.insertJob(PTable[4]);
  q1.insertJob(PTable[0]);
  q1.insertJob(PTable[7]);
  q1.insertJob(PTable[10]);
  q1.displayQueue();
  cout << endl;;
  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  q1.insertJob(PTable[2]);
  q1.insertJob(PTable[6]);
  q1.insertJob(PTable[1]);
  q1.insertJob(PTable[11]);
  q1.insertJob(PTable[8]);
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;
  
  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  u = q1.returnHighestJob();
  cout << "Removed: " << u.ID << " Pnum: " << u.Pnum << " State: " << u.state << endl;
  q1.displayQueue();
  cout << endl;

  
  cout << "==================================================" << endl;
  cout << "Test 2" << endl;
  for(int c = 0; c < 20; c++)
    PTable[c].Pnum = rand()%50+1;

  int randNum = rand()%20;
  for(int i = 0; i < 10; i++)
    {
      q1.insertJob(PTable[randNum]);
      randNum = (randNum+1)%19;
    }

  int A = 0;
  PCB E;
  int C;
  //time_t begin, end;
  //time(&begin);
  //using namespace chrono;
  //high_resolution_clock::time_point t1 = high_resolution_clock::now();
  for(int i = 0; i < 1000000; i++)
    {
      A++;
      int x = rand()%2;
      try
        {
          if(x == 0)
            E = q1.returnHighestJob();
          else q1.insertJob(PTable[randNum]);
        }
      catch (pq::OverFlow)
        {
          //cout << "Queue is full, need to remove a job!\n";
          E = q1.returnHighestJob();
        }
      catch (pq::UnderFlow)
	{//cout << "Queue is empty need to add a job!\n";
	  q1.insertJob(PTable[randNum]);
        }
      randNum = (randNum+1)%19;
    }
  //time(&end);
  //high_resolution_clock::time_point t2 = high_resolution_clock::now();
  //duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  //double diffrence = difftime(end, begin);
  //cout << "Time: " << time_span.count() << "\n\n";
  cout << "Counter: " << A << endl;

 
  return 0;
}
