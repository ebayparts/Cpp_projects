#include <iostream>
using namespace std;

void showArray(int* ptrArray, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(ptrArray + i) << " ";
	}
}

void uniteArrays(int* ptrArray, int* ptrArray2, int* ptrArray3, int size) {
	for (int i = 0; i < size * 2; i++)
	{
		if (i < size) {
			*(ptrArray3 + i) = *(ptrArray + i);
		}
		else {
			*(ptrArray3 + i) = *(ptrArray2 + i - 10);
		}
	}
	for (int i = 0; i < size * 2 - 1; i++)
	{
		for (int j = 0; j < size * 2 - 1; j++)
		{
			if (*(ptrArray3 + j) > * (ptrArray3 + j + 1)) {
				int temp = *(ptrArray3 + j);
				*(ptrArray3 + j) = *(ptrArray3 + j + 1);
				*(ptrArray3 + j + 1) = temp;
			}
		}
	}
}

int main() {
	const int size = 10;
	int Number[size] = { 11,18,22,36,44,51,69,90,100,110 };
	int Number2[size] = { 2,4,6,8,10,12,14,16,18,20 };
	int Number3[size * 2];
	uniteArrays(Number, Number2, Number3, size);
	showArray(Number3, size * 2);
	return 0;
}