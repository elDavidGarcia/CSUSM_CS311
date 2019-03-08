#include <iostream>
using namespace std;

#include <vector>


// CS211 Vector demonstration program (by Yoshii)

int main()
{
  vector<int> mylist(3);  // mylist has 3 slots to begin with
  int num;                // to hold an element

  for (int i = 0; i < 3; i++)   // get 3 items
  { 
    cout << "Type an element: ";
    cin >> num;
    mylist[i] = num;     // assigning each to a slot using =
  }

  // demonstrating the size method
  cout << "Entered 3 elements" << endl;
  cout << "Current size: " << mylist.size() << endl;

  // demonstrating the push back method which makes the vector grow
  cout << "Adding one more number (i.e. 100) to the end" << endl;
  mylist.push_back(100);
  cout << "Current size: " << mylist.size() << endl;

  // demonstrating the push back method
  cout << "Adding one more (i.e. 200) to the end" << endl;
  mylist.push_back(200);
  cout << "Current size: " << mylist.size() << endl;

  // demonstrating the pop back method (this is like Popping the stack)
  cout << "Removing one from the end" << endl;
  mylist.pop_back();
  cout << "Current size: " << mylist.size() << endl;


  cout << "Now the entire list is: " << endl;
  for (int i = 0; i < mylist.size(); i++)
  { 
       cout <<  mylist[i]  << endl;
  }



  // Starting the second vector

  vector<int> secondlist;   // secondlist has 0 slots to begin with

  cout << "The second list has size " << secondlist.size() << endl;

  secondlist = mylist;   // the same elements as mylist

  cout << "After =mylist, the entire second list is: " << endl;
  for (int i = 0; i < secondlist.size(); i++)
  { 
       cout <<  secondlist[i]  << endl;
  }


  // demonstrating the use of ==
  if (mylist == secondlist) cout << "The two lists are the same" << endl;

  cout << "Putting 200 in slot 3 of the second list" << endl;
  secondlist[3] = 200;    // 200 for the 3rd slot


  // demonstrating the use of <
  if (mylist < secondlist) 
  cout << "mylist is smaller than the secondd" << endl;

  vector<int> thirdlist(5,2);  // 5 slots all with 2
  cout << "The third list is: " << endl;
  for (int i = 0; i < thirdlist.size(); i++)
  { 
    cout <<  thirdlist[i]  << endl;
  }

  // demonstrating the use of <
  if (mylist < thirdlist) cout << "mylist is shorter than the third" << endl;


}  
