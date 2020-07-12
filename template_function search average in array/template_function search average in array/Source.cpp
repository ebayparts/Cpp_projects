#include<iostream>
#include<Windows.h>
#include<string>
#include<ctime>
using namespace std;
int maxInArray = 0;
template <typename T>
void findMax(T array[], T size) {
	for (T i = 0; i < size; i++)
	{
		if (array[i] > array[maxInArray]) {
			maxInArray = i;
		}
	}
	cout << "Max number in Array is :" << array[maxInArray] << endl;
}

int main() {
	const int size = 10;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter array " << i + 1 << "value" << endl;
		cin >> array[i];
	}
	findMax(array, size);
	return 0;
}