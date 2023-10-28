//*****************
//Program Name: 2022SU Midterm Exam
//Author: Matthew Lim
//Program description: (due Tue 7/5 9:15pm) [100 pts]
//*****************

#include "Car.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

const int NUM_CARS{ 4 };

void printCollectionCar(vector<Car> &cars);
void addCar(vector<Car> &cars);
void removeCar(vector<Car> &cars);
void accelerateCar(vector<Car> &cars);
void brakeCar(vector<Car> &cars);
void copyCar(vector<Car> &cars);
void addMaintRecord(vector<Car> &cars);
void displayMenu();
void displaySubmenu(vector<Car> &cars);

int main()
{
    vector<Car> cars;

    freopen("error.txt", "w", stderr);
    ifstream fin("C:/Dev/comsc-200/midterm/cars.txt");
    if (fin.fail())
    {
        cout << "ERROR: could not open file!\n";
        cerr << "ERROR: could not open file!\n";
        return 0;
    }
    string carMake{};
    string year{};
    for(int i = 0; i < NUM_CARS; i++)
    {
        getline(fin, carMake);
        getline(fin, year);
        int carYear = stoi(year);
        Car tempCar(carMake, carYear);
        cars.push_back(tempCar);
    }
    fin.close();

    displayMenu();

    int choice{};
    cin >> choice;
    while(choice != 8)
    {
        while(choice < 1 || choice > 8)
        {
            cout << "ERROR: Please input a valid menu selection.\n";
            cerr << "ERROR: Please input a valid menu selection.\n";
            cin >> choice;
        }
        if(cars.size() == 0 && (choice == 1 || choice == 3 || choice == 4 ||
        choice == 5 || choice == 6 || choice == 7))
        {
            cout << "<car collection is empty>\n";
            cerr << "<car collection is empty>\n";
        }
        else
        {
            switch(choice)
            {
                case 1:
                    printCollectionCar(cars);
                    break;
                case 2:
                    addCar(cars);
                    break;
                case 3:
                    removeCar(cars);
                    break;
                case 4:
                    accelerateCar(cars);
                    break;
                case 5:
                    brakeCar(cars);
                    break;
                case 6:
                    copyCar(cars);
                    break;
                case 7:
                    addMaintRecord(cars);
                    break;
                case 8:
                    cout << "Thank you! Have a nice day.\n";
                    return 0;
            }
        }
        displayMenu();
        cin >> choice;
    }

    return 0;
}

//*****************
//printCollectionCar(): prints the car collection
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void printCollectionCar(vector<Car> &cars)
{
    cout << "Car Collection:\n\n";
    for(int i = 0; i < cars.size(); i++)
    {
        cout << "\t[" << (i + 1) << "] ";
        cars.at(i).printCollection();
    }
}

//*****************
//printCollectionCar(): adds a given car from the 'cars' vector
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void addCar(vector<Car> &cars)
{
    string carMake{};
    string year{};
    cout << "Adding a car to the collection...\n";
    cout << "    Enter make:";
    getline(cin >> ws, carMake); // 'ws' learned from learncpp.com
    cout << "    Enter year:";
    getline(cin >> ws, year);
    int carYear = stoi(year);
    Car tempCar(carMake, carYear);
    cars.push_back(tempCar);
    cout << "Done. Car added.\n";
}

//*****************
//removeCar(): removes a given car from the 'cars' vector
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void removeCar(vector<Car> &cars)
{
    cout << "Removing a car from the collection...\n\n";
    cout << "\tEnter the number of the car to remove:\n";
    displaySubmenu(cars);
    int choice{};
    cout << "Choice:";
    cin >> choice;
    while(choice < 1 || choice > cars.size())
    {
        cout << "ERROR: Please input a valid menu selection.\n";
        cerr << "ERROR: Please input a valid menu selection.\n";
        cin >> choice;
    }
    cars.erase(cars.begin() + (choice - 1));
    cout << "Done. Car removed.\n";
}

