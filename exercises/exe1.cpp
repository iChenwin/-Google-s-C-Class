#include <iostream>

int Input()
{
    int inputValue = 0;

    std::cout << "Number of chirps: ";

    while (!(std::cin >> inputValue))
    {
        std::cout << "Number only!" << std::endl;
        std::cout << "retry:";
    }

    return inputValue;
}

int main()
{
    int freq = 0;
    freq = Input();

    std::cout << "The temperature is: " << (float)(freq + 40 ) / 4 << " degrees" << std::endl;

}