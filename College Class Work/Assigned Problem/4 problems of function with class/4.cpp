// 4. Define a function to accept two string as an argument and connect both the string and print the string.

#include <iostream>
#include <string>
using namespace std;

class StrCat
{
public:
    string str1;
    string str2;

    StrCat(string str1, string str2)
    {
        this->str1 = str1;
        this->str2 = str2;
    }

    string connectStr()
    {
        return str1 + ' ' + str2;
    }
};

int main()
{
    string str1, str2;

    cout << "Enter the first string : ";
    getline(cin, str1);

    cout << "Enter the second string : ";
    getline(cin, str2);

    StrCat obj(str1, str2);

    string newStr = obj.connectStr();

    cout << "String after concatenating string 1 and string 2 : " << newStr << endl;

    return 0;
}