#ifndef INC_200_FINAL_DATE_H
#define INC_200_FINAL_DATE_H

/***************************
            Date
----------------------------
- month, day: int
----------------------------
+ Date()
+ Date(int, int)
+ getMonth() : int
+ getDate() : int
+ setMonth(int) : void
+ setDay(int) : void
***************************/
class Date
{
private:
    int m_month{};
    int m_day{};
public:
    // Constructors
    Date()
    { m_month = -1; m_day = -1; }
    Date(int month, int day)
    { m_month = month; m_day = day; }

    // Accessors & Mutators
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
    void setMonth(int month) { m_month = month; }
    void setDay(int day) { m_day = day; }
};

#endif //INC_200_FINAL_DATE_H