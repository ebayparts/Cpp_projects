#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
int arr[20];
float change() {
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
        cout << " " << arr[i];
    }
    int place;
    int number;
    do {
        cout << endl << "Chose which element to change";
        cin >> place;
        cout << "Enter number to put on " << place << " place:";
        cin >> number;
        arr[place - 1] = number;
        for (int i = 0; i < 20; i++) {
            cout << " " << arr[i];
        }
    } while (true);
    return 0;
}
int main() {
    change();
}