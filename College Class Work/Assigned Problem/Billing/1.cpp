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
    int product_quantity;

    void addProduct(int productCode, string productName, float productPrice, int productQuantity)
    {
        product_code = productCode;
        product_name = productName;
        product_price = productPrice;
        product_quantity = productQuantity;
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
double discountCal(int totalPrice);          // calculate the discount over total price

Product item[5];       // store is each product in store
Product itemList[100]; // store the product added to item list
int noOfItemInList = 0;
int noOfUniqueItemInList = 0;
int noOfItemDeleted = 0;
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

// ==========================================================================
// Function : Add Product
// ==========================================================================

void addProduct()
{
    item[0].addProduct(101, "101A", 100, 100);
    item[1].addProduct(102, "102A", 200, 100);
    item[2].addProduct(103, "103A", 300, 100);
    item[3].addProduct(104, "104A", 400, 100);
    item[4].addProduct(105, "105A", 360, 100);
    MessageBeep(MB_OK); // to confirm product is created
}

void displayAvailableProducts()
{
    system("cls");

    string store_name = R"(
   __    ____   ___    ___  ____  _____  ____  ____ 
  /__\  (  _ \ / __)  / __)(_  _)(  _  )(  _ \( ___)
 /(__)\  ) _ <( (__   \__ \  )(   )(_)(  )   / )__) 
(__)(__)(____/ \___)  (___/ (__) (_____)(_)\_)(____)
)";

    string store_name1 = R"(                                                                                               
                                                                                               
   ,---,           ,---,.   ,----..            .--.--.       ___                               
  '  .' \        ,'  .'  \ /   /   \          /  /    '.   ,--.'|_                             
 /  ;    '.    ,---.' .' ||   :     :        |  :  /`. /   |  | :,'   ,---.    __  ,-.         
:  :       \   |   |  |: |.   |  ;. /        ;  |  |--`    :  : ' :  '   ,'\ ,' ,'/ /|         
:  |   /\   \  :   :  :  /.   ; /--`         |  :  ;_    .;__,'  /  /   /   |'  | |' | ,---.   
|  :  ' ;.   : :   |    ; ;   | ;             \  \    `. |  |   |  .   ; ,. :|  |   ,'/     \  
|  |  ;/  \   \|   :     \|   : |              `----.   \:__,'| :  '   | |: :'  :  / /    /  | 
'  :  | \  \ ,'|   |   . |.   | '___           __ \  \  |  '  : |__'   | .; :|  | ' .    ' / | 
|  |  '  '--'  '   :  '; |'   ; : .'|         /  /`--'  /  |  | '.'|   :    |;  : | '   ;   /| 
|  :  :        |   |  | ; '   | '/  :        '--'.     /   ;  :    ;\   \  / |  , ; '   |  / | 
|  | ,'        |   :   /  |   :    /           `--'---'    |  ,   /  `----'   ---'  |   :    | 
`--''          |   | ,'    \   \ .'                         ---`-'                   \   \  /  
               `----'       `---`                                                     `----' 
)";

    cout << "\n\n\033[1;34m"
         << setw(50) << store_name1 << "\033[0m\n\n";
    cout << "\033[1;32m  These item are available in store \033[0m\n";
    cout << "_____________________________________________________________________\n";
    cout << left; // Left-align the text
    cout << "| " << setw(15) << "\033[1;33mProduct Code\033[0m" << " | " << setw(15) << "\033[1;33mProduct Name\033[0m" << " | " << setw(15) << "\033[1;33mProduct Price\033[0m" << " | " << setw(15) << "\033[1;33mQuantity In Stocks \033[0m" << " |" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "| " << setw(12) << item[i].product_code << " | " << setw(12) << item[i].product_name << " | " << setw(13) << item[i].product_price << " | " << setw(19) << item[i].product_quantity << " | \n";
    }
    cout << "_____________________________________________________________________\n";

    cout << "\n\n";
}

void UI()
{
    string options = " [0] - To exit \n [1] - Add an item \n [2] - Delete an item \n [3] - Check item's total value \n [4] - See complete items list \n";

    displayAvailableProducts();
MainMenu:

    cout << "\033[1;35mSelect from these options for your order cart \033[0m\n\n";
    cout << options << endl;

choiceMenu:

    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";
    char choice = _getch();
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
            cout << "\033[1;34;47m " << setw(55) << "See complete items list selected" << "Order List have : " << noOfItemInList << " items \033[0m\n";
            cout << "-----------------------------------------------------------------------------------";
            getCompleteList();
            goto choiceMenu;
            break;
        default:
            cout << intVal << endl;
            MessageBeep(MB_ICONERROR);
            cerr << "\n\n\033[5;31mInvalid options entered! Enter from 1 to 4 only\033[0m\n\n";
            Sleep(1200);
            system("1.exe");
        }
    }
    else
    {
        MessageBeep(MB_ICONERROR);
        cerr << "\n\n\033[5;31mInvalid input! Only numbers are allowed.\033[0m\n";
        Sleep(1200);
        system("1.exe");
    }
}

