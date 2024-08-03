#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

int main()
{
    int choice;
    const char *options = "\033[34m[1]- \033[36mTo open chrome browser \033[0m\n"
                          "\033[34m[2]- \033[36mTo open chrome browser and search for my todo app \033[0m\n"
                          "\033[34m[3]- \033[36mTo exit \033[0m\n\n";

    const char *program = "\033[1;41m                                                                 \033[0m\n"
                          "\033[1;41m       This is C++ program to perform following task             \033[0m\n"
                          "\033[1;41m                                                                 \033[0m\n\n";

    system("cls");
    cout << program;
    cout << options;
a:
    cout << "\033[1mEnter your choice {like 1 or 2} : \033[0m";
    if (cin >> choice)
    {
        if (choice == 1)
        {
            system("start chrome");
            goto a;
        }
        else if (choice == 2)
        {
            system("start chrome todo.devkantkumar.com");
            goto a;
        }
        else if (choice == 3)
        {
            cout << "\033[1mYou exited \033[0m\n";
        }
        else
        {
            cout << "\033[1;31mThis is invalid input! Please enter only 1 or 2 \033[0m\n";
            Beep(1000, 100);
            goto a;
        }
    }
    else
    {
        cout << "\033[31mInvalid input! Please enter numbers (1 or 2) only\033[0m\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Beep(1000, 100);
        goto a;
    }

    return 0;
}