
#include <iostream>
using namespace std;

#include <vector>

// CS211 - This demonstrates how to remove front of the vector (by Yoshii)

int main()
{

  vector<int> myvec;
  vector<int>::iterator it;
  // it is an iterator that can move through a vector.
  // At any point, *it is the element at the it location

  // adding 3 elements to the end
  myvec.push_back(10);
  myvec.push_back(20);
  myvec.push_back(30);

  cout << "All elements: " << endl;
  // from beginning to end but end() is one beyond the end
  // begin() and end() return an iterator
  for (it = myvec.begin(); it != myvec.end(); it++)
            cout << *it << endl;

  // demonstrating the front method which returns the front element
  // This is just like getFront
  cout << "The front element is " << myvec.front() << endl;

  // erase the front element found at begin() 
  // This is just like remove
  myvec.erase(myvec.begin());

  cout << "The front element is now " <<  myvec.front() << endl;

  cout << "All elements: " << endl;
  // from beginning to end but  end() is one beyond the end
  for (it = myvec.begin(); it != myvec.end(); it++)
            cout << *it << endl;

  myvec.erase(myvec.begin()); // erase the front element again

  cout << "After removing one, the front is now " << myvec.front() << endl;

  cout << "Remove another" << endl;
  myvec.erase(myvec.begin()); // erase the front element again

  if (myvec.empty()) cout << "The vector is now empty" << endl;

}

  
