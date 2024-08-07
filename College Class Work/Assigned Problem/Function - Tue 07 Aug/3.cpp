// 3. defined your own function to accept two string as an argument and return one if both are similar and zero if different

#include <iostream>
using namespace std;
int isSimilar(char str1[], char str2[]);

int main()
{
    char str1[100], str2[100];
    cout << "Enter your first string : ";
    cin.getline(str1, 100);
    cout << "Enter your second string : ";
    cin.getline(str2, 100);

    int status = isSimilar(str1, str2);
    if (status == 1)
    {
        cout << "Both stirng is similar \n";
    }
    else
    {
        cout << "Both string is not similar \n";
    }
    return 0;
}

int isSimilar(char str1[], char str2[])
{
    int length_of_str1 = 0, i = 0;

    while (str1[i] != '\0')
    {
        length_of_str1++;
        i++;
    }

    for (int i = 0; i < length_of_str1; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        return 1;
    }
}