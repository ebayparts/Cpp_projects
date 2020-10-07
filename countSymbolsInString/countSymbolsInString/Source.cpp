#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cout << "Type your string:" << endl;
	getline(cin, str);
	int count = 0;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	cout << "Your string have " << count << " symbols" << endl;
	return 0;
}