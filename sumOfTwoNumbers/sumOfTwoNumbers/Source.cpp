#include <iostream>
#include <string>
using namespace std;
int main() {
	char arr[100];
	cout << "Enter the equatation :" << endl;
	cin.getline(arr, 100);
	char firstNumber[100];
	char secondNumber[100];
	int a = 0, afterPlus = 0, b = 0;
	int c = 0;
	int j = 0;
	for (int i = 0; i < strlen(arr); i++) {
		if (afterPlus == 0) {
			firstNumber[j] = arr[i];
			j++;
		}
		if (arr[i] == '+') {
			a = atoi(firstNumber);
			j = 0;
			afterPlus = 1;
		}
		if (afterPlus == 1) {
			secondNumber[j] = arr[i];
			j++;
		}
		if (i == strlen(arr) - 1) {
			b = atoi(secondNumber);
		}
	}
	c = a + b;
	cout << a << " + " << b << " is equal = " << c;
}