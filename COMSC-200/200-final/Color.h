#ifndef INC_200_FINAL_COLOR_H
#define INC_200_FINAL_COLOR_H

#include <string>

using namespace std;

/****************************
           Color
----------------------------
- red, green, blue: int
- name: string
----------------------------
+ Color()
+ Color(int, int, int, string)
+ getRed() : int
+ getGreen() : int
+ getBlue() : int
+ getName() : string
+ setRed(int) : void
+ setGreen(int) : void
+ setBlue(int) : void
+ setName(string) : void
***************************/
class Color
{
private:
    int m_red{};
    int m_green{};
    int m_blue{};
    string m_name{};

public:
    // Constructors
    Color()
    { m_red = -1; m_green = -1; m_blue = -1; m_name = "NaN"; }
    Color(int red, int green, int blue, string name)
    { m_red = red; m_green = green; m_blue = blue; m_name = name; }

    // Accessors & Mutators
    int getRed() const { return m_red; }
    int getGreen() const { return m_green; }
    int getBlue() const { return m_blue; }
    string getName() const { return m_name; }
    void setRed(int red) { m_red = red; }
    void setGreen(int green) { m_green = green; }
    void setBlue(int blue) { m_blue = blue; }
    void setName(string name) { m_name = name; }
};

#endif //INC_200_FINAL_COLOR_H