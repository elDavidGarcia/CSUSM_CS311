#include "person.h"

using namespace std;

// Inherits from person public functions but not constructor/destructor

class girl : public person
{
 private: 
   int g_id;

 public:
  girl();
  ~girl();
  void doit();  // girl's doit

}; 
