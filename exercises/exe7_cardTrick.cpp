// Description: 
// This is a number analogy to a famous card trick. 
// Ask the user to enter a three-digit number. 
// Think of the number as ABC (where A, B, C are the three digits of the number). 
// Now, find the remainders of the numbers formed by ABC, BCA, and CAB when divided by 11. 
// We will call these remainders X, Y, Z. 
// Add them up as X+Y, Y+Z, Z+X. 
// If any of the sums are odd, increase or decrease it by 11 
// (whichever operation results in a positive number less than 20; 
// note if the sum is 9, just report this and stop the process). 
// Finally, divide each of the sums in half. 
// The resulting digits are A, B, C. 
// Write a program that implements this algorithm.

#include <iostream>
#include <stdio.h>

int ReversedToBCA(int origABC)
{
    short bitA = origABC / 100;
    short bitB = (origABC - 100 * bitA) / 10;
    short bitC = origABC % 10;
    
    return bitB * 100 + bitC * 10 + bitA;
}

int ReversedToCAB(int origABC)
{
    short bitA = origABC / 100;
    short bitB = (origABC - 100 * bitA) / 10;
    short bitC = origABC % 10;

    return bitC * 100 + bitA * 10 + bitB;
}

int InputABC(void)
{
    int inputValue = 0;

    std::cout << "Enter a 3 bits integer: ";

    do
    {
        if (!(std::cin >> inputValue))
        {
            std::cout << "Number only! Retry: ";
            continue;
        }

        if (inputValue > 999 || inputValue < 100)
        {
            std::cout << "Between 100~999, retry: ";
            continue;
        }

        break;
    } while(1);

    return inputValue;
}

int main(void)
{
    int origABC = InputABC();

    int numCAB = ReversedToCAB(origABC);
    int numBCA = ReversedToBCA(origABC);

    int remaindX = origABC % 11;
    int remaindY = numBCA % 11;
    int remaindZ = numCAB % 11;

    int addXY = remaindX + remaindY;
    int addYZ = remaindY + remaindZ;
    int addZX = remaindZ + remaindX;

    if ((addXY % 2) == 1)
    {
        if ((addXY + 11) < 20)
            addXY += 11;
        else
            addXY -= 11;

        if (addXY == 9)
            std::cout << "X+Y is 9" << std::endl;
    }

    if ((addYZ % 2) == 1)
    {
        if ((addYZ + 11) < 20)
            addYZ += 11;
        else
            addYZ -= 11;

        if (addYZ == 9)
            std::cout << "Y+Z is 9" << std::endl;
    }

    if ((addZX % 2) == 1)
    {
        if ((addZX + 11) < 20)
            addZX += 11;
        else
            addZX -= 11;

        if (addZX == 9)
            std::cout << "Z+X is 9" << std::endl;
    }

    printf("ABC: %d, CAB: %d, BCA: %d, X: %d, Y: %d, Z: %d, XY: %d, YZ: %d, ZX: %d\n", origABC, numCAB, numBCA, remaindX, remaindY, remaindZ, addXY, addYZ, addZX);

    addXY /= 2;
    addYZ /= 2;
    addZX /= 2;

    printf("A: %d, B: %d, C: %d\n", addXY, addYZ, addZX);

    return 0;
}