//*****************
//accelerateCar(): increases a given car's speed by +5
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void accelerateCar(vector<Car> &cars)
{
    cout << "Accelerating a car...\n\n";
    cout << "\tEnter the number of the car to accelerate:\n";
    displaySubmenu(cars);
    int choice{};
    cout << "Choice:";
    cin >> choice;
    while(choice < 1 || choice > cars.size())
    {
        cout << "ERROR: Please input a valid menu selection.\n";
        cerr << "ERROR: Please input a valid menu selection.\n";
        cin >> choice;
    }
    cars.at(choice - 1).accelerate();
    cout << "Done. Car accelerated. New speed " << cars.at(choice - 1)
    .getSpeed() << " mph.\n";
}

//*****************
//printCollectionCar(): decreases a given car's speed by -5
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void brakeCar(vector<Car> &cars)
{
    cout << "Braking a car...\n\n";
    cout << "\tEnter the number of the car to brake:\n";
    displaySubmenu(cars);
    int choice{};
    cout << "Choice:";
    cin >> choice;
    while(choice < 1 || choice > cars.size())
    {
        cout << "ERROR: Please input a valid menu selection.\n";
        cerr << "ERROR: Please input a valid menu selection.\n";
        cin >> choice;
    }
    if(cars.at(choice - 1).getSpeed() == 0)
    {
        cout << "Error: can't brake a car that's standing still.\n";
        cerr << "Error: can't brake a car that's standing still.\n";
    }
    else
    {
        cars.at(choice - 1).brake();
        cout << "Done. Car braked. New speed " << cars.at(choice - 1)
                .getSpeed() << " mph.\n";
    }
}

//*****************
//copyCar(): copys a given car via copy constructor
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void copyCar(vector<Car> &cars)
{
    cout << "Copying a car...\n\n";
    cout << "\tEnter the number of the car to copy:\n";
    displaySubmenu(cars);
    int choice{};
    cout << "Choice:";
    cin >> choice;
    while(choice < 1 || choice > cars.size())
    {
        cout << "ERROR: Please input a valid menu selection.\n";
        cerr << "ERROR: Please input a valid menu selection.\n";
        cin >> choice;
    }
    Car tempCar(cars.at(choice - 1));
    cars.push_back(tempCar);
    cout << "Done. Car copied.\n";
}

//*****************
//addMaintRecord(): adds maintenance information to given car
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void addMaintRecord(vector<Car> &cars)
{
    cout << "Adding a maintenance record...\n\n";
    cout << "\tEnter the number of the car to add a record to:\n";
    displaySubmenu(cars);
    int choice{};
    cout << "Choice:";
    cin >> choice;
    while(choice < 1 || choice > cars.size())
    {
        cout << "ERROR: Please input a valid menu selection.\n";
        cerr << "ERROR: Please input a valid menu selection.\n";
        cin >> choice;
    }
    int mileage{};
    cout << "Enter the mileage:";
    cin >> mileage;
    string maintenance{};
    cout << "Enter the maintenence completed:";
    getline(cin >> ws, maintenance);
    cars.at(choice - 1).enterMaint(mileage, maintenance);
}

//*****************
//displayMenu(): displays the main menu
//Inputs: none
//Outputs: void
//*****************
void displayMenu()
{
    cout << "\n*** MAIN MENU ***\n";
    cout << "\tEnter:\n";
    cout << "\t1 | Print complete car collection\n";
    cout << "\t2 | Add a car to the collection\n";
    cout << "\t3 | Remove a car from the collection\n";
    cout << "\t4 | Accelerate a car\n";
    cout << "\t5 | Brake a car\n";
    cout << "\t6 | Copy a car\n";
    cout << "\t7 | Add a maintenance record\n";
    cout << "\t8 | Quit\n";
}

//*****************
//displaySubmenu(): prints the car submenu
//Inputs: cars vector (pass by reference)
//Outputs: void
//*****************
void displaySubmenu(vector<Car> &cars)
{
    for(int i = 0; i < cars.size(); i++)
    {
        cout << "\t[" << (i + 1) << "] ";
        cars.at(i).printAbbrInfo();
    }
}