void addItem()
{
addItemMenu:
    char choice;

    cout
        << "\n\033[1;35mSelect from these options \033[0m\n\n";
    cout << "Enter 0 to exit and back to main menu \nEnter 1 to continue\n\n";
    cout << "\033[1;36mEnter your choice {like 1} : \033[0m";

    choice = _getch();
    if (choice >= '0' && choice <= '9')
    {
        int intVal = choice - '0'; // converting choice to equivalent int value

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
                        if (noOfUniqueItemInList >= 1)
                        {
                            bool itemNotInList = false;
                            for (int i = 0; i < noOfUniqueItemInList; i++)
                            {

                                if (itemList[i].product_code == product_code)
                                {
                                    itemList[i].product_quantity++;
                                    totalPrice += itemList[i].product_price;
                                    noOfItemInList++;
                                    MessageBeep(MB_OK); // confirm item is added

                                    cout
                                        << "\n"
                                        << itemList[i].product_name << setw(60) << " \033[1;32mAdded to your order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList << "\n";
                                    cout << "-----------------------------------------------------------------------------------";

                                    goto addItemMenu;
                                }
                                else
                                {
                                    itemNotInList = true;
                                }
                            }
                            if (itemNotInList == true)
                            {
                                itemList[noOfUniqueItemInList].product_code = item[i].product_code;
                                itemList[noOfUniqueItemInList].product_name = item[i].product_name;
                                itemList[noOfUniqueItemInList].product_price = item[i].product_price;
                                itemList[noOfUniqueItemInList].product_quantity = 1;
                                totalPrice += itemList[noOfUniqueItemInList].product_price;
                                noOfItemInList++;
                                noOfUniqueItemInList++;
                                MessageBeep(MB_OK); // confirm item is added

                                cout
                                    << "\n"
                                    << itemList[noOfUniqueItemInList - 1].product_name << setw(60) << " \033[1;32mAdded to your order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList << "\n";
                                cout << "-----------------------------------------------------------------------------------";

                                goto addItemMenu;
                            }
                        }
                        else
                        {
                            itemList[noOfUniqueItemInList].product_code = item[i].product_code;
                            itemList[noOfUniqueItemInList].product_name = item[i].product_name;
                            itemList[noOfUniqueItemInList].product_price = item[i].product_price;
                            itemList[noOfUniqueItemInList].product_quantity = 1;
                            totalPrice += itemList[noOfUniqueItemInList].product_price;
                            noOfItemInList++;
                            noOfUniqueItemInList++;
                            MessageBeep(MB_OK); // confirm item is added

                            cout
                                << "\n"
                                << itemList[noOfUniqueItemInList - 1].product_name << setw(60) << " \033[1;32mAdded to your order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList << "\n";
                            cout << "-----------------------------------------------------------------------------------";

                            goto addItemMenu;
                        }
                    }
                    else
                    {
                        matched = false;
                    }
                }

                if (matched == false)
                {
                    MessageBeep(MB_ICONERROR);
                    cerr << "\n\n\033[5;31mEnter valid product code to add item \033[0m\n";
                    goto addItem;
                }
            }
            else
            {
                MessageBeep(MB_ICONERROR);
                cerr << "\n\n\033[5;31mEnter valid product code only 3 digits allowed! \033[0m\n";
                // goto addItem;
            }
        }
        else
        {
            MessageBeep(MB_ICONERROR);
            cerr << "\n\n\033[5;31mInvalid Input! Enter 0 or 1 only\033[0m\n";
            goto addItemMenu;
        }
    }
    else
    {
        MessageBeep(MB_ICONERROR);
        cerr << "\n\n\033[5;31mOnly numbers are allowed \033[0m\n";
        Sleep(1000);
        system("1.exe");
    }
}

