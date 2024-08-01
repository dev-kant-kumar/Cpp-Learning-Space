// Remove zeros from the number 430705 to form 4375

#include <iostream>
using namespace std;

int main()
{
    int number[6] = {4, 3, 0, 7, 0, 5}, new_num[4], count = 0;

    for (int i = 0; i < 6; i++)
    {
        if (number[i] != 0)
        {
            new_num[count] = number[i];
            count++;
        }
    }

    cout << "After removing zero new number is : ";
    for (int i = 0; i < 4; i++)
    {
        cout << new_num[i];
    }

    return 0;
}