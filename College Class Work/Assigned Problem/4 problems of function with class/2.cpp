// 2. WAP to input a name and print the name is short form like : S.K Singh

#include <iostream>
#include <string>
using namespace std;

class nameShortener
{
public:
    string name;
    int len;
    int count = 1;
    int index_of_last_space;

    nameShortener(string name)
    {
        this->name = name;
        this->len = name.length();
    }

    void shortName()
    {
        cout << "Your short name is : " << name[0];

        for (int i = 1; i < len; i++)
        {
            if (name[i] == ' ')
            {
                cout << ".";
                cout << name[i + 1];
                index_of_last_space = i;
            }
        }

        for (int i = index_of_last_space + 2; i < len; i++)
        {
            cout << name[i];
        }
    }
};
int main()
{
    string name;

    cout << "Enter your full name : ";
    getline(cin, name);

    nameShortener obj(name);
    obj.shortName();
    return 0;
}