void deleteItem()
{
    cout << "\n\n";
    if (noOfItemInList >= 1)
    {
        int productCode;
    EnterProductCode:
        cout
            << "\033[1;36mEnter Product Code : \033[0m";
        if (cin >> productCode)
        {

            bool matched = false; // check the if product found
            for (int i = 0; i < noOfUniqueItemInList; i++)
            {
                if (itemList[i].product_code == productCode)
                {
                    matched = true; // product found
                    if (itemList[i].product_quantity > 1)
                    {
                        itemList[i].product_quantity--;
                        totalPrice -= (itemList[i].product_price);
                        noOfItemDeleted++;
                        MessageBeep(MB_OK); // confirm item is deleted

                        cout
                            << "\n"
                            << itemList[i].product_name << setw(60) << " \033[1;32mDeleted from order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList - 1 << "\n";
                        cout << "-----------------------------------------------------------------------------------\n";
                    }
                    else if (itemList[i].product_quantity == 1)
                    {
                        itemList[i].product_quantity--;
                        totalPrice -= (itemList[i].product_price);
                        itemList[i].product_price = 0;
                        noOfItemDeleted++;
                        // noOfUniqueItemInList--;
                        MessageBeep(MB_OK); // confirm item is deleted

                        cout
                            << "\n"
                            << itemList[i].product_name << setw(60) << " \033[1;32mDeleted from order list\033[0m" << "\033[1;32mTotal item is order list : \033[0m" << noOfItemInList - 1 << "\n";
                        cout << "-----------------------------------------------------------------------------------\n";
                    }
                    else
                    {

                        MessageBeep(MB_ICONERROR);
                        cerr << "\n\033[5;31mThis item is already deleted\033[0m\n\n";
                        goto EnterProductCode;
                    }
                }
            }
            if (matched == false)
            {
                MessageBeep(MB_ICONERROR);
                cerr << "\n\n\033[5;31mEnter valid product code to delete item \033[0m\n";
                goto EnterProductCode;
            }
        }
        else
        {
            MessageBeep(MB_ICONERROR);
            cerr << "\n\n\033[5;31mEnter valid product code to delete item only 3 digit allowed \033[0m\n";
            // goto EnterProductCode;
        }
    }
    else
    {
        MessageBeep(MB_ICONERROR);
        cerr << "\n\033[5;31mThere is no item in order list! \033[0m\n\n";
    }
}

void getTotalValue()
{
    cout << "\nTotal value of your order list : " << totalPrice << "\n\n";
    cout << "-----------------------------------------------------------------------------------\n\n";
}

void getCompleteList()
{

    cout << "\n\n";
    cout << "________________________________________________________________________________________\n";
    cout << left; // Left-align the text
    cout << "| " << setw(15) << "\033[1;33mProduct Code\033[0m" << " | " << setw(15) << "\033[1;33mProduct Name\033[0m" << " | " << setw(15) << "\033[1;33mProduct Quantity\033[0m" << " | " << setw(15) << "\033[1;33mProduct Price\033[0m" << " | " << setw(15) << "\033[1;33mProduct Total Price\033[0m" << " |" << endl;

    for (int i = 0; i < noOfUniqueItemInList; i++)
    {
        cout << "| " << setw(12) << itemList[i].product_code << " | " << setw(12) << itemList[i].product_name << " | " << setw(16) << itemList[i].product_quantity << " | " << setw(13) << itemList[i].product_price << " | " << setw(19) << itemList[i].product_quantity * itemList[i].product_price << " |\n";
    }
    cout << "________________________________________________________________________________________\n\n";

    cout << "Total Item   : " << setw(55) << noOfItemInList << "Total Price : " << totalPrice << endl;
    cout << "Deleted Item : " << setw(55) << noOfItemDeleted << "Discount    : " << discountCal(totalPrice) << endl;
    cout << "________________________________________________________________________________________\n";
    cout << "Current Item : " << setw(55) << noOfItemInList - noOfItemDeleted << "Final Price : " << totalPrice - discountCal(totalPrice) << endl;

    cout << "\n\n";
    cout << "-----------------------------------------------------------------------------------\n\n";
}

double discountCal(int totalPrice)
{

    double discount;
    if (totalPrice >= 800 && totalPrice <= 1500)
    {
        // discount of 0.5%
        discount = (totalPrice * 0.5) / 100;
    }
    else if (totalPrice > 1501 && totalPrice <= 2500)
    {
        // discount of 1%
        discount = (totalPrice * 1) / 100;
    }
    else if (totalPrice > 2550)
    {
        // discount of 1.5%
        discount = (totalPrice * 1.5) / 100;
    }
    else
    {
        discount = 0;
    }
    return discount;
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
            cerr << argv[i] << " \033[5;31mThis command is not recognized as any valid command \033[0m\n";
            cout << "\033[1;34mSee help section to know more information of commands\033[0m\n";
            break;
        }
    }
}