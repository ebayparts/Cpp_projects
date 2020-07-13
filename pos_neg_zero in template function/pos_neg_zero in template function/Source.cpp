#include<iostream>
#include<Windows.h>
#include<string>
#include<ctime>
using namespace std;

int pos = 0;
int neg = 0;
int zer = 0;

template <typename T>
void posNegZer(T array[], T size) {
	for (T i = 0; i < size; i++)
	{
		if (array[i] > 0) {
			pos++;
		}
		else if (array[i] < 0)
		{
			neg++;
		}
		else {
			zer++;
		}
	}
	cout << "Positive number count in Array is :" << pos << endl;
	cout << "Negative number count in Array is :" << neg << endl;
	cout << "Zero number count in Array is :" << zer << endl;
}

int main() {
	const int size = 10;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter array " << i + 1 << " value" << endl;
		cin >> array[i];
	}
	posNegZer(array, size);
}