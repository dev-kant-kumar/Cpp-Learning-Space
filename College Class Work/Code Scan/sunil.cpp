// 10. Write a C++ program to format the output.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double pi = 3.14159965;

    // Fixed-point notation with 4 decimal places
    cout << fixed << setprecision(4);
    cout << "\n\nThe value of pi is : " << pi << endl;

    // Fixed-point notation with total width 8
    cout << "Value of pi with decimal 4 places of total width 8  : " << "/" << setw(8) << pi << "/" << endl;

    // Fixed-point notation with total width 10
    cout << "Value of pi with decimal 4 places of total width 10 : " << "/" << setw(10) << pi << "/" << endl;

    // Scientific notation
    cout << "\nScientific\n";
    cout << "The value of pi in scientific format is : " << scientific << pi << endl;

    // Reset to fixed notation
    cout << fixed;

    // Boolean values in number and alphabetic form
    bool done = false;
    cout << "\nValue of bool in following format \n";
    cout << "Status in number : " << done << endl;                // Outputs 0 or 1
    cout << "Status in alphabet : " << boolalpha << done << endl; // Outputs "false"
    cout << "Status in number : " << noboolalpha << done << endl; // Outputs 0 or 1
    cout << "\n\n\n";

    return 0;
}
