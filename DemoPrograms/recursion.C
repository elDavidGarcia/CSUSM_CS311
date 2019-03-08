#include<iostream>
using namespace std;






void display(int L[], int beg, int end)
{
  for (int i = beg; i <= end; i++)
    cout << L[i] << " " ;
  cout << endl;
}


void divide(int L[], int beg, int end, int red)
{
  cout << "Divide was called: ";
  display(L, beg, end);

  if ((end - beg) >=1)  // if more than 1 item in the list
    divide(L, beg, end-red, red);  // recursive call

  else cout << "Ending recursion." << endl;
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

  cout << "Reduce the list by how much each time??";
  cin >> red;
  divide(MyArray, 0, 9, red);
}
