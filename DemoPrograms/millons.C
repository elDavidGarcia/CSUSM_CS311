// How long does this take?
// N = 1 million and this is N^2
// Do not use Optimization 

#include <iostream>
using namespace std;

int main()
{
  int a;
  cout << "begin" << endl;  

  for (int i = 1; i <= 1000000; i++)
    { 
      for (int j = 1; j <= 1000000; j++)
	{ a = i - j + 7; }
    }
  cout << "done" << endl;
 
}
