#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (i == 1)
            {
                cout << "B";
            }
            if ((j == 1) and (i == 2))
            {
                cout << "C";
            }
            if ((j == 1) and (i == 3))
            {
                cout << "A";
            }

            cout << " ";

        }
            cout << "\n";
    }
    for (int i = 3; i >=1; i--)
    {
        for (int j = i; j >=1; j--)
        {
            if ((i == 3) and (j==1))
            {
                cout << "B";
            }
            if ((i == 2) and (j == 1))
            {
                cout << "C";
            }
            if ((i == 1) and (j == 1))
            {
                cout << "A";
            }

            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
