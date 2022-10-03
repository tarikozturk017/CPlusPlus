/*
Student Name: Eray Sahin
Student ID: 156387201
Section: NRA
Date: 09-29-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Utils.h"


namespace sdds {
	class CC {//encapsulates a cc

		char* name;//notnull && >2 length
		short cvv;//3digit number
		short expMon;//between 1-12 not inclusive
		short expYear;//between 22-32 not inclusive
		unsigned long long cardNo;
		//prnt member function
		void prnNumber() const;
	public:
		//const char* my_itoa(int num, char* str);
		int validateDigitCounter(short int number)const;
		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;
		void set();//set to 0
		void cleanUp();
		void set(const char* cc_name,
		unsigned long long cc_no,
		short cvv, short expMon,
		short expYear);//setval
		bool isEmpty() const;
		bool read();
		void display(int row = 0) const;
	};
}