/***************************************
Student Name: Eray Sahin
Student E-mail: esahin2@myseneca.ca
Student ID: 156387201
Date: 09/15/2022
I have done all the coding by myselfand only copied the code that
my professor provided to complete my workshops and assignments.
**************************************/
#ifndef SDDS_FILE_H // replace with relevant names
#define SDDS_FILE_H


#include "ShoppingRec.h"

namespace sdds 
{

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

}



#endif