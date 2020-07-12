#include<iostream>
#include"ctime"
using namespace std;
void bros(int kubik);
int res();
void main()
{
	char brosok;
	do
	{
		srand(time(NULL));
		cout << "Hello! Let's play dice!" << endl;
		cout << "The winner is the one with the highest average for five shots!" << endl;
		cout << "Let's go ... " << endl << endl;
		float total_chel = 0;
		float total_komp = 0;
		do
		{
			cout << "Let's play the sequence of shots? Press 1 to throw : -->>";
			cin >> brosok;
		} while (brosok != '1');
		int res_chel, res_komp;
		do
		{
			res_chel = res();
			cout << "Your result: " << res_chel << endl;
			res_komp = res();
			cout << "Computer result: " << res_komp << endl;
		} while (res_chel == res_komp);
		if (res_chel > res_komp)
		{
			cout << endl << "You start first :(" << endl;
			for (int i = 1; i <= 5; i++)
			{
				do
				{
					cout << "Press 1 to throw" << endl;
					cin >> brosok;
				} while (brosok != '1');
				cout << "You:" << endl;
				total_chel += res();
				cout << "Computer:" << endl;
				total_komp += res();
				cout << "Next move:" << endl;
			}
			cout << "Your average result (for 5 shots): " << total_chel / 5 << endl;
			cout << endl << "The average result of the computer (for 5 shots): " << total_komp / 5 << endl;
		}
		else
		{
			cout << endl << "Computer starts :)" << endl;
			for (int i = 1; i <= 5; i++)
			{
				cout << "I:" << endl;
				total_komp += res();
				do
				{
					cout << "Press 1 to throw" << endl;
					cin >> brosok;
				} while (brosok != '1');
				cout << "You:" << endl;
				total_chel += res();
				cout << "Next move:" << endl;
			}
			cout << "Your overall result (total points for 5 shots): " << total_chel << endl;
			cout << endl << "The total result of the computer (total points for 5 shots): " << total_komp << endl;
		}

		if (total_chel == total_komp)
		{
			cout << endl << endl << "DRAW!" << endl << endl;
		}
		else
		{
			if (total_chel > total_komp)
			{
				cout << endl << endl << "You win!" << endl << endl;
			}
			if (total_chel < total_komp)
			{
				cout << endl << endl << "I win" << endl << endl;
			}
		}
		cout << endl << "If you want to continue, press 1: ";
		cin >> brosok;
	} while (brosok == '1');
}

void bros(int kubik)
{
	switch (kubik)
	{
	case 1:
		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "*        *        *" << endl;
		cout << "*                 *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
		break;
	case 2:
		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*        *        *" << endl;
		cout << "*                 *" << endl;
		cout << "*        *        *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
		break;
	case 3:
		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*    *            *" << endl;
		cout << "*        *        *" << endl;
		cout << "*            *    *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
		break;
	case 4:
		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*                 *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
		break;
	case 5:
		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*        *        *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
		break;

	case 6:

		cout << "* * * * * * * * * *" << endl;
		cout << "*                 *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*    *      *     *" << endl;
		cout << "*                 *" << endl;
		cout << "* * * * * * * * * *" << endl;
		break;
	}
}
int res()
{
	int kubik_1 = rand() % 6 + 1;
	bros(kubik_1);
	int kubik_2 = rand() % 6 + 1;
	bros(kubik_2);
	int rezult;
	rezult = kubik_1 + kubik_2;
	cout << "Result: " << rezult << endl << "" << endl;
	return rezult;
}