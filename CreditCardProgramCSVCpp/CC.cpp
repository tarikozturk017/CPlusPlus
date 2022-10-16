

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
#include "CC.h"

using namespace std;
using namespace sdds;

int CC::validateDigitCounter(short int number)const {
	int a = 0;
	if (number > 0) {
		while (number != 0) {
			number /= 10;
			a++;
		}
	}
	return a;
}

bool CC::validate(const char* name,
	unsigned long long cardNo,
	short cvv,
	short expMon,
	short expYear)const {
	bool flag = false;
	if (!(name == nullptr) && strlen(name) > 2 &&
		(cardNo >= 4000000000000000 && cardNo <= 4099999999999999)
		&& validateDigitCounter(cvv) == 3
		&& (expMon >= 1 && expMon <= 12)
		&& (expYear >= 22 && expYear <= 32)) {
		flag = true;
	}
	return flag;
}

void CC::prnNumber() const {
	unsigned long long card = cardNo;
	unsigned long long divide[]{ 
		1000000000000,
		100000000,
		10000,
		1 };
	cout << " ";
	for (int i = 0; i < 4; i++) {
		int result = card / divide[i];
		card = card % divide[i];
		cout.width(4);
		cout.fill('0');
		cout << result;
		if(i != 3)
		{
			cout << result << " ";	
		}
		cout.fill(' ');
	}
}


void CC::set() {
	name = nullptr;
	expMon = 0;
	expYear = 0;
	cardNo = 0;
	cvv = 0;
}

bool CC::isEmpty() const {
	//name is empty
	return(name == nullptr);
}

void CC::cleanUp() {
	//if not empty, free.
	if (name != nullptr)
	{
		delete[] name;
	}
	set();
}

bool CC::read() {
	short expMon;
	short expYear;
	char max[71];
	unsigned long long cardNo;
	short cvv;

	cout << "Card holder name: ";
	cin.getline(max, 71);
	if (!cin) {
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	cout << "Credit card number: ";
	cin >> cardNo;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}
	cout << "Card Verification Value (CVV): ";
	cin >> cvv;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}

	cout << "Expiry month and year (MM/YY): ";
	cin.clear();
	cin >> expMon;
	cin.ignore();
	cin >> expYear;
	cin.ignore(1000, '\n');
	if (cin)
	{
		set(max, cardNo, cvv, expMon, expYear);
	}
	else {
		cin.clear();
	}
	if (isEmpty() == true) return false;
	return true;
}

void CC::set(const char* cc_name,
	unsigned long long cc_no,
	short cvv,
	short expMon,
	short expYear) {
	cleanUp();
	if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
		name = new char[strlen(cc_name) + 1];
		strcpy(name, cc_name, 71);
		this->expMon = expMon;
		this->expYear = expYear;
		this->cardNo = cc_no;
		this->cvv = cvv;
	}
}



void CC::display(int row) const {
	if (isEmpty() == true) 
	{
		cout << "Invalid Credit Card Record\n";
	}
	else if (row > 0)
	{
		char* val;
		val = new char[strlen(name) + 1];
		/// <summary>
		///val = new deleted val
		/// </summary>
		strcpy(val, name, 30);
		cout << "|";
		// 1ST
		cout.width(4);
		cout.fill(' ');
		cout.setf(ios::right);
		cout << row;
		cout.unsetf(ios::right);
		cout << " | ";
		// 2ND
		cout.width(30);
		cout.fill(' ');
		cout.setf(ios::left);
		cout << val; 
		cout << " ";
		cout.unsetf(ios::left);
		cout << "|";
		// 3RD
		prnNumber();
		cout << " | ";
		// 4TH
		cout << cvv;
		cout << " | ";
		// 5TH
		cout.width(2);
		cout.fill(' '); cout.setf(ios::right);
		cout << expMon << "/";
		cout.unsetf(ios::right);
		cout << expYear;
		cout << " |";
		// 6TH
		cout.setf(ios::fixed);
		cout << '\n';
		delete[] val;
	}
	else
	{
		cout << "Name: " << name << "\nCreditcard No:";
		prnNumber();
		cout << "\nCard Verification Value: " << cvv;
		cout << "\nExpiry Date: " << expMon << "/" << expYear << endl;
	}
}
