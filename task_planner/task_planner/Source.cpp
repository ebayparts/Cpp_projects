#include<iostream>
#include<string>
using namespace std;

const int sizePlanner = 20;
string planner[sizePlanner];
string planPriority[sizePlanner];
int currentIndex = 0; //free space in planner
int planDate[sizePlanner][3]; // array with dates of all tasks
int temp = 0;
string tempstring;
// створимо додаткові масиви які будуть копіюватись при введенні і сортуватись при виведенні

string plannerCopy[sizePlanner];
string planPriorityCopy[sizePlanner];
int planDateCopy[sizePlanner][3];

void showTasks() {
	bool isEmpty = true;
	for (int i = 0; i < currentIndex; i++) //вивести всі 
	{
		if (planDate[i][0] != 0) {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2];
			if (planPriority[i] == "c")
				cout << " --  high priotity" << endl;
			else if (planPriority[i] == "b")
				cout << " --  medium priority" << endl;
			else if (planPriority[i] == "a")
				cout << " --  low priority" << endl;
		}
		isEmpty = false;
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void sortTasksbyPriority() {
	bool isEmpty = true;
	for (int i = 0; i < sizePlanner; i++) //вивести спочатку всі з С важливістю
	{
		if (planPriority[i] == "c") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  high priotity" << endl;
			isEmpty = false;
		}
	}
	for (int i = 0; i < sizePlanner; i++) //вивести всі з b важливістю
	{
		if (planPriority[i] == "b") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  medium priority" << endl;
			isEmpty = false;
		}
	}
	for (int i = 0; i < sizePlanner; i++) //вивести всі з a важливістю
	{
		if (planPriority[i] == "a") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  low priority" << endl;
			isEmpty = false;
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void sortTasksbyDate() {			// sorting arrays copy 

	bool isEmpty = true;
	for (int i = 0; i < currentIndex; i++)
	{
		for (int j = 0; j < currentIndex; j++)
		{
			if (planDateCopy[j][2] > planDateCopy[i][2]) {		/// по роках
				temp = planDateCopy[i][2];						// міняємо роки	
				planDateCopy[i][2] = planDateCopy[j][2];
				planDateCopy[j][2] = temp;
				temp = planDateCopy[i][1];						//місяці
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp;
				temp = planDateCopy[i][0];						//дні
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
			else if (planDateCopy[j][1] > planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {			/// по роках
				temp = planDateCopy[i][1];						//місяці
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp;
				temp = planDateCopy[i][0];						//дні
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
			else if (planDateCopy[j][0] > planDateCopy[i][0] && planDateCopy[j][1] == planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {		/// по дням
				temp = planDateCopy[i][0];						//дні
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
		}
	}

	for (int i = 0; i < currentIndex; i++)
	{
		if (planDateCopy[i][0] != 0) {
			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
			if (planPriorityCopy[i] == "c")
				cout << " --  high priotity" << endl;
			else if (planPriorityCopy[i] == "b")
				cout << " --  medium priority" << endl;
			else if (planPriorityCopy[i] == "a")
				cout << " --  low priority" << endl;
			bool isEmpty = false;
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void sortTaskABC() { // sorting arrays copy 
	bool isEmpty = true;
	int lenA, lenB, lenLow; // adding length of comparing strings
	int temp, temp1, temp2; // temporary variable to store the date
	string tempstring;		// temporary variable to store the name
	lenLow = plannerCopy[0].length();
	for (int i = 0; i < currentIndex; i++)
	{
		if (plannerCopy[i].length() < lenLow) {
			lenLow = plannerCopy[i].length();
		}
	}
	for (int i = 0; i < currentIndex; i++)
	{
		for (int j = i + 1; j < currentIndex; j++)
		{
			if (plannerCopy[i][0] > plannerCopy[j][0]) {	//міняємо місцями якщо перша буква задачі що стоїть вище, в алфафіті стоїть пізніше
				tempstring = plannerCopy[i];					//назву
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
				temp = planDateCopy[i][0];						//дні
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				temp1 = planDateCopy[i][1];						//місяці
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp1;
				temp2 = planDateCopy[i][2];						//роки
				planDateCopy[i][2] = planDateCopy[i][2];
				planDateCopy[i][2] = temp2;
			}
			else if (plannerCopy[i][0] == plannerCopy[j][0]) {
				for (int m = 0; m < lenLow;)
				{
					if (plannerCopy[i][m] == plannerCopy[j][m]) {
						m++;
					}
					else if (plannerCopy[i][m] > plannerCopy[j][m]) {//міняємо місцями якщо перша буква задачі що стоїть вище, в алфафіті стоїть пізніше
						tempstring = plannerCopy[i];					//назву
						plannerCopy[i] = plannerCopy[j];
						plannerCopy[j] = tempstring;
						temp = planDateCopy[i][0];						//дні
						planDateCopy[i][0] = planDateCopy[j][0];
						planDateCopy[j][0] = temp;
						temp1 = planDateCopy[i][1];						//місяці
						planDateCopy[i][1] = planDateCopy[j][1];
						planDateCopy[j][1] = temp1;
						temp2 = planDateCopy[i][2];						//роки
						planDateCopy[i][2] = planDateCopy[i][2];
						planDateCopy[i][2] = temp2;
						m = lenLow;
					}
					else if (plannerCopy[i][m] < plannerCopy[j][m]) {
						m = lenLow;
					}
				}
			}
		}
	}
	for (int i = 0; i < currentIndex; i++)
	{
		if (planDateCopy[i][0] != 0) {
			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
			if (planPriorityCopy[i] == "c")
				cout << " --  high priotity" << endl;
			else if (planPriorityCopy[i] == "b")
				cout << " --  medium priority" << endl;
			else if (planPriorityCopy[i] == "a")
				cout << " --  low priority" << endl;
			isEmpty = false;
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}
void addtask(string nameOftask, int date, string priority) {
	int day, month, year;
	year = date % 10000;
	day = date / 1000000;
	month = (date / 10000) % 100;
	if (currentIndex < sizePlanner) {			//	fulfilling two copies of array
		planner[currentIndex] = nameOftask;
		planDate[currentIndex][0] = day;
		planDate[currentIndex][1] = month;
		planDate[currentIndex][2] = year;
		planPriority[currentIndex] = priority;
		plannerCopy[currentIndex] = nameOftask;
		planDateCopy[currentIndex][0] = day;
		planDateCopy[currentIndex][1] = month;
		planDateCopy[currentIndex][2] = year;
		planPriorityCopy[currentIndex] = priority;
		currentIndex++;
	}
	else {
		cout << "planner is full" << endl;
	}
	cout << endl;
}

void removeTask(int indexOftask) {
	planner[indexOftask] = "";
	string tempArray[sizePlanner];
	int tempIndex = 0;
	for (string item : planner)
	{
		if (item != "") {
			tempArray[tempIndex] = item;
			tempIndex++;
		}
	}
	for (int i = 0; i < sizePlanner; i++)
	{
		planner[i] = tempArray[i];
	}
	cout << endl;
}

void  managerTasks() {
	int action = 0;
	do
	{
		cout << "1.Show all tasks" << endl;
		cout << "2.Remove task" << endl;
		cout << "3.Add task" << endl;
		cout << "4.Exit" << endl;
		cout << endl;
		cout << "Select action->_";
		cin >> action;
		switch (action)
		{
		case 1: {
			action = 0;
			system("cls");
			cout << "What sorting would you prefer?" << endl;
			cout << "1. By priority." << endl;
			cout << "2. By date. " << endl;
			cout << "3. Show as added. " << endl;
			cout << "4. In alphabet order. " << endl;
			cout << endl;
			cout << "Select action->_";
			cin >> action;
			switch (action)
			{
			case 1: {
				system("cls");
				sortTasksbyPriority();
			}break;

			case 2: {
				system("cls");
				sortTasksbyDate();
			}break;

			case 3: {
				system("cls");
				showTasks();
			}break;
			case 4: {
				system("cls");
				sortTaskABC();
			}break;
			}
			action = 0;
		}break;
		case 2: {
			system("cls");
			int tempNumber = 0;
			cout << "Enter number task for delete: ";
			cin >> tempNumber;
			removeTask(tempNumber - 1);
		}break;
		case 3: {
			system("cls");
			string temp, temp3;
			int temp2;
			cout << "Enter event name: ";
			cin.ignore();
			getline(cin, temp);
			cout << "Enter date in format (DDMMYYYY) :";
			cin >> temp2;
			cout << "Enter event priority: ";
			cin >> temp3;
			addtask(temp, temp2, temp3);
		}break;
		case 4: {
			cout << "Goodbye" << endl;
		}break;
		}
	} while (action != 4);
}
int main() {
	managerTasks();
	return 0;
}
