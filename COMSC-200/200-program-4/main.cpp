//*****************
// Program 4: Color Class
// Author: Matthew Lim
// Program description: a vector of Color objects (our palette) with class
// methods of tint() and rotate() to utilize the entire palette of colors
//*****************

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*-------------------------------
               Color
---------------------------------
- red: int
- green: int
- blue: int
- valid: bool
---------------------------------
- checkValue(int) : bool
- genColor() : int
+ Color()
+ Color(int, int, int)
+ setRed(int) : void
+ setGreen(int) : void
+ setBlue(int) : void
+ getRed() : int
+ getGreen() : int
+ getBlue() : int
+ getValid(): bool
+ tint() : void
+ outputColor() : void
+ repair() : void
+ rotate() : void
-------------------------------*/
class Color
{
private:
    int m_red{};
    int m_green{};
    int m_blue{};
    bool m_valid{};

    bool checkValue(int val); // must be called internally — not in main()
    int genColor();
public:
    // Constructors
    Color();
    Color(int red, int green, int blue);

    // Mutators — what's the line limit convention for inline functions?
    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);

    // Accessors
    int getRed() const { return m_red; }
    int getGreen() const { return m_green; }
    int getBlue() const { return m_blue; }
    bool getValid() const { return m_valid; } // hope this is OK

    // Misc.
    void tint();
    void outputColor();
    void repair();
    void rotate();
    
};

Color::Color()
{
    m_red = -1;
    m_green = -1;
    m_blue = -1;
    m_valid = false;
}

