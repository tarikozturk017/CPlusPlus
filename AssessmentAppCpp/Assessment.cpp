/*
Student Name: Eray Sahin
Student ID: 156387201
Section: NRA
Date: 09-23-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Assessment.h"
#include "Utils.h"

using namespace std;

namespace sdds {


	//Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(int& value, FILE* fptr)
	{
		if (fptr != nullptr)
		{
			bool b = false;
			b = fscanf(fptr, "%d", &value);
			return b;
		}

		else
		{
			return false;
		}
	}

	////Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false
	bool read(double& value, FILE* fptr)
	{
		if (fptr != nullptr)
		{
			bool b = false;
			b = fscanf(fptr, "%lf", &value);
			return b;
		}

		else
		{
			return false;
		}
	}

	////Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false
	bool read(char* cstr, FILE* fptr)
	{
		if (fptr != nullptr)
		{
			bool b = false;
			b = fscanf(fptr, ",%60[^\n]\n", cstr);
			return b;
		}

		else
		{
			return false;
		}
	}

	///*First it will try to read a double value for the mark and a string for title into a temporary local double variable and a 60 character lone cString (+1 for null).
	//If the read is successful, it will then allocate a dynamic double and a dynamic cString to the exact size of the read cstring from the file into the fields of the asmnt structure (asmnt.m_mark and asmnt.m_title) and copies the values into them.
	//In this case, the function will return true, otherwise, it will return false with no memory allocation.*/
	bool read(Assessment& asmnt, FILE* fptr)
	{
		int tempVal = 0;
		bool b = false;
		double newMark = 0;
		char newArray[61] = { '\0' };
		if (fptr != nullptr)
		{
			tempVal = fscanf(fptr, "%lf,%60[^\n]\n", &newMark, newArray);
			if (tempVal == 2)
			{
				asmnt.m_mark = new double;
				asmnt.m_title = new char[strlen(newArray) + 1];
				//*asmnt.m_mark
				*asmnt.m_mark = newMark;
				strcpy(asmnt.m_title, newArray);
				b = true;
			}
		}
		else
		{
			b = false;
		}
		return b;
	}

	///*This function will receive a reference of a dynamic Assessment array and its size. The function then will delete the dynamic Assessment array as follows:
	//The dynamic array will be deleted by first going through each element of the Assessment array in a loop,
	//deleting the dynamic double and the dynamic cString of all Assessment elements and then it will delete the array itself.*/
	void freeMem(Assessment*& aptr, int size)
	{
		//malloc
		for (int i = 0; i < size; i++)
		{
			//delete[] aptr[i].m_mark;
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}

		delete[] aptr;
		//aptr = 0;
	}

	///*This read function receives a reference of an Assessment pointer (to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.
	//The function will first read one integer which is the number of upcoming records to read. Then it will allocate a dynamic array of Assessments in the aptr pointer reference.
	//After allocating the memory, in a loop, it will read each record of the file into the Assessment elements (use the proper read overload for this).
	//This loop should stop either if the number of reads reaches the number of elements or if the read function fails.
	//When the loop is done compare the number of reads to the number of elements of the array. If the number is not a match,
	//free the Memory of the dynamic array (freeMem) and return zero, otherwise, return the size of the array.*/
	int read(Assessment*& aptr, FILE* fptr)
	{
		/// <summary>
		/// total temp
		/// </summary>
		/// <param name="aptr"></param>
		/// <param name="fptr"></param>
		/// <returns></returns>
		bool b = false;
		int firstVal = 0;
		int counter = 0;
		read(firstVal, fptr);
		aptr = new Assessment[firstVal];
		for (int i = 0; i < firstVal; i++)
		{
			b = read(aptr[i], fptr);
			if (b == true)
			{
				counter++;
			}
		}

		if (counter != firstVal)
		{
			freeMem(aptr, counter);
			return 0;
		}
		else
		{
			return counter;
		}
		
	}

}