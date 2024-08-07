// 1. Declare a function to input a string and check the entered string is palindrome or not.

#include <iostream>
using namespace std;
int findLength(char str[]);
bool isPalindrome(char str[]);
char *reverseStr(char str[], int length);

int main()
{
    char str[100];

    cout << "This c++ program check the entered string is palindrome or not \n\n";
    cout << "Enter any string : ";
    cin >> str;

    int status = isPalindrome(str);
    if (status)
    {
        cout << "Entered string : " << str << " is palindrome string. \n";
    }
    else
    {
        cout << "Entered string : " << str << " is not a palindrome string \n";
    }
    return 0;
}
int findLength(char str[])
{
    int i = 0, length = 0;
    while (str[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

char *reverseStr(char str[], int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        char lastChar = str[length - i - 1];
        str[length - i - 1] = str[i];
        str[i] = lastChar;
    }
    return str;
}

bool isPalindrome(char str[])
{
    int length_of_str = findLength(str);

    // creating and copying all elements to newStr char array to keep the original array intact and use for compare
    char newStr[length_of_str];
    for (int i = 0; i < length_of_str; i++)
    {
        newStr[i] = str[i];
    }

    // passing the newStr to reverseStr function to return its reverse
    char *reversedStr = reverseStr(newStr, length_of_str);

    for (int i = 0; i < length_of_str; i++)
    {
        if (reversedStr[i] != str[i])
        {
            return false;
        }
    }
    return true;
}