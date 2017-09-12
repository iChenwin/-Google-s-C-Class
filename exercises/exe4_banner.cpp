#include <iostream>

int PrintI()
{
    for (int i = 0; i < 5; i++)
        std::cout << "I";
    std::cout << std::endl;

    for (int i = 0; i < 3; i++)
        std::cout << "  I  " << std::endl;
    
    for (int i = 0; i < 5; i++)
        std::cout << "I";
    std::cout << std::endl;

    return 0;
}

int main()
{
    PrintI();
    
    return 0;
}