#include <iostream>
using namespace std;

void findPosOrNeg(int* value) {
	if (*value < 0) {
		cout << "Your value is negative!" << endl;
	}
	else if (*value > 0) {
		cout << "Your value is positive!" << endl;
	}
	else
	{
		cout << "Your value is zero!" << endl;
	}
}

int main() {
	int value;
	cout << "Enter number: ->";
	cin >> value;
	findPosOrNeg(&value);
	return 0;
}