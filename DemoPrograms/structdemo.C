#include <iostream>
#include <string>

using namespace std;


// student is a type of struct/record with 4 fields.

struct student
{
  string Name;
  char   Gender;
  string Major;
  int    Age;
};
// do not forget the semicolon


// function prototypes
void GatherData(student[], int);
void DisplayStudent(student[], int);


int main()
{
  // Local variables are MyClass and s

  student MyClass[10];  //MyClass array is made up of students
  
  // Gather data on students. Max is 10 students.
  GatherData(MyClass, 10);
  // Display info on all students.
  for (int s=0; s < 10; s++)
      DisplayStudent(MyClass, s);

}// end of main



//Purpose: To fill the passed array with student data but using Default record
//         for unused slots. 
//Parameters: Slist array to hold student data, size is the array size
//Algorithm: Uses a while loop that stops as soon as the user enters N or n
//           or the slot exceeds size-1.  For the rest, Default will be used.
void GatherData(student Slist[], int size)
{
  // local variables known only inside this function
  student Default = {"John Smith", 'M', "CS", 20};
  int i = 0;  // slot counter
  char ans;   // user answer
  
  // while loop to enter data until the user types in N
  cout << "Start? Type N or n to quit ";
  cin >> ans;
  while (((ans != 'N') && (ans != 'n')) && (i < size))
    {
      cout << "Enter student last name: ";
      cin >> Slist[i].Name;
      cout << "Enter student gender: ";
      cin >> Slist[i].Gender;
      cout << "Enter student Major: ";
      cin >> Slist[i].Major;
      cout << "Enter student Age: ";
      cin >> Slist[i].Age;

      cout << "Continue? Type N or n to quit ";
      cin >> ans;
      i++;  // go to the next slot
    }// end of while loop
  
  // i at this point is the number of students entered by the user
  for (int j = i; j < size; j++)
    {
      Slist[j] = Default;
    } //end of for loop
  
  
}//end of Gather Data


//Purpose: To display info on one student   
//Parameters: Slist array holding student data, slot is where the given student
//            record is found
//Algorithm:  nicely formats with couts 
void DisplayStudent(student Slist[], int slot)
{

  cout << "Name: " << Slist[slot].Name << endl;
  cout << "Gender: " << Slist[slot].Gender << endl;
  cout << "Major: " << Slist[slot].Major << endl;
  cout << "Age: " << Slist[slot].Age << endl;
  cout << "------------------------------------" << endl;

}// end of DisplayStudent

