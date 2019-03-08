#include<iostream>
#include<cmath>
using namespace std;



void display(int L[], int beg, int end)
{
  for (int i = beg; i <= end; i++)
    cout << L[i] << " " ;
  cout << endl;
}


void divide(int L[], int beg, int end, string j)
{ int mid;

  j = j + "  ";
  cout << j+"Divide was called: ";
  display(L, beg, end);

  if (beg == end) 
    { cout << j+"Recursion is ending" << endl; return; }


  mid = floor((beg+end)/2);  // mid point which will be part of the first 1/2

  cout << j+"For the first half " << endl;
  if ((mid+1 - beg) >=1)  // if more than 0 item in the list
    divide(L, beg, mid, j);  // recursive call


  cout << j+"For the second half " << endl;
  if ((end - mid) >=1)    // if more than 0 item in the list
    divide(L, mid+1, end, j); // recursive call


}







int main()
{
  int MyArray[10];
  int red;

  cout << "I will need 10 integers from you." << endl;
  for (int i = 0; i< 10; i++)
    {
    cout << "Enter::";
    cin >> MyArray[i];
    }
 
  string j = "";
  divide(MyArray, 0, 9, j);
}
