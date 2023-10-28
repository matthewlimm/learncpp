#ifndef INC_200_FINAL_ANIMAL_H
#define INC_200_FINAL_ANIMAL_H

/***************************
           Animal
----------------------------
- legs: int
----------------------------
+ Animal()
+ Animal(int)
+ getLegs() : int
+ setLegs(int) : void
***************************/
class Animal
{
private:
    int m_legs{};
public:
    // Constructors
    Animal()
    { m_legs = -1; }
    Animal(int legs)
    { m_legs = legs; }

    // Accessors & Mutators
    int getLegs() const { return m_legs; }
    void setLegs(int legs) { m_legs = legs; }
};

#endif //INC_200_FINAL_ANIMAL_H