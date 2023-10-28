#include "Car.h"

using namespace std;

Car::Car()
{
    this->make = "NaN";
    this->year = -1;
    this->speed = 0;
    this->nrEntries = 0;
}

Car::Car(string make, int year)
{
    this->make = make;
    this->year = year;
    this->speed = 0;
    this->nrEntries = 0;
}

Car::Car(const Car & c)
{
    this->make = c.make;
    this->year = c.year;
    this->speed = c.speed;
    this->nrEntries = c.nrEntries;
    for(int i = 0; i < nrEntries; i++)
    {
        maintLog[i] = c.maintLog[i];
    }
}

//enterMaint(): adds maintenance information to given car
//Inputs: int, string
//Returns: void
void Car::enterMaint(int mileage, string maintenance)
{
    if((nrEntries + 1) > MAX)
    {
        cout << "ERROR: maintenance log is full; log is not added.\n";
        return;
    }
    Log myLog = { mileage, maintenance };
    maintLog[nrEntries++] = myLog;
}

//printCollection(): prints the collection of cars
//Inputs: none
//Returns: void
void Car::printCollection()
{
    printAbbrInfo();
    cout << "\tMaintenance Log: ";
    for(int i = 0; i < getMaintCount(); i++) // -1 ?
    {
        cout << maintLog[i].mileage << ": " << maintLog[i].maintenance << ' ';
    }
    cout << '\n';
}

//printAbbrInfo(): prints cars in "abbreviated" form
//Inputs: none
//Returns: void
void Car::printAbbrInfo()
{
    cout << make << " | " << year << " | " << speed << " mph\n";
}