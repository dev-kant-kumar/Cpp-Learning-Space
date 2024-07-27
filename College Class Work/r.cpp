#include <iostream>
using namespace std;
int main()
{
    char str[] = "BCA";
    for (int i = 0; i < sizeof(str); i++)
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
        cout << endl;
    }
    return 0;
}