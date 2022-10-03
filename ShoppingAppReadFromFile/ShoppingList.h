/***************************************
Student Name: Eray Sahin
Student E-mail: esahin2@myseneca.ca
Student ID: 156387201
Date: 09/15/2022
I have done all the coding by myselfand only copied the code that
my professor provided to complete my workshops and assignments.
**************************************/
#ifndef SDDS_SHOPPINGLIST_H // replace with relevant names
#define SDDS_SHOPPINGLIST_H

#include "ShoppingRec.h"

namespace sdds
{
	// Your header file content goes here
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}



#endif