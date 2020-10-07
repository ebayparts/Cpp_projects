#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cout << "Type your string:" << endl;
	getline(cin, str);
	string deleting;
	cout << "which symbol to delete ?" << endl;
	cin >> deleting;
	int index = str.find(deleting);
	if (index < 0) {
		cout << "symbol not found" << endl;
	}
	else {
		str.erase(index, 1);
	}
	cout << "Your new string:" << endl << str << endl;
	return 0;
}