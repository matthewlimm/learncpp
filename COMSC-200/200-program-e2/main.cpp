//*****************
//Program Name: Program Program E2: Grade Magic 8 Ball
//Author: Matthew Lim
//Program description: This program replicates the Magic 8 Ball toy with grades
//*****************

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_ARRAY{ 100 }, GRADE_TYPES{ 13 };

void predict();

/*---------------------------------
            Magic8Ball
---------------------------------
- m_type: string
- m_gradesShook: string array
- m_nrGradesShook: int
- m_gradeType: const string array
---------------------------------
+ Magic8Ball()
+ Magic8Ball(type: string)
+ getType(): const string
+ getNrGradesShook(): const int
+ setType(type: string): void
+ setGradesShook(grade: string): void
---------------------------------*/
class Magic8Ball
{
private:
    string m_type{};
    string m_gradesShook[MAX_ARRAY]{}; // For future potential use and
    // development
    int m_nrGradesShook{};
    const string m_gradeType[GRADE_TYPES] = {"A+", "A", "A-", "B+", "B", "B-",
                                            "C+", "C", "C-", "D+", "D", "D-",
                                            "F"};
public:
    // Constructors
    Magic8Ball() { m_type = "NaN"; m_nrGradesShook = 0; }
    Magic8Ball(string type) { m_type = type; m_nrGradesShook = 0; }

    // Accessors and Mutators
    string getType() const {return m_type; }
    int getNrGradesShook() const { return m_nrGradesShook; }
    void setType(string type) { m_type = type;
        setGradesShook(type); }
    void setGradesShook(string grade) { m_gradesShook[m_nrGradesShook++] =
    grade; }

    // Operator Overload Methods
    friend ostream &operator<<(ostream&, Magic8Ball&);
};

int main()
{
    freopen("error.txt", "w", stderr);
    srand(time(0));

    Magic8Ball class1;
    cout << class1;

    cout << "\nPredict a grade for another class? Y/N:";
    char c{};
    cin >> c;

    while((c != 'N' && c != 'n') || (c != 'Y' && c != 'y'))
    {
        if(c == 'Y' || c == 'y')
        {
            predict();
            cout << "\nPredict a grade for another class? Y/N:";
            cin >> c;
        }
        else if(c == 'N' || c == 'n')
        {
            return 0;
        }
        else
        {
            cout << "ERROR: Please enter a valid input.\n";
            cerr << "ERROR: Please enter a valid input.\n";
            cin >> c;
        }
    }

    return 0;
}

//*****************
// predict(): Creates a new Magic8Ball class and triggers the cout overloaded
// method
// Inputs: N/A
// Outputs: void
//*****************
void predict()
{
    Magic8Ball tempClass;
    cout << tempClass;
}

// Overloaded << operator with a Magic8Ball object as RHS
ostream &operator<<(ostream &stream, Magic8Ball &ball)
{
    int shake{rand() % 12};
    ball.setType(ball.m_gradeType[shake]);

    stream << "\nMagic8Ball predicts your grade will be: " << ball.getType() <<
           '\n';

    if (ball.getType() != "A+" && ball.getType() != "A" && ball.getType() !=
    "A-")
    {
        stream << ball.getType() << "? Unacceptable! I'm shaking the Magic8Ball"
                                    " until I get an A!\n\n";
        while (ball.getType() != "A+" || ball.getType() != "A" || ball.getType()
                                                                  != "A-")
        {
            shake = rand() % 12;
            ball.setType(ball.m_gradeType[shake]);
            stream << "Shake #" << ball.getNrGradesShook()
                   << ": Your grade "
                      "will be..." <<
                   ball.getType()
                   << '\n';
            if(ball.getType() == "A+" || ball.getType() == "A" || ball
            .getType() == "A-")
            {
                break;
            }
        }
    }
    stream << "\nHad to shake the Magic 8 Ball " << ball.getNrGradesShook() << " times for this A.\n";

    return stream;
}