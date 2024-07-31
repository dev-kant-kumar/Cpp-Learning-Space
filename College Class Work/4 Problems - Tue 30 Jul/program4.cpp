// Form greatest and lowest number from 4136

#include <iostream>
using namespace std;

int main()
{
    int number[4] = {4, 1, 3, 6};
    int greatest_no[4], lowest_no[4];
    int count = 0;
    int greatest;
    int index_of_greatest;

    if (number[0] > number[1])
    {
        greatest = number[0];
    }
    else
    {
        greatest = number[1];
    }
    for (int i = 1; i < 4; i++)
    {

        for (int j = i + 1; j <= 3; j++)
        {
            if (number[i] > number[j] && number[i]>greatest)
            {
                greatest = number[i];
                index_of_greatest=i;
            }
        }
        greatest_no[count]=greatest;
        count++;

        // forming new number by removing the previous greatest no
        


    }    

        // cout << "Greatest no formed from 4136 is : ";
        // for (int i = 0; i < 4; i++)
        // {
        //     cout << greatest_no[i];
        // }
        // cout << "\nLowest no formed from 4136 is : ";
        // for (int i = 0; i < 4; i++)
        // {
        //     cout << lowest_no[i];
        // }
    }