using namespace std;

#include <string>

// This is the parent class
class person
{
 protected:
  string name;
  int age;

 public:
  person();
  ~person();
  void doit(); 

};
