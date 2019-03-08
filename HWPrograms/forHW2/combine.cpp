//=========================================================
//HW#: HW2P2 Combine
//Your name: David Garcia
//Complier:  g++
//File type: Client for Combine (w/ implemintaion)
//===========================================================
#include <iostream>
#include <vector> //need the vector library
using namespace std;

//Prototypes
void fillList(vector<int>&, int); //Fills list w/ user input
void display(vector<int>&); //Display's a list
void combine(vector<int>&, vector<int>&, vector<int>&); //Combines 2 list into another

int main()
{
  int size; //Varable where size(inputed by user) gets stored
  vector <int> list1; //1st list filled by the user
  vector <int> list2; //2nd list filled by the user
  vector <int> combinedList; //3rd list that combines 1st and 2nd list

  cout << "\nNumber of elements in each List: ";
  cin >> size; //Get input size to create 1st and 2nd list
  //Fill the 1st and 2nd lists by calling fillList function
  fillList(list1, size); 
  fillList(list2, size); 
  //combine the 1st and 2nd list by calling combine, store in 3rd list
  combine(list1, list2, combinedList); 
  //Display the combined list by calling display
  cout << "Combined list: "; display(combinedList); 
  return 0;//end program
}

//FUNCTION: Fills a list with elements inputed from the user.
//PARAMETERS: List that will be filled (list), how many elements will go in the list (size)
//ALGORITHIM: Use resize to make vector desired size to be able to use as an array. Using
//            for loop initalize counter that will also keep track of position in vector
//            While the counter does not reach desired size, it will ask user to input an 
//            element storing it in temp then puts it in a slot inside vecttor by setting
//            vector slot equal to temp. 
//           *I used resize so the vector wouldn't have to find new memory space everytime
//            I wanted to push an element (saves time). 
void fillList(vector<int>& list, int size)
{
  int temp; //Initialize temp variable to get input from user
  list.resize(size); //Resize the vector so you don't have to use push_back. (Saves space)
  for(int i = 0; i < size; i++) //Start the for loop, intialize counter
    {
      cout << "Enter element: "; //Ask for new element
      cin >> temp; //Store it in temp
      list[i] = temp; //store input in vector list
    }
  cout << endl; //make it pretty (easier to read on screen)
}

//FUNCTION: Displays a vector list
//PARAMETERS: The list you wish to display
//ALGORITHIM: Using a for loop initialize a counter that also works for slot
//            slot position. As the counter increments it will move the position
//            by one resulting in displaying the elements one by one. The loop stops 
//            when it reaces the list size by calling size function in vector class.
void display(vector<int>& list)
{
  for(int i = 0; i < list.size(); i++) //Start for loop
    cout << list[i] << " "; //Use counter to display a slot of the vector list
  cout << endl; //Make screen more readable
}

//FUNCTION: Combines two list (list1 and list2) and stores it in combinedList.
//PARAMETERS: Pass 1st list, 2nd list, and 3rd list(store combined list) all by reference
//ALGORITHIM: Initialize 3 counters (one for each list), resize the vector so it is twice
//            the size of the 1st and 2nd list. While counter 3 is less than the size of 
//            the combined list and counters 1 and 2 are less than their lists sizes then 
//            it compares the element counter 1 is pointing to to the element counter 2. 
//            if list's 1 element is smaller or equal to list's 2 element then pass list's
//            1 element to the combined list current slot. Else if list's 1 element is 
//            bigger than list's 2 pass the element in list 2. If one of the list elements
//            are all smaller than the another than the bigger lists comes down 
//            automatically. It does this by using a for loop that goes through the 
//            elements of the bigger list using its counter and stores them in combined
//            list using the combined list counter (counter3). 
//            
//           *I used resize so the vector wouldn't have to find new memory space everytime
//            I wanted to push an element (saves time).
void combine(vector<int>& list1, vector<int>& list2, vector<int>& combinedList)
{
  int count1 = 0; //Counter for list1 
  int count2 = 0; //Counter for list2
  int count3 = 0; //Counter for combinedList
  combinedList.resize(list1.size()*2); //Resize vector to twice the size of list 1 and 2  
  for(count3; count3 < ((list1.size()*2)) && count1 != list1.size() && count2 != list2.size(); count3++)
    {
      if(list1[count1] <= list2[count2]) //compare element in list 1 & 2 
	{
	  combinedList[count3] = list1[count1]; //Store list 1 element in combined list
	  count1++; //Increment counter of list 1
	  cout << "Comparison #" << (count3+1) << endl; //Display comparison number
	}
      else 
	{
	  combinedList[count3] = list2[count2]; //Store list 2 element in combined list
	  count2++; //increment counter of list 2
	  cout << "Comparison #" << (count3+1) << endl; //Display comparison number
	}
    }
  //If the first list still has elements that were not passed, pass them
  //If statement is repetitive but sensei wanted us to ouput "Rest of first..."
  //Works without if statement and no message
  if(count1 < list1.size() && count3 < combinedList.size())
    {
      cout << "Rest of first list goes down!\n\n";
      for(count1, count3; count1 < list1.size() && count3 < combinedList.size(); count1++, count3++) combinedList[count3] = list1[count1];
      return; //No need to check if other list, return to main 
    }
  //If the second list still has element that were not passed, pass them
  //If statement is repetitive but sensei wanted us to ouput "Rest of second..."
  //Works without if statement and no message
  else if(count2 < list2.size() && count3 < combinedList.size())
    {
      cout << "Rest of second list goes down!\n\n";
      for(count2, count3; count2 < list2.size() && count3 < combinedList.size(); count2++, count3++) combinedList[count3] = list2[count2];
    }
}
