// Description: Math Puzzles
//reversed number

#include <iostream>

int Input(void)
{
    int inputValue = 0;
    short first = 0, last = 0;

    // std::cout << "Enter a 3 digits integer(the first digit must be greater than its last):";
    do{
        if (std::cin >> inputValue)
        {
            if (inputValue > 998 || inputValue < 100)
            {
                std::cout << "Number must has 3 digits. Retry:";
                continue;
            }
            
            first = inputValue / 100;
            last = inputValue % 10;

            if (first < last)
            {
                std::cout << "The first digit must be greater than its last. Retry:";
                continue;
            }                

            break;
        }

        std::cout << "Number only. Retry:";
    } while(1);

    return inputValue;
}

/*
*    This program takes an integer input from the user. Then the while loop is used until n != 0 is false.
*    In each iteration of while loop, the remainder when n is divided by 10 is calculated and the value of n is reduced by times. 
*/

int ReverseNumber(int orig)
{
    // short first = 0, second = 0, last = 0;

    // first = orig / 100;
    // last = orig % 10;
    // second = (orig - 100 * first - last) / 10;

    // return last * 100 + second * 10 + first;

    int reversedNumber = 0, reminder;

    while (0 != orig)
    {
        reminder = orig % 10;
        reversedNumber = reversedNumber * 10 + reminder;
        orig /= 10;
    }

    return reversedNumber;
}

int main(void)
{
    int orig, reversed, sub, add;

    std::cout << "input number: ";
    orig = Input();
    reversed = ReverseNumber(orig);
    std::cout << "reverse it: " << reversed << std::endl;
    sub = orig - reversed;
    std::cout << "subtract: " << orig << " - " << reversed << " = " << sub << std::endl;
    reversed = ReverseNumber(sub);
    std::cout << "reverse it: " << reversed << std::endl;
    add = reversed + sub;
    std::cout << "add: " << reversed << " + " << sub << " = " << add << std::endl;

    return 0;
}