#include <iostream>

int Input()
{
    int inputValue = 0;

    std::cout << "Number of chirps: ";

    do
    {
        if (std::cin >> inputValue)
            break;

        std::cout << "Number only!" << std::cout << "retry:";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } while (1);

    return inputValue;
}

int main()
{
    int freq = 0;
    freq = Input();

    std::cout << "The temperature is: " << (float)(freq + 40 ) / 4 << " degrees" << std::endl;

}