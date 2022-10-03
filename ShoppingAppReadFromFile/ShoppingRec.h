/***************************************
Student Name: Eray Sahin
Student E-mail: esahin2@myseneca.ca
Student ID: 156387201
Date: 09/15/2022
I have done all the coding by myselfand only copied the code that
my professor provided to complete my workshops and assignments.
**************************************/
#ifndef SDDS_SHOPPINGREC_H // replace with relevant names
#define SDDS_SHOPPINGREC_H


namespace sdds {
	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;

	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	// Your header file content goes here
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}



#endif