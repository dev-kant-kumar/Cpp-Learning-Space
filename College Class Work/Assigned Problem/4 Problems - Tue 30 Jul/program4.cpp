// Form greatest and smallest number from 4136

#include <iostream>
using namespace std;
int findGreatestNo(int number[], int size, int *index_of_greatest);
void findSmallestNo(int number[], int size);

int main()
{
    int number[] = {4, 1, 3, 6};
    int size_number = sizeof(number) / sizeof(number[0]); // size of main/original array
    int size_of_array = size_number;                      // size for new array,it will change
    int index_of_greatest;
    int count = 0; // to track the index for greatest number to push in greatest_no array
    int greatest_no[size_number];
    while (size_of_array > 1)
    {
        int new_number[size_of_array - 1]; // new array by removing previous greatest number

        greatest_no[count] = findGreatestNo(number, size_of_array, &index_of_greatest);
        count++;

        // this loop form new array by removing the previous greatest number from array
        for (int i = 0, j = 0; i < size_of_array; i++)
        {
            if (i != index_of_greatest)
            {
                new_number[j] = number[i];
                j++;
            }
        }

        // Copy new_number to number for the next iteration
        for (int i = 0; i < size_of_array - 1; i++)
        {
            number[i] = new_number[i];
        }

        // Update the size_of_array
        size_of_array--;
    }

    // Find the last remaining element and add it to the greatest_no array
    greatest_no[count] = number[0];
    count++;

    // printing final results
    cout << "Greatest number is : ";
    for (int i = 0; i < size_number; i++)
    {
        cout << greatest_no[i];
    }

    findSmallestNo(greatest_no, size_number); // this function reverse the actual array of greatest number

    cout << "\n";
    cout << "Smallest number is : ";
    for (int i = 0; i < size_number; i++)
    {
        cout << greatest_no[i];
    }
    return 0;
}

int findGreatestNo(int number[], int size, int *index_of_greatest)
{
    int greatest = number[0];
    *index_of_greatest = 0;

    for (int i = 1; i < size; i++)
    {
        if (number[i] > greatest)
        {
            greatest = number[i];
            *index_of_greatest = i;
        }
    }
    return greatest;
}

void findSmallestNo(int number[], int size)
{
    // reversing the array of greatest number to form the array of smallest number

    for (int i = 0; i < size / 2; i++)
    {
        int lastNo = number[size - i - 1];
        number[size - i - 1] = number[i];
        number[i] = lastNo;
    }
}