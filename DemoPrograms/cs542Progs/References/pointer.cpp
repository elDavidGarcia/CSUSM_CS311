#include <iostream>
using namespace std;

  //This function basically translates f(m,2) into m[2]
  int& f(int X[], int i) 
    {
      return X[i]; }  // f returns the location of X[i]  because of &


int main2()
{

  int m[] = {1,2,3};
  f(m,1)= 6;         // the location of m[1] gets 6
  cout << m[1] << endl ;  // 6 will be displayed

  cout << f(m,1) << endl;  // displays m[1] which is 6

}

int main()
{
  int *P;  // pointer P is declared
  int A = 6;    // integer variable is declared
   P = &A;       // makes P point to the location of A
   *P = A;        // this does not work unless P=&A has been done 
   cout << *P << endl;  // displays 6

  int m[] = {4,2,3};  // static array m. m is a pointer
  cout << *m;  // displays 4 because *m refers to the first element of m
  cout << *(m+1) ;  // displays 2 the 2nd element of m
  cout << *(m+2) ;  // displays 3 the 3rd element of m

  cout << endl;
  main2();

}

