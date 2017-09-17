#include <iostream>

int main(void)
{
    char dateStr[5] = {0};
    int month = 0, day = 0, year = 0;

    std::cout << "Enter date code: ";

    if (std::cin >> dateStr)
    {
        month = dateStr[0] - 'A' + 1;
        day = (dateStr[1] - 'Q') * 10 + (dateStr[2] - 'Q');
        year = 1995 + (dateStr[3] - 'A' + 1);
    }

    std::cout << year << "/" << month << "/" << day << std::endl;

    return 0;
}