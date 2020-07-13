#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
int arr[4];
int attempt = 0;
int arr1[4];
int bulls = 0;
int cows = 0;
float game() {
    srand(time(NULL));
    cout << "Lets play in BULLS AND COWS GAME!!" << endl;
    for (int i = 0; i < 4; i++) {
        arr[i] = rand() % 4;
        //cout << " " << arr[i]; // for checking - uncomment this row;
    }
    do {
        cows = 0;
        bulls = 0;
        cout << endl << "Make a try to guess (4 numbers) up to 10 each:" << endl;
        cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3];
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == arr1[i]) {
                cows++;
            }
            else if (arr[i] == arr1[0] || arr[i] == arr1[1] || arr[i] == arr1[2] || arr[i] == arr1[3]) {
                bulls++;
            }
        }
        cout << "You've got : " << cows << " cows - correct placed numbers, and" << endl << bulls << " bulls - incorrect placed numbers" << endl;
        attempt++;
    } while (cows != 4);
        cout << "you win !" << endl << "as result you need only " << attempt << " attempts to chose correct number" << endl;
        cout << "here you got applause and firework!" << endl;
    return 0;
}
int main() {
    game();
}