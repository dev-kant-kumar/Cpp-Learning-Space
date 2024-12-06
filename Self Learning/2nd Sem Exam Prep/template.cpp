#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{

    int marks[4] = {99, 98, 97, 96};
    float price[4] = {70.55, 55.67, 88.9, 55.3};

    int counter = 0, counterForMarks = 0, counterForPrice = 0, totalMarks = 0;
    float totalPrice = 0;

    for (int i = 0; i < 4; i++)
    {
        if (counter % 2 == 0)
        {
            totalMarks += add(marks[counterForMarks], marks[counterForMarks + 1]);
            counterForMarks += 2;
            counter++;
        }
        else
        {

            totalPrice += add(price[counterForPrice], price[counterForPrice + 1]);
            counterForPrice += 2;
            counter++;
        }
    }
    system("cls");
    cout << "We got following \n\n";
    cout << "\033[1;33mTotal Marks : \033[0m" << totalMarks << "\n";
    cout << "\033[1;33mTotal Price : \033[0m" << totalPrice << "\n";
    cout << "\n\n\n\n";

    return 0;
}
