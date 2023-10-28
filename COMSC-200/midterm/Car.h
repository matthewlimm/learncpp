// Car.h

#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;

const int MAX = 100;

/*----------------------------
         Struct: Log
------------------------------
+ mileage: int
+ maintenance: string
------------------------------
------------------------------
          Class: Car
------------------------------
- make: string
- year: int
- speed: int
- maintLog[]: Log
- nrMaintLogEntries: int
------------------------------
+ Car()
+ Car(string, int)
+ Car(Car&)
+ getMake() : string
+ getYear() : int
+ getSpeed() : int
+ getMaintCount() : int
+ setMake(string) : void
+ setYear(int) : void
+ setSpeed(int) : void
+ enterMaint(int, string) : void
+ accelerate() : void
+ brake() : void
+ printCollection() : void
+ printAbbrInfo() : void
-----------------------------*/
class Car
{
    struct Log
    {
        int mileage;
        string maintenance;
    };

private:
    string make;
    int year;
    int speed;
    Log maintLog[MAX];
    int nrEntries;  // holds number of entries in maintenance log

public:
    // constructors
    Car();
    Car(string, int);
    Car(const Car &);

    // setters and getters
    string getMake()        { return make; }
    int getYear()           { return year; }
    int getSpeed()          { return speed; }
    int getMaintCount()     { return nrEntries; }
    void setMake (string m) { make = m; }
    void setYear (int y)    { year = y; }
    void setSpeed(int s)    { speed = s; }
    void enterMaint(int, string);

    //other methods
    void accelerate()       { speed += 5; }
    void brake()            { speed -= 5; }
    void printCollection(); // outputs all object info
    void printAbbrInfo();   // outputs make/year only
};
#endif