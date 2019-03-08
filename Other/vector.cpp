#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> myVector;
  myVector.resize(10);
  myVector[0] = 1;
  myVector.resize(11);
  cout << myVector[0] << endl;
  return 0;
}
