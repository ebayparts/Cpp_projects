#include<iostream>
#include<time.h>
using namespace std;
void random(int* arr, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)

	{
		arr[i] = rand() % 100;
	}
}
void showArray(int* arr1, int size1) {
	for (int i = 0; i < size1; i++)
	{
		cout << arr1[i] << " ";
	}
}
void deleteElement(int*& arraySecond, int& size2, int index1) {
	int* temp = new int[size2];
	for (int i = 0; i < size2;i++)
	{
		if (i != index1) {
			temp[i] = arraySecond[i];
		}
	}
	delete[] arraySecond;
	size2;
	arraySecond = new int[size2 - 1];
	int j = 0;
	for (int i = 0; i < size2; i++)
	{
		if (i != index1) {
			arraySecond[j] = temp[i];
			j++;
		}
	}
	size2--;
}
void addElement(int*& arraySecond, int& size2, int index, int number) {
	int* temp = new int[size2 + 1];
	size2++;
	int j = 0;
	for (int i = 0; i < size2; i++)
	{
		if (i != index) {
			temp[i] = arraySecond[j];
			j++;
		}
		else {
			temp[i] = number;
		}
	}
	delete[] arraySecond;
	arraySecond = new int[size2];
	for (int i = 0; i < size2; i++)
	{
		arraySecond[i] = temp[i];
	}
	delete[] temp;
	temp = nullptr;
}
int main() {
	srand(time(NULL));
	int count = 0;
	int achion = 0;
	cout << "Enter size array -> ";
	cin >> count;
	int* ptr = new int[count];
	random(ptr, count);
	do
	{
		cout << "1. Show Array" << endl;
		cout << "2. Add element in specified place in array" << endl;
		cout << "3. Delete specified element in array" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "Chose achion (1-2-3-4)-> ";
		cin >> achion;
		int index = 0;
		switch (achion)
		{
		case 1: {
			showArray(ptr, count);
			cout << endl;
		}break;
		case 2: {
			int number = 0;
			cout << "Enter new elements for arr-> ";
			cin >> number;
			cout << "Enter index for adding elements-> ";
			cin >> index;
			addElement(ptr, count, index-1, number);
			cout << endl;
		}break;
		case 3: {
			showArray(ptr, count);
			cout << "Enter index for deleting element-> ";
			cin >> index;
			deleteElement(ptr, count, index-1);
			cout << endl;
		}break;
		default:
			cout << "Invalid number of achion";
			break;
		}
	} while (achion != 4);
	return 0;
}