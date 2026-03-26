/*
    Notes - Class 16 - Mar 04, 2026
    Week 8_Strings and Intro to C++.pptx

    - What is C++?
        C, C++, Java, and C# are related
        C++ evolved from C
        C++ is a superset of C: added classes and OOP
        Java was modeled after C++

    - <iostream? provides def for I/O functions
    - cout
        object that writes to the stdout devide
        std::cout
        << is the C++ insertion operator
        endl is the C++ newline character

    - Scope resolution operator ::
        used to identify and disambiguate identifier used
        in different scopes

    - g++ is the compiler for C++ programs

    - cin
        predefinced variable that reads data from keyboard
        >> extraction operator

    - string
        not a basic type, it is a class
*/

#include <iostream> // loads a header file containing function and class definitions
// C++ headers are not referred to with the .h suffix

using namespace std; // loads a namespace called std
// namespaces are used to save typing of code for convenience

int main() {
    cout << "Hello World!" << endl;
    return 0;
}