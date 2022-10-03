/***************************************
Student Name: Eray Sahin
Student E-mail: esahin2@myseneca.ca
Student ID: 156387201
Date: 09/15/2022
I have done all the coding by myselfand only copied the code that
my professor provided to complete my workshops and assignments.
**************************************/
#ifndef SDDS_UTILS_H // replace with relevant names
#define SDDS_UTILS_H

// Your header file content goes here

namespace sdds 
{
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}

#endif

