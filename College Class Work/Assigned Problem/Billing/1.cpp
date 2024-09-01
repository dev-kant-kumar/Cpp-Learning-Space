// Problem Statement
// Create a class to manage every month item list we place to a dealer
// list include -> item code,price of each item
// performing following operations
// 1 - Adding an item
// 2 - Deleting a item
// 3 - printing total value
// 4 - displaying the entire list

#include <iostream>
#include <conio.h>
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

void addProduct();                           // add product in store
void displayAvailableProducts();             // display available products
void UI();                                   // display options available to perform on item list
void addItem();                              // add item in item list
void deleteItem();                           // delete item from item list - update price to 0 and keep the item intact
void getTotalValue();                        // show total value of all items in item list
void getCompleteList();                      // show complete item list
void commandHandler(int argc, char *argv[]); // handle command line argument to this program

Product item[5];       // store is each product in store
Product itemList[100]; // store the product added to item list
int noOfItemInList = 0;
int totalPrice = 0;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        commandHandler(argc, argv);
    }
    else
    {
        addProduct();
        UI();
    }

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
    MessageBeep(MB_OK); // to confirm product is created
}

void displayAvailableProducts()
{
    system("cls");

    cout << "\n\n"
         << setw(100) << "\033[1;34mWelcome to ABC Store\033[0m\n\n";
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

    string options = " [0] - To exit \n [1] - Add an item \n [2] - Delete an item \n [3] - Check item's total value \n [4] - See complete items list \n";

    displayAvailableProducts();
MainMenu:
    cout << "\033[1;35mSelect from these options for your order cart \033[0m\n\n";
    cout << options << endl;
choiceMenu:
    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";
    choice = _getch();
    if (choice >= '0' && choice <= '9')
    {
        int intVal = choice - '0';
        switch (intVal)
        {
        case 0:
            cout << intVal << endl;
            cout << "\n";
            cout << "You exited\n";
            MessageBeep(MB_ICONQUESTION);
            cout
                << "Bye Hope to see you again!\n\n";
            break;
        case 1:
            cout << intVal << endl;
            cout << "\n";
            cout << "\033[1;37;42m " << setw(55) << "Adding item selected" << "Order List have : " << noOfItemInList << " items \033[0m\n";
            cout << "-----------------------------------------------------------------------------------";
            addItem();
            break;
        case 2:
            cout << intVal << endl;
            cout << "\n";
            cout << "\033[1;37;41m " << setw(55) << "Deleting item selected" << "Order List have : " << noOfItemInList << " items \033[0m\n";
            cout << "-----------------------------------------------------------------------------------";
            deleteItem();
            goto choiceMenu;
            break;
        case 3:
            cout << intVal << endl;
            cout << "\n";
            cout << "\033[1;30;47m " << setw(55) << "Check item's total value selected" << "Order List have : " << noOfItemInList << " items \033[0m\n";
            cout << "-----------------------------------------------------------------------------------";
            getTotalValue();
            goto choiceMenu;
            break;

        case 4:
            cout << intVal << endl;
            cout << "\n";
            cout << "\033[1;32;47m " << setw(55) << "See complete items list selected" << "Order List have : " << noOfItemInList << " items \033[0m\n";
            cout << "-----------------------------------------------------------------------------------";
            getCompleteList();
            goto choiceMenu;
            break;
        default:
            cout << intVal << endl;
            MessageBeep(MB_ICONERROR);
            cout << "\n\n\033[5;31mInvalid options entered! Enter from 1 to 4 only\033[0m\n\n";
            Sleep(1200);
            system("1.exe");
        }
    }
    else
    {
        MessageBeep(MB_ICONERROR);
        cout << "\n\n\033[5;31mInvalid input! Only numbers are allowed.\033[0m\n";
        Sleep(1200);
        system("1.exe");
    }
}

