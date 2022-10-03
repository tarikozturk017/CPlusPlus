/*
Student Name: Eray Sahin
Student ID: 156387201
Section: NRA
Date: 09-25-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {


	struct PostalCode {
		char* code;
		int population;
	};
	void sortPostCodes();
	bool load(const char filename[]);
	//newf
	bool load(PostalCode& post);
	//newf
	void display(const PostalCode& code);
	void display();
	void deallocateMemory();

}
#endif