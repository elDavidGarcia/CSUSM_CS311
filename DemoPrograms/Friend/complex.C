#include "complex.h"


Complex::Complex(float r, float i)  // eates a new object with
    {realpart = r; imagpart = i;} // 0 if missing

void Complex::display()
{
  cout << realpart << " and " << imagpart << endl; }

// Both y and z will be passed to the operator by reference
// Adds y and z and returns a new object
Complex operator+( const Complex& y, const Complex& z)
{
     return
       Complex(y.realpart + z.realpart, y.imagpart + z.imagpart);
}
