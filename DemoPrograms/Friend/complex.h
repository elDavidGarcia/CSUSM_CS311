using namespace std;
#include <iostream>

class Complex
{
 private:
  float realpart, imagpart;

 public:  
  Complex(float r=0, float i=0);  // creates a new object with
                                  // with given values 
                         // if values are not given, use 0s 
 
  void display(); // displays the Complex number

  // friend function is used for overloading +
  // Here, both arguments can be floats which are treated
  // as the r parts of Complex numbers
  friend Complex operator+(const Complex&, const Complex&);  
};





           
