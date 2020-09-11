#include<iostream>
#include<string>
using namespace std;

struct Answer {
	string name;
	bool isTrue;
};

struct Question {
	string name;
	int answerQuantity;
	Answer* answers;
};

struct Quiz {
	string name;
	int questionQuantity;
	Question* questions;
};

int countQuiz = 0; // quantity of done quizes
Quiz* quizList = new Quiz[countQuiz];

void showAllQuiz() {
	for (int i = 0; i < countQuiz; i++)
	{
		cout << i + 1 << ". " << quizList[i].name;
	}
	cout << endl;
}

void addNewQuiz(Quiz newQuiz) {
	Quiz* temp = new Quiz[countQuiz + 1];

	for (int i = 0; i < countQuiz; i++)
	{
		temp[i].name = quizList[i].name;
		for (int j = 0; j < quizList[i].questionQuantity; j++)
		{
			temp[i].questionQuantity = quizList[i].questionQuantity;
		}
	}



	for (int i = 0; i < newQuiz.questionQuantity; i++)  // adding questions and answer quantity
	{
		cin.ignore();
		cout << "Enter " << i + 1 << " question name: " << endl;
		cin >> newQuiz.questions[i].name;
		cout << "Enter " << i + 1 << " question answer quantity: " << endl;
		cin >> newQuiz.questions[i].answerQuantity;
		newQuiz.questions[i].answers = new Answer[newQuiz.questions[i].answerQuantity];

		for (int j = 0; j < newQuiz.questions[i].answerQuantity; j++) // adding answer names and true variant
		{
			cout << "Enter " << j + 1 << " answer: " << endl;
			cin >> newQuiz.questions[i].answers[j].name;
			int a = 0;
			cout << "Is this answer correct? (1 - yes, 0 - no)" << endl;
			cin >> a;
			if (a == 1) {
				newQuiz.questions[i].answers[j].isTrue = true;
			}
			else {
				newQuiz.questions[i].answers[j].isTrue = false;
			}
		}
	}
}

void menu() {
	int action = 0;
	cout << "1. Show all quizes" << endl;
	cout << "2. Add new quiz" << endl;
	cout << "3. Search quiz" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
	cout << "Select action from menu - >> _" << endl;
	cin >> action;

	switch (action) {
	case 1: {
		showAllQuiz();
	}break;
	case 2: {
		Quiz newQuiz;
		cout << "Enter victoruna name: " << endl;
		cin >> newQuiz.name;
		cout << "Enter questions quantity: " << endl;
		cin >> newQuiz.questionQuantity;
		newQuiz.questions = new Question[newQuiz.questionQuantity];
		addNewQuiz(newQuiz);
		countQuiz++;
	}break;
	case 3: {

	}break;
	case 4: {

	}break;
	case 5: {

	}break;
	}
}

int main() {

	menu();

	//cout << "Enter victoruna name: " << endl;
	//cin >> victoruna.name;
	//cout << "Enter questions quantity: " << endl;
	//cin >> victoruna.questionQuantity;
	//
	//for (int i = 0; i < victoruna.questionQuantity; i++)  // adding questions and answer quantity
	//{
	//	cout << "Enter " << i + 1 << " question name: " << endl;
	//	cin >> victoruna.questions[i].name;
	//	cout << "Enter " << i + 1 << " question answer quantity: " << endl;
	//	cin >> victoruna.questions[i].answerQuantity;
	//	for (int j = 0; j < victoruna.questions[i].answerQuantity; j++) // adding answer names and true variant
	//	{
	//		cout << "Enter " << j + 1 << " answer: " << endl;
	//		cin >> victoruna.questions[i].answers[j].name;
	//		cout << "Is this answer correct? (1 - yes, 2 - no)" << endl;
	//		cin >> victoruna.questions[i].answers[j].isTrue;
	//	}
	//}



	return 0;
}