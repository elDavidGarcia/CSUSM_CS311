#include "complex.h"

int main()
{
  Complex X(3.2,1.2);
  X.display();

  Complex Num;
  Num.display();

  Complex Res;
  Res = Num + 2; // 2 is treated as the r part
                 // in operator+(Num, 2);
  Res.display();

  Res = 1 + Num; // 1 is treated as the r part
                 // in operator+(1, Num)
  Res.display(); // I could not have done this with regular +
                 // because it would be like 1.operator+(Num) 

}  
  
