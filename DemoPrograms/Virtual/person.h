using namespace std;

#include <string>

class person
{
 protected:
  string name;
  int age;

 public:
  person();
  ~person();
   virtual  void doit();  // try this with virtual

};
