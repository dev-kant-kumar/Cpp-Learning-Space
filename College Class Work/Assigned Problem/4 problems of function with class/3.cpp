// 3. defined your own function to accept two string as an argument and return one if both are similar and zero if different

#include <iostream>
#include <string>
using namespace std;

class CompareString
{
public:
    string str1;
    string str2;
    int len_str1;
    int len_str2;

    CompareString(string str1, string str2)
    {
        this->str1 = str1;
        this->str2 = str2;
        len_str1 = str1.length();
        len_str2 = str2.length();
    }

    bool isSimilar()
    {
        bool status = true;
        cout << "length of string 1 : " << len_str1 << endl;
        cout << "length of string 2 : " << len_str2 << endl;

        if (len_str1 != len_str2)
        {
            status = false;
        }
        else
        {
            for (int i = 0; i < len_str1; i++)
            {
                if (str1[i] != str2[i])
                {
                    status = false;
                    break;
                }
            }
        }
        return status;
    }
};

int main()
{
    string str1, str2;

    cout << "Enter first string : ";
    getline(cin, str1);
    cout << "Enter second string : ";
    getline(cin, str2);

    CompareString obj(str1, str2);

    bool status = obj.isSimilar();

    if (status == true)
    {
        cout << "0 : Both the strings are similar\n";
    }
    else
    {
        cout << "1 : Both the strings are not similar\n";
    }

    return 0;
}