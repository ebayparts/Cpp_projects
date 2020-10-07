#include <iostream>
#include <string>
using namespace std;
int stringLength(string str, int countSym) {
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		countSym++;
	}
	return countSym;
}

int main() {
	string str;
	cout << "Type your string:" << endl;
	getline(cin, str);
	int count=0;
	count = stringLength(str, count);
	cout << "Your string have " << count << " symbols" << endl;
	return 0;
}