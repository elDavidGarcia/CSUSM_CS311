//Binary search 
#include <iostream>
#include <math.h>
using namespace std;

int binarySearch(int key, int el[], int arraySIZE);

//PURPOSE:
int main()
{
  //Initialize an array with odd numbers from 1-19
  int el[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  //          0  1  2  3  4  5   6   7   8   9
  int key, slot; //Initalize key (input), and slot (slot key is found in)
  //int arraySIZE = 10; //Need to know the size of the array
  int arraySIZE = 10;
  cout << "Enter number you are looking for: ";
  cin >> key; //Get input from user and store it in key
  //Call the search function. returns slot so store it in slot.
  slot = binarySearch(key, el, arraySIZE); 
  if(slot != -1) //Item was found, display what slot it's in.
    cout << "Number has been found in slot: " << slot + 1 << endl;
  else //Item wsa not found in array, let user know.
    cout << "Number not found!\n";
  return 0; //End program
}

//PURPOSE:
//PARAMETERS:
//ALGORITHIM:
int binarySearch(int key, int el[], int arraySIZE)
{
  int slot = floor((arraySIZE-1)/2); //Start slot 
  int Size = slot;  
  bool out = false;
    
  do
    {
      out = true;
      cout << "Comparing against element in slot: " << slot << endl; 
      if(Size > 1) Size = floor(Size/2);
      if(el[slot] == key) return slot;
      else if(el[slot] > key) 
	{
	  slot = slot - Size;
	  out = false;
	}
      else if(el[slot] < key) 
	{
	  slot = slot + Size;
	  out = false;
	}
      //arraySIZE = floor((arraySIZE)/2);
      //cout << "Size: " << arraySIZE << endl;
    }while(!out);
  return -1;
}
