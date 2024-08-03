// 1. write a cpp program to print the following pattern
// 1
// 1 0
// 1 0 1
// 1 0 1 0
// 1 0 1 0 1

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j % 2 != 0)
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
        cout << "\n";
    }
    return 0;
}