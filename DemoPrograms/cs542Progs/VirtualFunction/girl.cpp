#include "girl.h"

#include <iostream>

girl::girl()
{ g_id = 3; cout << "girl const" << endl; }

girl::~girl()
{ cout << "girl deconst" << endl; }


void girl::doit()
{ cout << "I am a girl." << endl; }
