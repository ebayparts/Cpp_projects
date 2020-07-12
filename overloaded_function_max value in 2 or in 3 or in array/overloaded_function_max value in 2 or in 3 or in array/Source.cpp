#include<iostream>
#include<Windows.h>
#include<string>
#include<ctime>
using namespace std;
int maxInArray = 0;
void findMax(int a, int b) {
	if (a > b) {
		cout << "max is" << a << endl;
	}
	else if (b > a) {
		cout << "max is" << b << endl;
	}
	else {
		cout << "first and second numbers are equal:" << a << " = " << b << endl;
	}
}
void findMax(int a, int b, int c) {
	if (a > b && a > c) {
		cout << "max is" << a << endl;
	}
	else if (b > a && b > c) {
		cout << "max is" << b << endl;
	}
	else if (c > a && c > b) {
		cout << "max is" << c << endl;
	}
	else {
		cout << "first and second and third numbers are equal:" << a << " = " << b << " = " << c << endl;
	}
}
void findMax(int array[], int size) {
	for (int i = 0; i < size; i++)
	{
		if (array[i] > array[maxInArray]) {
			maxInArray = i;
		}
	}
	cout << "Max number in Array is :" << array[maxInArray] << endl;
}
int main() {
	srand(time(NULL));
	const int size = 10;
	int array[size];
	for (int j = 0; j < size; j++)
	{
		array[j] = rand();
		cout << array[j] << " ";
	}
	cout << endl;
	findMax(5, 4);
	cout << endl;
	findMax(12, 3, 29);
	cout << endl;
	findMax(array, size);
	return 0;
}