#include "person.h"

using namespace std;

// Inherits from person
class girl : public person
{
 private: 
   int g_id;

 public:
  girl();
  ~girl();
  void doit();  // girl's doit
}; 
