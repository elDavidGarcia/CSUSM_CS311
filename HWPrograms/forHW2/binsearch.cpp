//=========================================================
//HW#: HW2P1 queue
//Your name: David Garcia
//Complier:  g++
//File type: Client for Binary Search (w/ implemintaion)
//===========================================================
#include <iostream>
#include <math.h>
using namespace std;

//Prototypes
int binarySearch(int , int [], int , int);

//PURPOSE: Asks user to input a number. Calls binary search function
//         to see if the number is inside the list hard coded into the 
//         program. Lets user know which slot the number they are looking 
//         for is in, or if not found lets user know.
int main()
{
  //Initialize an array with odd numbers from 1-19
  int el[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  //          0  1  2  3  4  5   6   7   8   9
  int key, slot; //Initalize key (input), and slot (slot key is found in)
  int first = 0; //Declare first slot of the array
  int last = 9;  //Declare last slot of the array
  cout << "Enter element: ";
  cin >> key; //Get input from user and store it in key
  //Call the search function. returns slot so store it in slot.
  slot = binarySearch(key, el, first, last); 
  if(slot != -1) //Item was found, display what slot it's in.
    cout << "Element is in position: " << slot + 1 << endl;
  else //Item wsa not found in array, let user know.
    cout << "Element was not found in the list!\n";
  return 0; //End program
}

//PURPOSE: Looks for number, inputed by user, inside the list. Returns 
//         the slot number is in or -1 (if not found) by value.
//PARAMETERS: Needs key (number user is looking for), array (list of
//            numbers given), first (first index in array list), and 
//            last (last index in array list)
//ALGORITHIM: Gets middle slot of the array list by dividing the first and last slots
//            it is checking. If the key is less than current slot being checked the
//            last slot becomes the current slot -1 so it decreses the size by half
//            and goes to check the half with smaller numbers. If the key is greater 
//            than the slot being checked it makes the first equal to current slot +1
//            so it cuts size by half and goes to check the half with bigger numbers.
//            It keeps doing this until the first and last slot crosses which would mean
//            it has checked all the elements in the list. If this happens it gets out of
//            the do-while loop to return -1, letting the main know element was not found.
int binarySearch(int key, int el[], int first, int last)
{
  int slot; //The middle of the list, number that is compared to the key. 
  do
    {
      slot = floor((first+last)/2); //Gives new middle location to check against key 
      if(el[slot] == key) return slot; //Finds key and returns slot where it is located
      else if(key < el[slot]) last = slot - 1; //goes to first half of list
      else if(key > el[slot]) first = slot + 1;//goes to second half of list
    }while(first <= last); //While the first and last dont cross 
  return -1; //element was not found, return -1 as a "not found" to main
}
