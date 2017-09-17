#include <iostream>

int Input()
{
    int inputValue = 0;

    std::cout << "Number of seconds: ";

    do
    {
        if (std::cin >> inputValue)
            return inputValue;

        std::cout << "Number only!" << std::cout << "retry:";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } while(1);
}

int main()
{
    int seconds = Input();

    int hours = seconds / 3600;
    int minutes = seconds % 3600 / 60;
    int leftSeconds = seconds % 60;

    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Minutes: " << minutes << std::endl;
    std::cout << "Seconds: " << leftSeconds << std::endl;

    return 0;
}