#ifndef INC_200_LAB_11_COLLECTION_H
#define INC_200_LAB_11_COLLECTION_H

#include <vector>
#include <iostream>

using namespace std;

/*---------------------------------
            Collection
---------------------------------
- m_container: vector<Type>
---------------------------------
+ Collection(size: int, init: Type)
+ push(val: Type): void
+ print(): void
+ setValue(val: Type, i: int): void
---------------------------------*/
template <class Type>
class Collection
{
private:
    vector<Type> m_container{};

public:
    //Constructor
    Collection(int size, Type init);

    // Mutators
    void push(Type val);
    void setValue(Type val, int i)
    { m_container.at(i) = val; };

    // Misc.
    void print();
};

// Constructor implementation
template <class Type>
Collection<Type>::Collection(int size, Type init)
{
    for(int i = 0; i < size; i++)
    {
        push(init);
    }
}

// push(Type val): this receives a value of type <Type> and pushes it into
// the  vector using 'emplace_back' rather than 'push_back' (emplace_back
// works  better placing objects into containers).
// Inputs: Type val
// Returns: void
template <class Type>
void Collection<Type>::push(Type val)
{
    m_container.template emplace_back(val);
}

// print(): outputs the vector data
// Inputs: N/A
// Returns: void
template <class Type>
void Collection<Type>::print()
{
    cout << '\t';
    for(int i = 0; i < m_container.size(); i++)
    {
        cout << m_container.at(i) << ' ';
    }
    cout << '\n';
}

#endif //INC_200_LAB_11_COLLECTION_H