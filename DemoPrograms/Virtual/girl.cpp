#include "girl.h"

#include <iostream>

girl::girl()
{ cout << "girl const" << endl; }

girl::~girl()
{ cout << "girl deconst" << endl; }

void girl::doit()
{ cout << "I am a girl." << endl; }
