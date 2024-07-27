#include <iostream>

int main()
{
    char name[20];
    std::cout << "Enter your name: ";
    std::cin.getline(name, 20);

    std::cout << "Your name is " << name << std::endl;

    return 0;
}