Color::Color(int red, int green, int blue)
{
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

// setRed(int red): sets the red color and calls checkValue(bool) to
// determine its validity
// Inputs: int
// Returns: void
void Color::setRed(int red)
{
    if(!checkValue(red))
    {
        cout << "Red value error (" << red << "). Initializing to -1 "
                                              "with invalid state.\n";
        m_red = -1;
        m_valid = false;
    }
    else
    {
        m_red = red;
        m_valid = true;
    }
}

// setGreen(int green): sets the green color and calls checkValue(bool) to
// determine its validity
// Inputs: int
// Returns: void
void Color::setGreen(int green)
{
    if(!checkValue(green))
    {
        cout << "Green value error (" << green << "). Initializing to -1 "
                                                  "with "
                                                  "invalid state.\n";
        m_green = -1;
        m_valid = false;
    }
    else
    {
        m_green = green;
        m_valid = true;
    }
}

// setBlue(int blue): sets the blue color and calls checkValue(bool) to
// determine its validity
// Inputs: int
// Returns: void
void Color::setBlue(int blue)
{
    if(!checkValue(blue))
    {
        cout << "Blue value error (" << blue << "). Initializing to -1 "
                                                "with "
                                                "invalid state.\n";
        m_blue = -1;
        m_valid = false;
    }
    else
    {
        m_blue = blue;
        m_valid = true;
    }
}

// checkValue(int val): returns the boolean 'true' if the color is in the
// range 0-255, 'false' if not
// Inputs: int
// Returns: bool
bool Color::checkValue(int val)
{
    if(val < 0 || val > 255)
    {
        return false;
    }
    return true;
}

// genColor(): will return a random integer in the range 0-255 inclusive
// Inputs: N/A
// Returns: int
int Color::genColor()
{
    return rand() % 255;
}

// tint(): will tint a color by adding 10 to all of its values. If any value
// then goes over 255, it rolls over to the beginning
// Inputs: N/A
// Returns: void
void Color::tint()
{
    if(m_red >= 246)
    {
        m_red = (10 + m_red) % 256;
    }
    else
    {
        m_red += 10;
    }
    if(m_green >= 246)
    {
        m_green = (10 + m_green) % 256;
    }
    else
    {
        m_green += 10;
    }
    if(m_blue >= 246)
    {
        m_blue = (10 + m_blue) % 256;
    }
    else
    {
        m_blue += 10;
    }
}

// outputColor(): will output all three colors in this format if the color is
// valid: R: 10 | G: 50 | B: 150 or this format if the color is invalid: R:
// 10 | G: 50 | B: 150 | invalid
// Inputs: N/A
// Returns: void
void Color::outputColor()
{
    cout << "R: " << getRed() << " | G: " << getGreen() << " | B: " <<
    getBlue();
    if(!getValid())
    {
        cout << setw(11) << " | invalid\n";
    }
    else
    {
        cout << '\n';
    }
}

// repair(): will repair any color that is a -1 to a new valid random value
// and restore the object's state to valid
// Inputs: N/A
// Returns: void
void Color::repair()
{
    if(m_red == -1)
    {
        m_red = genColor();
        m_valid = true;
    }
    if(m_green == -1)
    {
        m_green = genColor();
        m_valid = true;
    }
    if(m_blue == -1)
    {
        m_blue = genColor();
        m_valid = true;
    }
}

// rotate(): will rotate the colors: green becomes red; red becomes blue;
// blue becomes green
// Inputs: N/A
// Returns: void
void Color::rotate()
{
    int tempGreen{ m_green };
    m_green = m_red;
    m_red = m_blue;
    m_blue = tempGreen;
}

int main()
{
    // PART ONE: INITIALIZATION
    srand(time(0));
    const int NUM_COLORS{ 6 };
    vector<Color> colors;
    for(int i = 0; i < NUM_COLORS; i++)
    {
        Color tempColor;
        tempColor.setRed(rand() % 255);
        tempColor.setGreen(rand() % 255);
        tempColor.setBlue(rand() % 255);
        colors.push_back(tempColor);
    }

    cout << "STATE OF THE VECTOR\n";
    cout << setw(11) << "Color#"
    << setw(10) << "R value"
    << setw(10) << "G value"
    << setw(10) << "B value"
    << setw(12) << "Invalid?\n";
    cout << setw(11) << "------"
    << setw(10) << "-------"
    << setw(10) << "-------"
    << setw(10) << "-------"
    << setw(12) << "--------\n";

    for(int i = 0; i < NUM_COLORS; i++)
    {
        cout << setw(11) << (i + 1)
             << setw(10) << colors.at(i).getRed()
             << setw(10) << colors.at(i).getGreen()
             << setw(10) << colors.at(i).getBlue();
        if(!colors.at(i).getValid())
        {
            cout << setw(11) << "invalid\n";
        }
        else
        {
            cout << '\n';
        }
    }

    // PART TWO: TINTING
    cout << '\n';
    cout << "Tinting the palette by 10 values...\n";
    for(int i = 0; i < NUM_COLORS; i++)
    {
        colors.at(i).tint();
    }

    cout << "STATE OF THE VECTOR\n";
    cout << setw(11) << "Color#"
         << setw(10) << "R value"
         << setw(10) << "G value"
         << setw(10) << "B value"
         << setw(12) << "Invalid?\n";
    cout << setw(11) << "------"
         << setw(10) << "-------"
         << setw(10) << "-------"
         << setw(10) << "-------"
         << setw(12) << "--------\n";

    for(int i = 0; i < NUM_COLORS; i++)
    {
        cout << setw(11) << (i + 1)
             << setw(10) << colors.at(i).getRed()
             << setw(10) << colors.at(i).getGreen()
             << setw(10) << colors.at(i).getBlue();
        if(!colors.at(i).getValid())
        {
            cout << setw(11) << "invalid\n";
        }
        else
        {
            cout << '\n';
        }
    }

    // PART THREE: ROTATING
    cout << '\n';
    cout << "Rotating palette colors...\n";
    for(int i = 0; i < NUM_COLORS; i++)
    {
        colors.at(i).rotate();
    }

    cout << "STATE OF THE VECTOR\n";
    cout << setw(11) << "Color#"
         << setw(10) << "R value"
         << setw(10) << "G value"
         << setw(10) << "B value"
         << setw(12) << "Invalid?\n";
    cout << setw(11) << "------"
         << setw(10) << "-------"
         << setw(10) << "-------"
         << setw(10) << "-------"
         << setw(12) << "--------\n";

    for(int i = 0; i < NUM_COLORS; i++)
    {
        cout << setw(11) << (i + 1)
             << setw(10) << colors.at(i).getRed()
             << setw(10) << colors.at(i).getGreen()
             << setw(10) << colors.at(i).getBlue();
        if(!colors.at(i).getValid())
        {
            cout << setw(11) << "invalid\n";
        }
        else
        {
            cout << '\n';
        }
    }

    // PART FOUR: CORRUPTING
    cout << '\n';
    cout << "Corrupting one palette color...\n";
    int randColor{ rand() % NUM_COLORS };
    colors.at(randColor).setRed(350);

    cout << "STATE OF THE VECTOR\n";
    cout << setw(11) << "Color#"
         << setw(10) << "R value"
         << setw(10) << "G value"
         << setw(10) << "B value"
         << setw(12) << "Invalid?\n";
    cout << setw(11) << "------"
         << setw(10) << "-------"
         << setw(10) << "-------"
         << setw(10) << "-------"
         << setw(12) << "--------\n";

    for(int i = 0; i < NUM_COLORS; i++)
    {
        cout << setw(11) << (i + 1)
             << setw(10) << colors.at(i).getRed()
             << setw(10) << colors.at(i).getGreen()
             << setw(10) << colors.at(i).getBlue();
        if(!colors.at(i).getValid())
        {
            cout << setw(11) << "invalid\n";
        }
        else
        {
            cout << '\n';
        }
    }

    // PART FIVE: REPAIR
    cout << '\n';
    cout << "Creating a bad color1 using the parameter constructor "
            "(15/225/300) ...\n";
    Color color1 { 15, 255, 300 };
    color1.outputColor();
    cout << "Repairing color1...\n";
    color1.repair();
    color1.outputColor();

    // PART SIX: COLOR CREATION VIA CONSTRUCTOR
    cout << '\n';
    cout << "Creating a bad color2 using the default constructor...\n";
    Color color2;
    color2.outputColor();
    cout << "Repairing color2...\n";
    color2.repair();
    color2.outputColor();

    return 0;
}