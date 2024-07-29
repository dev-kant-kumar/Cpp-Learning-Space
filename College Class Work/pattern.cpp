// Write a c++ program to print following pattern
// Pattern A -
// B
//  C
//   A

// Pattern B -
//   B
//  C
// A

#include <iostream>
#include <limits>
using namespace std;

void print_pattern(int choice);

int main()
{
    int choice;
    const char *patternA = "B   \n"
                           "  C \n"
                           "   A\n\n";

    const char *patternB = "   B\n"
                           "  C \n"
                           "A   \n";

    cout << "\033[1;41m This c++ program prints the following pattern \033[0m\n\n";
    cout << "\033[1;35mPattern A \033[0m\n";
    cout << patternA << endl;
    cout << "\033[1;35mPattern B \033[0m\n";
    cout << patternB << endl;
a:
    cout << "\033[1mEnter your choice {like 1 or 2 } : \033[0m";
    if (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            print_pattern(1);
            break;
        case 2:
            print_pattern(2);
            break;
        default:
            cout << choice << "\033[31m This is invalid choice enter only 1 or 2 \033[0m\n";
            goto a;
        }
    }
    else
    {
        cout << "\033[1;31mInvalid input! Please enter numbers 1 or 2 only \033[0m\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto a;
    }
}

void print_pattern(int choice)
{
    char str[] = "BCA";
    int count = 0;

    switch (choice)
    {
    case 1:
        // for printing pattern A
        // i - j
        // 0 - 0
        // 1 - 0 1
        // 2 - 0 1 2

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
                {
                    cout << str[i];
                }
                else
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        break;

    case 2:
        // for printing pattern B
        // i - j
        // 3 - 0 1 2
        // 2 - 0 1
        // 1 - 0

        for (int i = 3; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (j == i - 1)
                {
                    cout << str[count];
                    count++;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }

        break;
    }
}