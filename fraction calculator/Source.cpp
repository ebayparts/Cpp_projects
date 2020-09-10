#include <iostream>
#include <string>
using namespace std;

int numeratorGeneral, denominatorGeneral;
int action = 1;
int gCD = 1; // greatest common divisor
float floatingResult;

struct Fraction {
	int numerator;
	int denominator;
};
Fraction fraction1, fraction2, fractionResult;

void greatCommonDivisor(int dividend1, int dividend2) {
	if (dividend1 < 0) {
		dividend1 *= (-1);
	}
	if (dividend2 < 0) {
		dividend2 *= (-1);
	}
	if (dividend1 < dividend2) {
		for (int i = dividend1; i > 0; i--)
		{
			if (dividend1 % i == 0 && dividend2 % i == 0) {
				gCD = i;
				i = 0;
			}
		}
	}
	else {
		for (int i = dividend2; i > 0; i--)
		{
			if (dividend2 % i == 0 && dividend1 % i == 0) {
				gCD = i;
				i = 0;
			}
		}
	}
};

void showResult(int operation) {
	string operationSign;
	string resultSign;

	if (operation == 1) {
		operationSign = '+';
	}
	else if (operation == 2) {
		operationSign = '-';
	}
	else if (operation == 3) {
		operationSign = 'X';
	}
	else if (operation == 4) {
		operationSign = ':';
	}
	if (fractionResult.numerator < 0 && fractionResult.denominator > 0 || fractionResult.numerator > 0 && fractionResult.denominator < 0) {
		resultSign = '-';
	}
	else {
		resultSign = ' ';
	}
	if (fractionResult.denominator != 1)
	{
		if (fractionResult.denominator < 0) {
			fractionResult.denominator *= (-1);
		}
		if (fractionResult.numerator < 0) {
			fractionResult.numerator *= (-1);
		}
		if (fractionResult.numerator < fractionResult.denominator) // checking for proper fractions
		{
			cout << " " << fraction1.numerator << "\t\t  " << fraction2.numerator << "\t---    " << fractionResult.numerator << endl;
			cout << "----\t  " << operationSign << "\t ----\t    " << resultSign << " -----" << endl;
			cout << " " << fraction1.denominator << "\t\t  " << fraction2.denominator << "\t---    " << fractionResult.denominator << endl;
		}
		else if (fractionResult.numerator > fractionResult.denominator) {
			cout << " " << fraction1.numerator << "\t\t  " << fraction2.numerator << "\t---    " << fractionResult.numerator % fractionResult.denominator << endl;
			cout << "----\t  " << operationSign << "\t ----\t   " << resultSign << " " << fractionResult.numerator / fractionResult.denominator << " -----" << endl;
			cout << " " << fraction1.denominator << "\t\t  " << fraction2.denominator << "\t---    " << fractionResult.denominator << endl;
		}
		else if (fractionResult.numerator == fractionResult.denominator) {
			cout << " " << fraction1.numerator << "\t\t  " << fraction2.numerator << "\t---    " << endl;
			cout << "----\t  " << operationSign << "\t ----\t   " << resultSign << " " << 1 << endl;
			cout << " " << fraction1.denominator << "\t\t  " << fraction2.denominator << "\t---    " << endl;
		}
	}
	else {
		cout << " " << fraction1.numerator << "\t\t  " << fraction2.numerator << "\t---    " << endl;
		cout << "----\t  " << operationSign << "\t ----\t\t" << fractionResult.numerator << endl;
		cout << " " << fraction1.denominator << "\t\t  " << fraction2.denominator << "\t---    " << endl;
	}
}

void calc(int numerator1, int denominator1, int numerator2, int denominator2, int action) {
	//finding greatest common divisor = gCD;
	greatCommonDivisor(denominator1, denominator2);
	int operationFraction = action;
	if (action == 2) {
		operationFraction = -1;
	}
	fractionResult.denominator = (denominator1 * denominator2) / gCD;
	fractionResult.numerator = (fractionResult.denominator / denominator1) * numerator1 + (fractionResult.denominator / denominator2) * numerator2 * operationFraction;
	if (action == 3) {
		fractionResult.denominator = denominator1 * denominator2;
		fractionResult.numerator = numerator1 * numerator2;
	}
	if (action == 4) {
		fractionResult.numerator = numerator1 * denominator2;
		fractionResult.denominator = denominator1 * numerator2;
	}
	greatCommonDivisor(fractionResult.denominator, fractionResult.numerator);
	fractionResult.denominator = fractionResult.denominator / gCD;
	fractionResult.numerator = fractionResult.numerator / gCD;
	showResult(action);
}

void enterData() {
	cout << "Example of fraction equatation: " << endl;
	cout << endl;
	cout << "num_1\t\tnum_2\t---" << endl;
	cout << "----\t  +\t----\t\tRESULT" << endl;
	cout << "den_1\t\tden_2\t---" << endl;
	cout << endl;
	cout << "Enter numerator of first fraction: - >";
	cin >> fraction1.numerator;
	cout << "Enter denumerator of first fraction: - >";
	cin >> fraction1.denominator;
	cout << "Enter numerator of second fraction: - >";
	cin >> fraction2.numerator;
	cout << "Enter denumerator of second fraction: - >";
	cin >> fraction2.denominator;
	cout << endl << "So the result of all this is: " << endl;
	calc(fraction1.numerator, fraction1.denominator, fraction2.numerator, fraction2.denominator, action);
}

int main() {
	do
	{
		cout << endl;
		cout << "Magical Fraction Calculator Salute You!" << endl;
		cout << "Chose arithmetic operation:" << endl;
		cout << "1. Addition (+)" << endl;
		cout << "2. Substraction (-)" << endl;
		cout << "3. Multiplication (*)" << endl;
		cout << "4. Division(:)" << endl;
		cout << "5. Exit from Magical Fraction Calculator" << endl;
		cout << endl;
		cout << "Select action from menu - >> _" << endl;
		cin >> action;
		switch (action)
		{
		case 1: {
			enterData();
		}break;

		case 2: {
			enterData();
		}break;

		case 3: {
			enterData();
		}break;

		case 4: {
			enterData();
		}break;

		case 5: {
			cout << "Good bye!" << endl;
		}break;

		default: {
			cout << "Error: Please, select action from menu!" << endl;
		}break;
		}
	} while (action != 5);
	return 0;
}