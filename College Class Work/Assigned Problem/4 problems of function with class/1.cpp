// 1. Declare a function to input a string and check the entered string is palindrome or not.

#include <iostream>
#include <string>
using namespace std;

class reverseStr
{

public:
    string text;
    int len;
    string text_reverse;

    reverseStr(string text)
    {
        this->text = text;
        this->len = text.length();
        this->text_reverse = text;

        // calling required fun to get done the tasks
        reverse();
    }

    void reverse()
    {
        // this function will reverse the text_reverse
        char lastChar;
        for (int i = 0; i < len / 2; i++)
        {
            lastChar = text_reverse[len - i - 1];
            text_reverse[len - i - 1] = text_reverse[i];
            text_reverse[i] = lastChar;
        }
    }

    bool isPalindrome()
    {
        cout << "After reverse string is : " << text_reverse << endl;
        bool status = true;
        for (int i = 0; i < len; i++)
        {
            if (text[i] != text_reverse[i])
            {
                status = false;
                break;
            }
        }
        return status;
    }
};

int main()
{
    string inputStr;

    cout << "Enter the string : ";
    getline(cin, inputStr);

    reverseStr obj1(inputStr);

    bool status = obj1.isPalindrome();
    if (status == true)
    {
        cout << obj1.text << " is a palindrome string \n";
    }
    else
    {
        cout << obj1.text << " is not a palindrome string \n";
    }

    return 0;
}