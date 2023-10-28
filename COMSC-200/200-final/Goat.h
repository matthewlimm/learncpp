#ifndef INC_200_FINAL_GOAT_H
#define INC_200_FINAL_GOAT_H

#include "Animal.h"
#include "Color.h"
#include "Date.h"
#include <string>

using namespace std;

/*********************************************
              Goat : Animal
----------------------------------------------
- age : int
- name : string
- color : Color
- bd : Date
----------------------------------------------
+ Goat() : Animal()
+ Goat(int, Color, Date, int, string) : Animal(int), color(), bd()
+ getAge() : int
+ getName() : string
+ getColor() : Color
+ setAge(int) : void
+ setName(string) : void
+ setColor(int, int, int, string) : void
+ getBD() : Date
+ setBD(int, int) : void
+ friend ostream &operator<< (ostream&, Goat&)
**********************************************/
class Goat : public Animal
{
private:
    int m_age{};
    string m_name{};
    Color color{};
    Date bd{};

public:
    // Constructors
    Goat() : Animal(), color(), bd()
    { m_age = -1; m_name = "NaN"; }
    Goat(int legs, Color cr, Date date, int age, string name) : Animal(legs), bd
            (date), color(cr)
    { m_age = age; m_name = name; }

    // Accessors & Mutators
    int getAge() const { return m_age; }
    string getName() const { return m_name; }
    void setAge(int age) { m_age = age;}
    void setName(string name) { m_name = name; }

    // "External" Accessors & Mutators
    Color getCR()
    {
        Color tmp{ color.getRed(), color.getGreen(), color.getBlue(), color
                .getName() };
        return tmp;
    }
    Date getBD()
    {
        Date tmp{ bd.getMonth(), bd.getDay() };
        return tmp;
    }
    void setCR(int red, int green, int blue, string name)
    {
        color.setRed(red);
        color.setGreen(green);
        color.setBlue(blue);
        color.setName(name);
    }
    void setBD(int month, int day)
    {
        bd.setMonth(month);
        bd.setDay(day);
    }

    // Misc.
    friend ostream &operator<< (ostream& stream, Goat& goat);
};

#endif //INC_200_FINAL_GOAT_H