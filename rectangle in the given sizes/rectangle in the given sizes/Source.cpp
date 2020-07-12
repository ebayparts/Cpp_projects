#include<iostream>
#include<conio.h>
using namespace std;
int F(int x, int y) {
    int i, j;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= y; j++)
        {
            if (j == 1 || j == y || i == 1 || i == x) {
                cout << "|  ";
            }
            else {
                cout << "_  ";
            }
        }
        cout << endl << endl;
    }return(x, y);
}
void main()
{
    int K, N;
    cout << "Enter width and height:" << endl;
    cin >> N >> K;
    F(K, N);
    _getch();
}