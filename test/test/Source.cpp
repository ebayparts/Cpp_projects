#include <iostream>
using namespace std;
int action = 0;
const int N = 10;
string quizzesCollection[4][22][5];
int emptyQuiz = 0;		// number of next empty quiz;
int currentQuiz = 0;	// active quiz; 
int menu() {
	do {
		cout << "\nWelcome at our quiz!\n1. Show all quizzes names.\n2. Add new quiz.\n3. Take chanse to go through quiz.\nMake your choose:";
		cin >> action;
		switch (action) {
		case 1: {
			cout << "All quizzes list:" << endl;
			for (int i = 0; i < emptyQuiz; i++) { if (i == 0) { cout << endl; };cout << i + 1 << ". " << quizzesCollection[0][0][0] << endl; }
		}break;
		case 2: {
			cout << "Enter quiz name:" << endl;
			cin >> quizzesCollection[0][emptyQuiz * 22][0];
			for (int i = 0; i < 20;i += 2)
			{
				cout << "Enter " << i / 2 + 1 << " question: ";
				cin >> quizzesCollection[0][0][i + 1];
				cout << "Question number " << i/2 + 1 << ": " << quizzesCollection[0][0][(emptyQuiz * 22) + i + 1] << endl;
				for (int j = 0; j < 3; j++)
				{
					cout << "Enter " << j + 1 << " answer: ";
					cin >> quizzesCollection[j + 1][0][i + 1];
					cout << "Is it correct answer? (n - no / y - yes): ";
					cin >> quizzesCollection[j + 1][0][i + 2];
				}
			}
			emptyQuiz ++;
		}break;
		case 3: {
			for (int i = 0; i < emptyQuiz; i++)
			{
				cout << quizzesCollection[0][i * emptyQuiz * 22][0] << endl;
			}
			cout << "Chose your quiz:"<<"1 - "<< emptyQuiz;
			cin >> currentQuiz;
			for (int i = currentQuiz*22; i < (currentQuiz * 22)+20; i += 2)
			{
				cout << "Question "<< i - (currentQuiz * 22) << " : "<<quizzesCollection[0][currentQuiz * 22][i + 1];
			}
		}break;
		}
	} while (action != 5);
	return 0;
}
int main() {
	menu();
	return 0;
}