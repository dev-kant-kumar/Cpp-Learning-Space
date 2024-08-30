// Problem Statement
// Create a class to manage every month item list we place to a dealer
// list include -> item code,price of each item
// performing following operations
// 1 - Adding an item
// 2 - Deleting a item
// 3 - printing total value
// 4 - displaying the entire list

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{

public:
    int product_code;
    string product_name;
    double product_price;

    void addProduct(int productCode, string productName, float productPrice)
    {
        product_code = productCode;
        product_name = productName;
        product_price = productPrice;
    }
};

void displayAvailableProducts(Product items[]);
void UI();
void addItem();

int main()
{
    Product item[5];
    item[0].addProduct(101, "101A", 100);
    item[1].addProduct(102, "102A", 200);
    item[2].addProduct(103, "103A", 300);
    item[3].addProduct(104, "104A", 400);
    item[4].addProduct(105, "105A", 360);
    item[5].addProduct(106, "106A", 1300);

    displayAvailableProducts(item);

    UI();

    return 0;
}

void displayAvailableProducts(Product items[])
{

    cout << "\n\n\033[1;34mWelcome to ABC Store\033[0m\n\n";
    cout << "\033[1;32m  These item are available in stocks \033[0m\n";
    cout << "_______________________________________________\n";
    cout << left; // Left-align the text
    cout << "| " << setw(15) << "\033[1;33mProduct Code\033[0m" << " | " << setw(15) << "\033[1;33mProduct Name\033[0m" << " | " << setw(15) << "\033[1;33mProduct Price\033[0m" << " |" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "| " << setw(12) << items[i].product_code << " | " << setw(12) << items[i].product_name << " | " << setw(13) << items[i].product_price << " |\n";
    }
    cout << "_______________________________________________\n";

    cout << "\n\n";
}

void UI()
{
    int choice;

    string options = " [1] - Add an item \n [2] - Delete an item \n [3] - Check item's total value \n [4] - See complete items list \n";

    cout << "\033[1;35mSelect from these options for your order cart \033[0m\n\n";
    cout << options << endl;
    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";
    if (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            cout << "Adding item selected\n";
            addItem();
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
            cout << "\033[5;31mInvalid options entered! Enter from 1 to 4 only\033[0m\n";
        }
    }
    else
    {
        cout << "\033[5;31mInvalid input! Only numbers are allowed.\033[0m\n";
    }
}

void addItem()
{
}
