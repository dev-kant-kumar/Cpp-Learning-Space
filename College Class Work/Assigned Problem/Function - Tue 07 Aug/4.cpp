// 4. Define a function to accept two string as an argument and connect both the string and print the string.

#include <iostream>
using namespace std;
void concatStr(char str1[], char str2[]);
int findLength(char str[]);

int main()
{
    char str1[100], str2[100];
    cout << "Enter the first string : ";
    cin.getline(str1, 100);
    cout << "Enter the second string : ";
    cin.getline(str2, 100);
    concatStr(str1, str2);
    return 0;
}

int findLength(char str[])
{
    int length = 0, i = 0;
    while (str[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

void concatStr(char str1[], char str2[])
{
    int length_of_str1 = findLength(str1), length_of_str2 = findLength(str2), count = 0;
    char newStr[length_of_str1 + length_of_str2 + 2]; // for storing both str1 and str2 and 2 for store null char '\0' and whitespace

    // this loop push all the char of str1 to newSte
    for (int i = 0; i < length_of_str1; i++)
    {
        newStr[count] = str1[i];
        count++;
    }

    newStr[count] = ' '; // push a whitespace to separate str1 and str2
    count++;

    // this loop push all the char of str2 to newSte
    for (int i = 0; i < length_of_str2; i++)
    {
        newStr[count] = str2[i];
        count++;
    }

    newStr[count] = '\0';

    // printing the final string formed by concat str1 and str2
    int i = 0;
    while (newStr[i] != '\0')
    {
        cout << newStr[i];
        i++;
    }
    cout << "\n\n";
}