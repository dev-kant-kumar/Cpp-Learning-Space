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
#include <windows.h>
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

void addProduct();               // add product in store
void displayAvailableProducts(); // display available products
void UI();                       // display options available to perform on item list
void addItem();                  // add item in item list

Product item[5];       // store is each product in store
Product itemList[100]; // store the product added to item list
int noOfItemInList = 0;

int main()
{
    addProduct();
    UI();

    return 0;
}

void addProduct()
{
    item[0].addProduct(101, "101A", 100);
    item[1].addProduct(102, "102A", 200);
    item[2].addProduct(103, "103A", 300);
    item[3].addProduct(104, "104A", 400);
    item[4].addProduct(105, "105A", 360);
    item[5].addProduct(106, "106A", 1300);
}

void displayAvailableProducts()
{
    system("cls");

    cout << "\n\n\033[1;34mWelcome to ABC Store\033[0m\n\n";
    cout << "\033[1;32m  These item are available in stocks \033[0m\n";
    cout << "_______________________________________________\n";
    cout << left; // Left-align the text
    cout << "| " << setw(15) << "\033[1;33mProduct Code\033[0m" << " | " << setw(15) << "\033[1;33mProduct Name\033[0m" << " | " << setw(15) << "\033[1;33mProduct Price\033[0m" << " |" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "| " << setw(12) << item[i].product_code << " | " << setw(12) << item[i].product_name << " | " << setw(13) << item[i].product_price << " |\n";
    }
    cout << "_______________________________________________\n";

    cout << "\n\n";
}

void UI()
{
    int choice;

    string options = " [1] - Add an item \n [2] - Delete an item \n [3] - Check item's total value \n [4] - See complete items list \n";

    displayAvailableProducts();
MainMenu:
    cout << "\033[1;35mSelect from these options for your order cart \033[0m\n\n";
    cout << options << endl;
    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";
    if (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            cout << "\n";
            cout << setw(55) << "Adding item selected" << "Order List have : " << noOfItemInList << " items\n";
            cout << "-----------------------------------------------------------------------------------";
            addItem();
            break;
        case 2:
            cout << "\nDeleting item selected\n";
            cout << "-----------------------------------------------------------------------------------";
            // deleteItem();
            break;
        case 3:
            cout << "\nCheck item's total value selected\n";
            cout << "-----------------------------------------------------------------------------------";
            break;

        case 4:
            cout << "\nSee complete items list selected\n";
            cout << "-----------------------------------------------------------------------------------";
            break;
        default:
            Beep(750, 100);
            cout << "\n\033[5;31mInvalid options entered! Enter from 1 to 4 only\033[0m\n";
            goto MainMenu;
        }
    }
    else
    {
        Beep(750, 100);
        cout << "\n\033[5;31mInvalid input! Only numbers are allowed.\033[0m\n";
    }
}

void addItem()
{
addItemMenu:
    int choice;

    cout << "\n\033[1;35mSelect from these options \033[0m\n\n";
    cout << "Enter 0 to exit and back to main menu \nEnter 1 to continue\n\n";
    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";

    if (cin >> choice)
    {
        if (choice == 0)
        {
            cout << "\nBack to Main Menu\n";
            UI();
        }
        else if (choice == 1)
        {
        addItem:
            // adding item in item list
            int product_code;
            cout << "\n\033[1;36mEnter product code : \033[0m";
            cin >> product_code;

            // check if the product exist with entered product code
            bool matched = true;
            for (int i = 0; i < 5; i++)
            {
                if (item[i].product_code == product_code)
                {
                    itemList[noOfItemInList].product_code = item[i].product_code;
                    itemList[noOfItemInList].product_name = item[i].product_name;
                    itemList[noOfItemInList].product_price = item[i].product_price;
                    noOfItemInList++;

                    cout << "\n"
                         << itemList[noOfItemInList - 1].product_name << setw(60) << " \033[1;32mAdded to your order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList << "\n";
                    cout << "-----------------------------------------------------------------------------------";

                    goto addItemMenu;
                }
                else
                {
                    matched = false;
                }
            }

            if (matched == false)
            {
                cout << "\n\033[5;31mEnter valid product code to add item \033[0m\n";
                goto addItem;
            }
        }
        else
        {
            cout << "\n\033[5;31mInvalid Input! Enter 0 or 1 only\033[0m\n";
            goto addItemMenu;
        }
    }
    else
    {
        cout << "\n\033[5;31mOnly numbers are allowed \033[0m\n";
        // goto addItemMenu;
    }
}