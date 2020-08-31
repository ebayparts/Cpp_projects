#include <iostream>
using namespace std;

void findMax(int* first, int* second) {
	int Max = *first;
	if (*first < *second) {
		Max = *second;
	}
	cout << "Maximum value is " << Max << endl;
}


int main() {
	int Number, Number2;
	cout << "Enter first number for comparing: ->";
	cin >> Number;
	cout << "Enter second number for comparing: ->";
	cin >> Number2;
	findMax (&Number, &Number2);
	
	return 0;
}