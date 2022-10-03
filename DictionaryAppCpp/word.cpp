/*Student Name : Eray Sahin
Student ID: 156387201
Student E-mail Address: esahin2@myseneca.ca
Date: 09-18-2022
I have done all the coding by myself and only copied the 
code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
	void DisplayWord(const char* word)
	{
		SearchWord(word);
	}

	void AddWord(const char* word, const char* type, const char* definition)
	{
		NewWord(word, type, definition);
	}
}