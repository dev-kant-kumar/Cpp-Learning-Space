// Problem Statement
// Create a class to manage every month item list we place to a dealer
// list include -> item code,price of each item
// performing following operations
// 1 - Adding an item
// 2 - Deleting a item
// 3 - printing total value
// 4 - displaying the entire list

#include <iostream>
#include <string>
using namespace std;

void UI();

class Product
{

private:
    int product_code;
    string product_name;
    double product_price;

public:
    Product(int productCode, string productName, double productPrice)
    {
        this->product_code = productCode;
        this->product_name = productName;
        this->product_price = productPrice;
    }
};

int main()
{
    UI();
    return 0;
}

void UI()
{
    int choice;

    cout << "Welcome to \n";

    string options = " [1] - Add an item \n [2] - Delete an item \n [3] - Check item's total value \n [4] - See complete items list \n\n";

    cout << options << endl;
    cout << "Enter your choice {like 1} : ";
    if (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            cout << "Adding item selected\n";
            // addItem();
            break;
        case 2:
            cout << "Deleting item selected\n";
            // deleteItem();
            break;
        case 3:
            cout << "Check item's total value selected\n";
            break;

        case 4:
            cout << "See complete items list selected\n";
            break;
        default:
            cout << "Invalid options entered! Enter from 1 to 4 only\n";
        }
    }
    else
    {
        cout << "Invalid input! Only numbers are allowed.\n";
    }
}