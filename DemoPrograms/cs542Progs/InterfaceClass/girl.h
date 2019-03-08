#include "Ipure.h"

using namespace std;

// Inherits from Ipure

class girl : public Ipure
{
 private: int g;

 public:
  girl();
  ~girl();
  virtual void doit();  // need to define doit.   
}; 
