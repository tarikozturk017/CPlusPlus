#include <iostream>
#include "TagList.h"
#include "NameTag.h"
#include "Utils.h"

using namespace std;
using namespace sdds;


void TagList::set() {
	nt = nullptr;
	emptyCounter();
}
void TagList::set(int num) {
	cleanup();	
	nt = new NameTag[num];
}
void TagList::add(const NameTag& nt) {
	if (strlen(*(nt.name)) > longestName) {
		longestName = strlen(*(nt.name));
	}
	this->nt[getCounter()] = nt;
	increaseCounter();
}
void TagList::print() {
	for (int i = 0; i < getCounter() + 1; i++) 
	{
		cout.width(longestName + 4);
		cout.fill('*');
		cout << endl;
		cout.fill(' ');
		cout << "* " << nt[i].name << " *" << endl;
		cout.fill('*');
		cout << endl;
	}

	
}
void TagList::cleanup() {
	delete[] nt;

}

