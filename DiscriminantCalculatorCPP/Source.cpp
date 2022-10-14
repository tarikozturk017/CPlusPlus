#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool myIsDigit(char letter) {
	return (letter - 48 >= 0 && letter - 48 <= 9);
}

string returnString() {
	string a;
	string beforePoint;
	string afterPoint;
	int counter = 0;
	cin >> a;
	while (a[counter] != '.') {
		if (myIsDigit(a[counter])) {
			beforePoint.push_back(a[counter]);

			counter++;
		}
		else {
			throw "Error! Not a digit.";
			break;
		}

	}	
	if (counter == 0) {
		throw "ERROR!";
	}
	counter++;
	while (a[counter] != '\0') {
		if (myIsDigit(a[counter])) {
			afterPoint.push_back(a[counter]);
			
		}
		else {
			throw "Error! Not a digit.";
			break;
		}
		counter++;
		
	}
	if (afterPoint.length() != 3) {
		throw "Error! Should be 3 characters long.";
	}
	
	a = beforePoint + "." + afterPoint;
	
	return a;
}

int calculateDiscriminant(int a, int b, int c) {
	int sonuc;

	sonuc = b * b - (4 * a * c);
	return sonuc;
}

vector<double> discResult(int a, int b, int c) {
	int sonuc = calculateDiscriminant(a, b, c);
	vector<double> returnValue;
	if (sonuc > 0) {
		
		double root1 = (-b + sqrt(calculateDiscriminant(a,b,c)) / 2 * a);
		double root2 = (-b - sqrt(calculateDiscriminant(a,b,c)) / 2 * a);
		returnValue.push_back(root1);
		returnValue.push_back(root2);

	}
	else if (sonuc == 0) {
		double root1;
		root1 = -b / 2 * a;
		returnValue.push_back(root1);
		
	}
	return returnValue;
}


int main() {

	double a, b, c;

	try
	{
		a = stod(returnString());
		b = stod(returnString());
		c = stod(returnString());
	}
	catch(...) 
	{
		cout << "ERROR!" << endl;
		return 1;
	}
	vector<double> newVector;
	newVector = discResult(a, b, c);
	if (newVector.size() == 0) {
		cout << "No result." << endl;
	}
	for (int i = 0; i < newVector.size(); i++) {
		cout << newVector[i] << endl;
	
	}


	return 0;
}