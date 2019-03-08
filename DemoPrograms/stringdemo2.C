#include <iostream>
using namespace std;
#include <string>


// Demostrates casting (conversion from char to int)

int main()
{
  string mystring;
  cout << "Give me a string:";
  cin  >> mystring;

  int i = 0;
  while (mystring[i] != '\0')  // until the end of the string
    { 
      char let;
      let = mystring[i];
      cout << i <<  "th == ";
      cout << let << endl;

      // conversion to int
      if ((let != '*') && (let != '+'))
	{ int x = int(let)-48;
        cout << "integer value is: " << x << endl;
      }

      i++;  // next char
    }

}
