#include<iostream>
#include<Windows.h>
#include<string>
#include<ctime>
using namespace std;

int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int daysInMonthLY[12]={ 31,29,31,30,31,30,31,31,30,31,30,31 }; // LY -leap year 
int d1, m1, year1, d2, m2, year2;

void duration(int d1, int m1, int year1, int d2, int m2, int y2) {

	int diff = 0;
	if (year1 == year2 && year1%4==0) {//тривал≥сть дн≥в в д≥апазон≥ одного високосного року
		for (int i = m1; i < m2 - 1; i++)
		{
			diff = diff + daysInMonthLY[i];
		}
			diff = diff + d2 + (daysInMonthLY[m1 - 1] - d1); // додаЇмо дн≥ початкового та к≥нцевого м≥с€ц≥в
	}
	else if (year1 == year2 && year1 % 4 != 0) {//тривал≥сть дн≥в в д≥апазон≥ одного невисокосного року
		for (int i = m1; i < m2 - 1; i++)
		{
			diff = diff + daysInMonth[i];
		}
		diff = diff + d2 + (daysInMonth[m1 - 1] - d1); // додаЇмо дн≥ початкового та к≥нцевого м≥с€ц≥в
	}
	else if (year2 > year1) {
		if (year1 % 4 == 0) { /////к≥льк≥сть дн≥в до к≥нц€ високосного року
			for (int i = m1; i < 12; i++)
			{
				diff = diff + daysInMonthLY[i];
			}
			diff = diff + (daysInMonthLY[m1 - 1] - d1);
		}
		else {///к≥льк≥сть дн≥в до к≥нц€ невисокосного року
			for (int i = m1; i < 12; i++)
			{
				diff = diff + daysInMonth[i];
			}
			diff = diff + (daysInMonth[m1 - 1] - d1);
		}
		if (year2 % 4 == 0) {/// к≥льк≥сть дн≥в з початку високосного року
			for (int j = 0; j < m2 - 1; j++)
			{
				diff = diff + daysInMonthLY[j];
			}
			diff = diff + d2;
		}
		else {/// к≥льк≥сть дн≥в з початку невисокосного року
			for (int j = 0; j < m2 - 1; j++)
			{
				diff = diff + daysInMonth[j];
			}
			diff = diff + d2;
		}
		for (int k = year1 + 1; k < year2; k++) /// дн≥ кожного року в €ких не рахуЇмо р≥к початку ≥ р≥к зак≥нченн€
		{
			if (k % 4 == 0) {
				for (int l = 0; l < 12; l++)
				{
					diff = diff + daysInMonthLY[l];
				}
			}
			else {
				for (int l = 0; l < 12; l++)
				{
					diff = diff + daysInMonth[l];
				}
			}
		}
	}
	cout << "difference between days:" << diff << endl;
}


int main() {

	cout << "Enter date that duration starts from: (in format DD MM YYYY)" << endl;
	cin >> d1 >> m1 >> year1;

	cout << "Enter date that duration ends in: (in format DD MM YYYY)" << endl;
	cin >> d2 >> m2 >> year2;

	duration(d1, m1, year1, d2, m2, year2);


	return 0;
}
