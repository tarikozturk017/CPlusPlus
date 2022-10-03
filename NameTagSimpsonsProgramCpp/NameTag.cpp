#include <iostream>
#include "NameTag.h"
#include "Utils.h"

using namespace std;
using namespace sdds;


void NameTag::set(const char* name) {

	strcpy(*(this->name), name, strlen(name));
}