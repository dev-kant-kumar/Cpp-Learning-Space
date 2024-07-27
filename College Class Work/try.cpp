#include <iostream>
using namespace std;
int main()
{
    int num;
    int i, j;
    char a[4]= "BCA";
    cout << "Enter 1 or 2: ";
    cin >> num;
    switch (num)
    {
    case 1:

        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j <=i; j+3)
        //     {
        //         cout<<" a[i]";
        //     }cout<<"\n";
        //     for (int k = 0; k <= i; k++)
        //     {
        //         cout<<"\t";
        //     }
            
            
        // }
        
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j >= i; j--)
            {
                if (i == 1)
                {
                    cout << "B";
                }
                if ((j == 2) and (i == 2))
                {
                    cout << "C";
                }
                if ((j == 3) and (i == 3))
                {
                    cout << "A";
                }
                
                
                    cout << " ";
                
                cout << "\n";
            }
        }

    }
    return 0;
}