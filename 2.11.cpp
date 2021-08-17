// you can avoid duplicated definitions within header files with header guards (aka include guard)
// header guards are conditional compilation directives that take the following form:

#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

// your declarations (and certain types of definitions) here

#endif

// this basically has the preprocessor check whether this identifier has been previously defined through the conditional compilation directives learned a few lessons back
// however... header guards do not prevent a given header file from being included (once) into separate code files
// two separate header files may end up having the same filename; many developers recommend using a naming convention of 
// <PROJECT>_<PATH>_<FILE>_H , <FILE>_<LARGE RANDOM NUMBER>_H, or <FILE>_<CREATION DATE>_H

/*
#ifndef SQUARE_H // square.h included from main.cpp,
#define SQUARE_H // SQUARE_H gets defined here

// and all this content gets included
int getSquareSides()
{
    return 4;
}

#endif // SQUARE_H

#ifndef GEOMETRY_H // geometry.h included from main.cpp
#define GEOMETRY_H
#ifndef SQUARE_H // square.h included from geometry.h, SQUARE_H is already defined from above
#define SQUARE_H // so none of this content gets included

int getSquareSides()
{
    return 4;
}

#endif // SQUARE_H
#endif // GEOMETRY_H

int main()
{
    return 0;
}
*/

#pragma once is a less error-prone and shorter versions of header guards; however, it is not an official part of the C++ language, and not all compilers support it