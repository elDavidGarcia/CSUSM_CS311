#include "person.h"

using namespace std;

// Inherits from person
class boy : public person
{
 private: 
   int b_id;

 public:
  boy();
  ~boy();
  void doit();  // boy's doit
}; 
