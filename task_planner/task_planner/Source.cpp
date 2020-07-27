#include <iostream>
using namespace std;

const int sizePlanner = 20;
string planner[sizePlanner];
string planPriority[sizePlanner];
int currentIndex = 0;				//	index of free space in planner
int planDate[sizePlanner][3];		//	array with dates for all tasks
int temp = 0;						//	temp variable for changing elements in array
string tempstring;					//	тут € шось напишу ≥ по€сню шо це за зм≥нна, а пот≥м прочитаю десь в код≥
//temp variable for changing string elements
string plannerCopy[sizePlanner];			//	additional variable copy of array for sorting original array
string planPriorityCopy[sizePlanner];		//	additional variable copy of array for sorting original array
int planDateCopy[sizePlanner][3];			//	additional variable copy of array for sorting original array

bool isEmpty = true;			//	variable need for checking if planner is empty

int sortPriority() {			//	show planner sorting by priority
	for (int i = 0; i < sizePlanner; i++) //вивести спочатку вс≥ з — важлив≥стю
	{
		if (planPriority[i] == "c") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  high priotity" << endl;
			isEmpty = false;
		}
	}
	for (int i = 0; i < sizePlanner; i++) //вивести вс≥ з b важлив≥стю
	{
		if (planPriority[i] == "b") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  medium priority" << endl;
			isEmpty = false;
		}
	}
	for (int i = 0; i < sizePlanner; i++) //вивести вс≥ з a важлив≥стю
	{
		if (planPriority[i] == "a") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  low priority" << endl;
			isEmpty = false;
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
};

