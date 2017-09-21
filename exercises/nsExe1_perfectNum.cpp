/*  suppose x^2 = k (x, k are integers) and n*(n+1)/2 = k
 *  so the k is what we are looking for.
 *  n = (sqrt(8*k+1)-1)/2 must be an integer
 */
#include <iostream>
#include <math.h>

typedef unsigned long long int ULLI;
#define START_SQRT 35

void StartUp(void)
{
    std::cout << "Start searching square of numbers larger than " << START_SQRT << " ..." << std::endl;
}

double Caln(ULLI k)
{
    return (sqrt( 8 * k + 1) - 1) / 2;
}

bool IsInteger(double n)
{
    return (ceil(n) == n);
}

int main(void)
{
    StartUp();

    double x = START_SQRT;
    ULLI k = 0;
    double n = 0;

    int i = 0;

    do
    {
        do
        {
            x++;
            k = x * x;
            n = Caln(k);

        } while (!IsInteger(n));

        std::cout << i << ". The next pecfect number is " << k << ", which is " << x << "^2, and the sum from 1 through " << n << "." << std::endl;

        i++;
    } while(i < 10);

    return 0;
}