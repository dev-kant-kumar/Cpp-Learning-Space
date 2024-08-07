// 2. WAP to input a name and print the name is short form like : S.K Singh

#include <iostream>
using namespace std;

int main()
{

    char name[100];
    cout << "This c++ program print the name is shortest from \n\n";
    cout << "Enter your name : ";
    cin.getline(name, 100);

    // finding the length of the name
    int length_of_name = 0, i = 0;

    while (name[i] != '\0')
    {
        length_of_name++;
        i++;
    }
    int index_of_space; // storing the last index of whitespace in name
    cout << name[0];    // printing first char of name

    for (int i = 0; i < length_of_name; i++) // printing char after each whitespace and dot in place of whitespace
    {
        if (name[i] == ' ')
        {
            cout << ".";
            cout << name[i + 1];
            index_of_space = i;
        }
    }
    for (int i = index_of_space + 2; i < length_of_name; i++) // printing all char after last whitespace
    {
        cout << name[i];
    }

    return 0;
}