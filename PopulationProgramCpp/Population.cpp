/*
Student Name: Eray Sahin
Student ID: 156387201
Section: NRA
Date: 09-25-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
	//sort
	//calculate number of postal codes and populations
	int noOfPostalCodes;
	int noOfPopulations;
	//struct
	PostalCode* postcode;

	bool load(PostalCode &post) {
		bool tf = false;
		char postalCode[7];
		if (read(postalCode) && read(post.population))
		{
			post.code = new char[strlen(postalCode) + 1];
			//strcpy
			strcpy(post.code, postalCode);
			tf = true;
		}
		return tf;
	}

	bool load(const char filename[])
	{
		bool tf = false;
		int counter = 0;
		//open
		if (openFile(filename))
		{
			noOfPostalCodes = noOfRecords();
			//malloc
			postcode = new PostalCode[noOfPostalCodes];
			for (int a = 0; a < noOfPostalCodes; a++)
			{
				counter += load(postcode[a]);
			}
			if (counter != noOfPostalCodes)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
			}
			else
			{
				//true
				tf = true;
			}
			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
		}
		return tf;
	}

	void display(const PostalCode& code)
	{
		cout << code.code << ":  " << code.population << endl;
	}

	void sortPostCodes()
	{
		int a;
		PostalCode postCode;
		for (int i = 1; i < noOfPostalCodes; i++)
		{
			postCode = postcode[i];
			for (a = i - 1;
				a >= 0 && postcode[a].population 
				> postCode.population;
				a--)//reverse
			{
				postcode[a + 1] = postcode[a];
			}
			//postcode[a] = postCode;
			postcode[a + 1] = postCode;
		}
	}

	void display() {
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		//using noofrecs
		//noofrecs << postalcode << : << 2 spaces << population
		sortPostCodes();
		for (int i = 0; i < noOfPostalCodes; i++)
		{
			cout << i + 1 << "- ";
			display(postcode[i]);
			noOfPopulations += postcode[i].population;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << noOfPopulations << endl;

	}

	void deallocateMemory() {
		for (int i = 0; i < noOfPostalCodes; i++)
		{
			delete[] postcode[i].code;
			postcode[i].code = nullptr;
 		}
		delete[] postcode;
		postcode = nullptr;
	}
}