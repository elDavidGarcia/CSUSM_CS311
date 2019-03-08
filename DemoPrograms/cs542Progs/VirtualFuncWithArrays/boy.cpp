#include "boy.h"

#include <iostream>

boy::boy()
{ b_id = 5; cout << "boy const" << endl; }

boy::~boy()
{ cout << "boy deconst" << endl; }


void boy::doit()
{ cout << "I am a boy." << endl; }