int sortDate() {				//	show planner sorting by date
	bool isEmpty = true;
	for (int i = 0; i < currentIndex; i++)
	{
		for (int j = 0; j < currentIndex; j++)
		{
			if (planDateCopy[j][2] > planDateCopy[i][2]) {		/// по роках
				temp = planDateCopy[i][2];						// м≥н€Їмо роки	
				planDateCopy[i][2] = planDateCopy[j][2];
				planDateCopy[j][2] = temp;
				temp = planDateCopy[i][1];						//м≥с€ц≥
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp;
				temp = planDateCopy[i][0];						//дн≥
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
			else if (planDateCopy[j][1] > planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {			/// по роках
				temp = planDateCopy[i][1];						//м≥с€ц≥
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp;
				temp = planDateCopy[i][0];						//дн≥
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
			else if (planDateCopy[j][0] > planDateCopy[i][0] && planDateCopy[j][1] == planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {		/// по дн€м
				temp = planDateCopy[i][0];						//дн≥
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
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
};

int sortAsAdded() {				//	show planner as added
	for (int i = 0; i < currentIndex; i++) 
	{
		if (planDate[i][2] != 0) {
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
};


void sortInsertionAsc(int array[]) {
	int temp = 0; // temporary variable to store the element of array
	int indexPrev = 0; //variable to store previous element values
	for (int i = 0; i < sizePlanner; i++)
	{
		temp = array[i];	//assign the current element to the temporary change
		indexPrev = i - 1;	// set the index of the previous value

		while (indexPrev >= 0 && array[indexPrev] > temp) //goes as long as the previous index! = 0 and the previous element is greater than the current one
		{
			array[indexPrev + 1] = array[indexPrev];
			array[indexPrev] = temp;
			indexPrev--;
		}
	}
}





int sortAlphabetically() {		//	show planner sorting alphabetically
	bool isEmpty = true;
	int lenA, lenB, lenLow; // adding length of comparing strings
	for (int i = 0; i < currentIndex; i++)
	{
		for (int j = i; j < currentIndex; j++)
		{
			string a = plannerCopy[i];		//variable for each word in arrays
			string b = plannerCopy[j];
			lenA = plannerCopy[i].length();
			lenB = plannerCopy[j].length();
			if (lenA > lenB) {				//finding shortest word
				lenLow = lenB;
			}
			else {
				lenLow = lenA;
			}
			//зробити так щоб пор≥внювало першу букву - €кщо однаков≥ - хай другу пор≥внюЇ

			for (int l = 0; l < lenLow;)
			{
				//cout << "lenLow = "<< lenLow<<" ,l="<<l  << endl;////////////////////////
				if (a[l] == b[l]) {
					l++;
				}
				else if (a[l] > b[l]) {
					temp = planDateCopy[i][2];						// м≥н€Їмо роки	
					planDateCopy[i][2] = planDateCopy[j][2];
					planDateCopy[j][2] = temp;
					temp = planDateCopy[i][1];						//м≥с€ц≥
					planDateCopy[i][1] = planDateCopy[j][1];
					planDateCopy[j][1] = temp;
					temp = planDateCopy[i][0];						//дн≥
					planDateCopy[i][0] = planDateCopy[j][0];
					planDateCopy[j][0] = temp;
					tempstring = plannerCopy[i];					//назву
					plannerCopy[i] = plannerCopy[j];
					plannerCopy[j] = tempstring;
					l = lenLow;
				}
			}

		}
	}
	for (int i = 0; i < sizePlanner; i++)
	{
		if (planDateCopy[i][0] != 0) {
			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
			if (planPriorityCopy[i] == "c")
				cout << " --  high priotity" << endl;
			else if (planPriorityCopy[i] == "b")
				cout << " --  medium priority" << endl;
			else if (planPriorityCopy[i] == "a")
				cout << " --  low priority" << endl;
		}
		isEmpty = false;
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
};

int removeTask(){

};				
int addTask() {

};




int menu() {
	int action=0;
	do {
		cout<<"1. Show all tasks."<<endl;
		cout<<"2. Remove task."<<endl;
		cout<<"3. Add task."<<endl;
		cout<<"4. Exit."<<endl;
		cout << "make your chose:" << endl;
		cin >> action;
		switch (action) {
			case 1:{
				cout<<"How would you like to sort tasks?"<<endl;
				cout<<"1. By priority."<<endl;
				cout<<"2. By date."<<endl;
				cout<<"3. As originally added."<<endl;
				cout << "4. Sort alphabetically." << endl;
				cin >> action;
				switch (action) {
				case 1: {
					sortPriority();
				}break;
				case 2: {
					sortDate();
				}break;
				case 3: {
					sortAsAdded();
				}break;
				case 4: {
					sortAlphabetically();
				}break;

				}
			}break;
			case 2:{
				removeTask();
			}break;
			case 3:{
				addTask();
			}break;
			case 4:{
				cout << "Have a nice day!" << endl;
			}break;
		}
	} 
	while (action==4);
}



int main() {

	menu();

}





//
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//const int sizePlanner = 20;
//string planner[sizePlanner];
//string planPriority[sizePlanner];
//int currentIndex = 0; //free space in planner
//int planDate[sizePlanner][3]; // array with dates of all tasks
//int temp = 0;
//string tempstring;
//// створимо додатков≥ масиви €к≥ будуть коп≥юватись при введенн≥ ≥ сортуватись при виведенн≥
//
//string plannerCopy[sizePlanner];
//string planPriorityCopy[sizePlanner];
//int planDateCopy[sizePlanner][3];
//
//void showTasks() {
//	bool isEmpty = true;
//	for (int i = 0; i < currentIndex; i++) //вивести вс≥ 
//	{
//		if (planDate[i][0] != 0) {
//			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2];
//			if (planPriority[i] == "c")
//				cout << " --  high priotity" << endl;
//			else if (planPriority[i] == "b")
//				cout << " --  medium priority" << endl;
//			else if (planPriority[i] == "a")
//				cout << " --  low priority" << endl;
//		}
//		isEmpty = false;
//	}
//	if (isEmpty == true) {
//		cout << "List is empty!" << endl;
//	}
//}
//
//void sortTasksbyPriority() {
//	bool isEmpty = true;
//	for (int i = 0; i < sizePlanner; i++) //вивести спочатку вс≥ з — важлив≥стю
//	{
//		if (planPriority[i] == "c") {
//			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  high priotity" << endl;
//			isEmpty = false;
//		}
//	}
//	for (int i = 0; i < sizePlanner; i++) //вивести вс≥ з b важлив≥стю
//	{
//		if (planPriority[i] == "b") {
//			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  medium priority" << endl;
//			isEmpty = false;
//		}
//	}
//	for (int i = 0; i < sizePlanner; i++) //вивести вс≥ з a важлив≥стю
//	{
//		if (planPriority[i] == "a") {
//			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  low priority" << endl;
//			isEmpty = false;
//		}
//	}
//	if (isEmpty == true) {
//		cout << "List is empty!" << endl;
//	}
//}
//
//void sortTasksbyDate() {			// sorting arrays copy 
//
//	bool isEmpty = true;
//	for (int i = 0; i < currentIndex; i++)
//	{
//		for (int j = 0; j < currentIndex; j++)
//		{
//			if (planDateCopy[j][2] > planDateCopy[i][2]) {		/// по роках
//				temp = planDateCopy[i][2];						// м≥н€Їмо роки	
//				planDateCopy[i][2] = planDateCopy[j][2];
//				planDateCopy[j][2] = temp;
//				temp = planDateCopy[i][1];						//м≥с€ц≥
//				planDateCopy[i][1] = planDateCopy[j][1];
//				planDateCopy[j][1] = temp;
//				temp = planDateCopy[i][0];						//дн≥
//				planDateCopy[i][0] = planDateCopy[j][0];
//				planDateCopy[j][0] = temp;
//				tempstring = plannerCopy[i];
//				plannerCopy[i] = plannerCopy[j];
//				plannerCopy[j] = tempstring;
//			}
//			else if (planDateCopy[j][1] > planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {			/// по роках
//				temp = planDateCopy[i][1];						//м≥с€ц≥
//				planDateCopy[i][1] = planDateCopy[j][1];
//				planDateCopy[j][1] = temp;
//				temp = planDateCopy[i][0];						//дн≥
//				planDateCopy[i][0] = planDateCopy[j][0];
//				planDateCopy[j][0] = temp;
//				tempstring = plannerCopy[i];
//				plannerCopy[i] = plannerCopy[j];
//				plannerCopy[j] = tempstring;
//			}
//			else if (planDateCopy[j][0] > planDateCopy[i][0] && planDateCopy[j][1] == planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {		/// по дн€м
//				temp = planDateCopy[i][0];						//дн≥
//				planDateCopy[i][0] = planDateCopy[j][0];
//				planDateCopy[j][0] = temp;
//				tempstring = plannerCopy[i];
//				plannerCopy[i] = plannerCopy[j];
//				plannerCopy[j] = tempstring;
//			}
//		}
//	}
//
//	for (int i = 0; i < currentIndex; i++)
//	{
//		if (planDateCopy[i][0] != 0) {
//			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
//			if (planPriorityCopy[i] == "c")
//				cout << " --  high priotity" << endl;
//			else if (planPriorityCopy[i] == "b")
//				cout << " --  medium priority" << endl;
//			else if (planPriorityCopy[i] == "a")
//				cout << " --  low priority" << endl;
//		}
//	}
//	if (isEmpty == true) {
//		cout << "List is empty!" << endl;
//	}
//}
//
//void sortTaskABC() { // sorting arrays copy 
//	bool isEmpty = true;
//	int lenA, lenB, lenLow; // adding length of comparing strings
//	for (int i = 0; i < currentIndex; i++)
//	{
//		for (int j = i; j < currentIndex; j++)
//		{
//			string a = plannerCopy[i];		//variable for each word in arrays
//			string b = plannerCopy[j];
//			lenA = plannerCopy[i].length();
//			lenB = plannerCopy[j].length();
//			if (lenA > lenB) {				//finding shortest word
//				lenLow = lenB;
//			}
//			else {
//				lenLow = lenA;
//			}
//			//зробити так щоб пор≥внювало першу букву - €кщо однаков≥ - хай другу пор≥внюЇ
//
//			for (int l = 0; l < lenLow;)
//			{
//				//cout << "lenLow = "<< lenLow<<" ,l="<<l  << endl;////////////////////////
//				if (a[l] == b[l]) {
//					l++;
//				}
//				else if (a[l] > b[l]) {
//					temp = planDateCopy[i][2];						// м≥н€Їмо роки	
//					planDateCopy[i][2] = planDateCopy[j][2];
//					planDateCopy[j][2] = temp;
//					temp = planDateCopy[i][1];						//м≥с€ц≥
//					planDateCopy[i][1] = planDateCopy[j][1];
//					planDateCopy[j][1] = temp;
//					temp = planDateCopy[i][0];						//дн≥
//					planDateCopy[i][0] = planDateCopy[j][0];
//					planDateCopy[j][0] = temp;
//					tempstring = plannerCopy[i];					//назву
//					plannerCopy[i] = plannerCopy[j];
//					plannerCopy[j] = tempstring;
//					l = lenLow;
//				}
//			}
//
//		}
//	}
//	for (int i = 0; i < sizePlanner; i++)
//	{
//		if (planDateCopy[i][0] != 0) {
//			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
//			if (planPriorityCopy[i] == "c")
//				cout << " --  high priotity" << endl;
//			else if (planPriorityCopy[i] == "b")
//				cout << " --  medium priority" << endl;
//			else if (planPriorityCopy[i] == "a")
//				cout << " --  low priority" << endl;
//		}
//		isEmpty = false;
//	}
//	if (isEmpty == true) {
//		cout << "List is empty!" << endl;
//	}
//}
//
//void addtask(string nameOftask, int date, string priority) {
//	int day, month, year;
//	year = date % 10000;
//	day = date / 1000000;
//	month = (date / 10000) % 100;
//
//	if (currentIndex < sizePlanner) {			//	fulfilling two copies of array
//		planner[currentIndex] = nameOftask;
//		planDate[currentIndex][0] = day;
//		planDate[currentIndex][1] = month;
//		planDate[currentIndex][2] = year;
//		planPriority[currentIndex] = priority;
//		plannerCopy[currentIndex] = nameOftask;
//		planDateCopy[currentIndex][0] = day;
//		planDateCopy[currentIndex][1] = month;
//		planDateCopy[currentIndex][2] = year;
//		planPriorityCopy[currentIndex] = priority;
//		currentIndex++;
//	}
//	else {
//		cout << "planner is full" << endl;
//	}
//	cout << endl;
//}
//
//void removeTask(int indexOftask) {
//	planner[indexOftask] = "";
//	string tempArray[sizePlanner];
//	int tempIndex = 0;
//	for (string item : planner)
//	{
//		if (item != "") {
//			tempArray[tempIndex] = item;
//			tempIndex++;
//		}
//	}
//	for (int i = 0; i < sizePlanner; i++)
//	{
//		planner[i] = tempArray[i];
//	}
//	cout << endl;
//}
//
//void  managerTasks() {
//	int action = 0;
//
//	do
//	{
//		cout << "1.Show all tasks" << endl;
//		cout << "2.Remove task" << endl;
//		cout << "3.Add task" << endl;
//		cout << "4.Exit" << endl;
//		cout << endl;
//		cout << "Select action->_";
//		cin >> action;
//
//		switch (action)
//		{
//		case 1: {
//			action = 0;
//			system("cls");
//			cout << "What sorting would you prefer?" << endl;
//			cout << "1. By priority." << endl;
//			cout << "2. By date. " << endl;
//			cout << "3. Show as added. " << endl;
//			cout << "4. In alphabet order. " << endl;
//			cout << endl;
//			cout << "Select action->_";
//			cin >> action;
//			switch (action)
//			{
//			case 1: {
//				system("cls");
//				sortTasksbyPriority();
//			}break;
//
//			case 2: {
//				system("cls");
//				sortTasksbyDate();
//			}break;
//
//			case 3: {
//				system("cls");
//				showTasks();
//			}break;
//			case 4: {
//				system("cls");
//				sortTaskABC();
//			}break;
//			}
//
//		}break;
//
//		case 2: {
//			system("cls");
//			int tempNumber = 0;
//			cout << "Enter number task for delete: ";
//			cin >> tempNumber;
//			removeTask(tempNumber - 1);
//		}break;
//
//		case 3: {
//			system("cls");
//			string temp, temp3;
//			int temp2;
//			cout << "Enter event name: ";
//			cin.ignore();
//			getline(cin, temp);
//			cout << "Enter date in format (DDMMYYYY) :";
//			cin >> temp2;
//			cout << "Enter event priority: ";
//			cin >> temp3;
//			addtask(temp, temp2, temp3);
//		}break;
//
//		case 4: {
//			cout << "Goodbye" << endl;
//		}break;
//
//		}
//	} while (action != 4);
//}
//
//int main() {
//
//	managerTasks();
//
//	return 0;
//}
//
