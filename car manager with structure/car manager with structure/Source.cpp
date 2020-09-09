#include <iostream>
#include <string>
using namespace std;

struct Vehicle {
    string name;
    int length;
    int clearence;
    float engineCapacity;
    int enginePower;
    int rimDiameter;
    string bodyColor;
    string transmissionType;
};

int countVehicles = 0;
Vehicle* ListVehicles = new Vehicle[countVehicles];

void addCarToSystem(Vehicle newVehicle) {

    Vehicle* temp = new Vehicle[countVehicles + 1];
    for (int i = 0; i < countVehicles; i++)
    {
        temp[i] = ListVehicles[i];
    }

    temp[countVehicles] = newVehicle;
    countVehicles++;

    ListVehicles = new Vehicle[countVehicles];


    for (int i = 0; i < countVehicles; i++)
    {
        ListVehicles[i] = temp[i];
    }
    delete[]temp;
}

void showAllCars() {


    for (int i = 0; i < countVehicles; i++)
    {
        cout << endl;
        cout << "Car: " <<ListVehicles[i].name<< endl;
        cout << "Car length: " <<ListVehicles[i].length<< endl;
        cout << "Car clearence: " <<ListVehicles[i].clearence << endl;
        cout << "Car engine capacity: " <<ListVehicles[i].engineCapacity<< endl;
        cout << "Car engine power: " <<ListVehicles[i].enginePower<< endl;
        cout << "Car rim diameter: " <<ListVehicles[i].rimDiameter<< endl;
        cout << "Car body color: " <<ListVehicles[i].bodyColor<< endl;
        cout << "Car transmission type: " <<ListVehicles[i].transmissionType<< endl;

    }
}


void searchCar(string dataSearch) {
    for (int i = 0; i < countVehicles; i++)
    {
        if (ListVehicles[i].name.find(dataSearch) != string::npos || //npos - nothing found
            to_string(ListVehicles[i].length).find(dataSearch) != string::npos ||
            to_string(ListVehicles[i].clearence).find(dataSearch) != string::npos ||
            to_string(ListVehicles[i].engineCapacity).find(dataSearch) != string::npos ||
            to_string(ListVehicles[i].enginePower).find(dataSearch) != string::npos ||
            to_string(ListVehicles[i].rimDiameter).find(dataSearch) != string::npos ||
            ListVehicles[i].bodyColor.find(dataSearch) != string::npos ||
            ListVehicles[i].transmissionType.find(dataSearch) != string::npos)
        {
            cout << endl;
            cout << "Car: " << ListVehicles[i].name << endl;
            cout << "Car length: " << ListVehicles[i].length << endl;
            cout << "Car clearence: " << ListVehicles[i].clearence << endl;
            cout << "Car engine capacity: " << ListVehicles[i].engineCapacity << endl;
            cout << "Car engine power: " << ListVehicles[i].enginePower << endl;
            cout << "Car rim diameter: " << ListVehicles[i].rimDiameter << endl;
            cout << "Car body color: " << ListVehicles[i].bodyColor << endl;
            cout << "Car transmission type: " << ListVehicles[i].transmissionType << endl;
            }
    }

}


int main() {

    int action = 0;
    do
    {


        cout << "1. Show all cars" << endl;
        cout << "2. Add new car" << endl;
        cout << "3. Search cars" << endl;
        cout << "4. Exit" << endl;
        cout << endl;
        cout << "Select action from menu - >> _" << endl;
        cin >> action;


        switch (action)
        {
        case 1: {
            showAllCars();
        }break;

        case 2: {
            Vehicle newCar;
            cout << "Enter name for car: ";
            cin >> newCar.name;

            cout << "Enter length of the car: ";
            cin >> newCar.length;

            cout << "Enter clearence of the car: ";
            cin >> newCar.clearence;

            cout << "Enter engine capacity of the car: ";
            cin >> newCar.engineCapacity;

            cout << "Enter engine power of the car: ";
            cin >> newCar.enginePower;

            cout << "Enter rim diameter of the car: ";
            cin >> newCar.rimDiameter;

            cout << "Enter body color of the car: ";
            cin >> newCar.bodyColor;

            cout << "Enter transmission type for car: ";
            cin >> newCar.transmissionType;

            addCarToSystem(newCar);

        }break;


        case 3: {
            string dataSearch = "";
            cout << "Search: ";
            cin >> dataSearch;
            searchCar(dataSearch);
        }break;

        case 4: {
            cout << "Good bye!" << endl;
        }break;

        default: {
            cout << "Error: Please, select action from menu!" << endl;
        }break;

        }

    } while (action != 4);

    return 0;
}




























