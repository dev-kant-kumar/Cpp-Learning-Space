// Write a c++ program to reverse a number and check if the number is palindrome or not
// I am using string for working both on number as well as on string

#include <iostream>
#include <string.h>
using namespace std;

int isPalindrome(char *number);

int main()
{
    char number[100];

    cout << "This c++ program reverse entered number or string and check for palindrome\n\n";
    cout << "Enter the number or string : ";
    cin >> number;

    int status = isPalindrome(number);
    status == 1 ? cout << "This is palindrome number or string \n" : cout << "This is not a palindrome number or string \n";
    return 0;
}

int isPalindrome(char *number)
{
    char original_number[100];
    strcpy(original_number, number);
    strrev(number);
    if (strcmp(number, original_number) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}