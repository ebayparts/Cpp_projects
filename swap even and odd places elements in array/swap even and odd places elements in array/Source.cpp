#include <iostream>
using namespace std;

void showArray(int* ptrArray, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(ptrArray + i) << " ";
	}
	cout << endl;
}

void swapParAndNepar(int* ptrArray, int size) {
	int indexMin, indexMax = 0;
	for (int i = 0; i < size; i++)
	{
		if (i > 0 & (i - 1) % 2 == 0) {
			int temp = *(ptrArray + i);
			*(ptrArray + i) = *(ptrArray + (i - 1));
			*(ptrArray + (i - 1)) = temp;
		}
	}
}

int main() {
	const int size = 10;
	int Numbers[size] = { -10, 55,23,24,-1,-23,11,0,3,1 };
	showArray(Numbers, size);
	swapParAndNepar(Numbers, size);
	showArray(Numbers, size);
	return 0;
}