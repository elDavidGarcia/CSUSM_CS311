#include "person.h"

#include <iostream>

person::person()
{ cout << "person const" << endl; }

person::~person()
{ cout << "person deconst" << endl; }

void person::doit()
{ cout << "I am a person." << endl; }