void addItem()
{
addItemMenu:
    int choice;

    cout
        << "\n\033[1;35mSelect from these options \033[0m\n\n";
    cout << "Enter 0 to exit and back to main menu \nEnter 1 to continue\n\n";
    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";

    choice = _getch();
    if (choice >= '0' && choice <= '9')
    {
        int intVal = choice - '0';

        if (intVal == 0)
        {
            cout << intVal;
            cout << "\nBack to Main Menu\n";
            UI();
        }
        else if (intVal == 1)
        {
            cout << intVal;
        addItem:
            // adding item in item list
            int product_code;
            cout << "\n\033[1;36mEnter product code : \033[0m";
            if (cin >> product_code)
            {
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
                        MessageBeep(MB_OK); // confirm item is added

                        cout
                            << "\n"
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
                    MessageBeep(MB_ICONERROR);
                    cout << "\n\n\033[5;31mEnter valid product code to add item \033[0m\n";
                    goto addItem;
                }
            }
            else
            {
                MessageBeep(MB_ICONERROR);
                cout << "\n\n\033[5;31mEnter valid product code only 3 digits allowed! \033[0m\n";
                // goto addItem;
            }
        }
        else
        {
            MessageBeep(MB_ICONERROR);
            cout << "\n\n\033[5;31mInvalid Input! Enter 0 or 1 only\033[0m\n";
            goto addItemMenu;
        }
    }
    else
    {
        MessageBeep(MB_ICONERROR);
        cout << "\n\n\033[5;31mOnly numbers are allowed \033[0m\n";
        Sleep(1000);
        system("1.exe");
    }
}

void deleteItem()
{
    cout << "\n\n";
    int productCode;
EnterProductCode:
    cout
        << "\033[1;36mEnter Product Code : \033[0m";
    if (cin >> productCode)
    {
        // check if the product exist with entered product code
        bool matched = true;
        for (int i = 0; i < 5; i++)
        {
            if (item[i].product_code == productCode)
            {
                itemList[i].product_price = 0;
                MessageBeep(MB_OK); // confirm item is added

                cout
                    << "\n"
                    << itemList[i].product_name << setw(60) << " \033[1;32mDeleted from order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList - 1 << "\n";
                cout << "-----------------------------------------------------------------------------------\n";
                break; // so that only one product can be removed at once
            }
            else
            {
                matched = false;
            }

            if (matched == false)
            {
                MessageBeep(MB_ICONERROR);
                cout << "\n\n\033[5;31mEnter valid product code to delete item \033[0m\n";
                goto EnterProductCode;
            }
        }
    }
    else
    {
        MessageBeep(MB_ICONERROR);
        cout << "\n\n\033[5;31mEnter valid product code to delete item only 3 digit allowed \033[0m\n";
        // goto EnterProductCode;
    }
}

void getTotalValue()
{
    // int totalPrice = 0;
    for (int i = 0; i < noOfItemInList; i++)
    {
        totalPrice += itemList[i].product_price;
    }

    cout << "\nTotal value of your order list : " << totalPrice << "\n\n";
    cout << "-----------------------------------------------------------------------------------\n\n";
}

void getCompleteList()
{
    cout << "\n\n";
    cout << "_______________________________________________\n";
    cout << left; // Left-align the text
    cout << "| " << setw(15) << "\033[1;33mProduct Code\033[0m" << " | " << setw(15) << "\033[1;33mProduct Name\033[0m" << " | " << setw(15) << "\033[1;33mProduct Price\033[0m" << " |" << endl;

    for (int i = 0; i < noOfItemInList; i++)
    {
        cout << "| " << setw(12) << itemList[i].product_code << " | " << setw(12) << itemList[i].product_name << " | " << setw(13) << itemList[i].product_price << " |\n";
    }
    cout << "_______________________________________________\n";
    getTotalValue(); // calling so that totalPrice updated without checking total price so that can be used here in.
    cout << "Total Item : " << setw(18) << noOfItemInList << "Total Price : " << totalPrice << endl;

    cout << "\n\n";
    cout << "-----------------------------------------------------------------------------------\n\n";
}

void commandHandler(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0)
        {
            system("cls");
            cout << "\n\n";
            cout << setw(45) << " " << "welcome to help section\n";
            cout << "____________________________________________________________________________________________________________________\n\n";
            cout << "Help section is under development \n";
            cout << "\n____________________________________________________________________________________________________________________\n\n";
        }
        else if (strcmp(argv[i], "--version") == 0)
        {
            cout << "\n\n\033[1;32mCurrent version is : v01xe1.0\033[0m\n\n";
        }
        else
        {
            cout << "\n\n";
            cout << "\033[5;31mThis command is not recognized as any valid command \033[0m\n";
            cout << "\033[1;34mSee help section to know more information of commands\033[0m\n";
        }
    }
}