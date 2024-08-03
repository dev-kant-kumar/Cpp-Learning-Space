#include <iostream>
using namespace std;

int main()
{
    int num, reverse = 0, rem, original_num;

    cout << "Enter a four digit no : ";
    cin >> num;
    original_num = num;
    while (num > 0)
    {
        rem = num % 10;      // getting last digit of the number
        reverse*= 10 + rem; // forming reversed number
        num /= 10;
    }
    cout << "Reverse of " << original_num << " is : " << reverse << endl;
    return 0;
}