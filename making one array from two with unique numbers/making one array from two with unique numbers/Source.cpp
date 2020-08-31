#include <iostream>
#include <ctime>
using namespace std;

void showArray(int* ptrArray, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *(ptrArray + i) << " ";
	}
	cout << endl;
}

void uniqueArray(int* arrayA, int* arrayB, int m, int n) {
	int newM = m;
	int* tempArrayA = new int[m];
	for (int i = 0; i < m; i++) // copying array A
	{
		tempArrayA[i] = arrayA[i];
	}
	for (int i = 0; i < n; i++) //checking if new tempArrayA is unique from array B
	{
		for (int j = 0; j < newM; j++)
		{
			if (tempArrayA[j] == arrayB[i]) {
				newM--;
				for (int k = j; k < newM; k++)
				{
					tempArrayA[k] = tempArrayA[k + 1];
				}
			}
		}
	}
	m = newM;
	arrayA = new int[m];
	cout << "New array A is:" << endl;
	for (int i = 0; i < m; i++) // rewriting new array A
	{
		arrayA[i] = tempArrayA[i];
		cout << arrayA[i] << " ";
	}
	delete[] tempArrayA;
}

int main() {
	srand(time(NULL));
	int m, n;
	cout << "Enter elements quantity in array A : - >";
	cin >> m;
	cout << "Enter elements quantity in array B : - >";
	cin >> n;
	int* arrayA = new int[m];
	int* arrayB = new int[n];
	for (int i = 0; i < m; i++)
	{
		arrayA[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		arrayB[i] = rand() % 100;
	}
	showArray(arrayA, m);
	showArray(arrayB, n);
	uniqueArray(arrayA, arrayB, m, n);
	return 0;
}