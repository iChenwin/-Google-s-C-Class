
#include <iostream>
#include <stdlib.h>
#include <time.h>

int StartUp(void) {
    std::cout << "Welcome to Artillery.\n\
You are in the middle of a war and being charged by thousands of enemies.\n\
You have one cannon, which you can shoot at any angle.\n\
You only have 10 cannonballs for this target..\n\
Let's begin...\n" << std::endl;

    return 0;
}

int randomNum(void)
{
    srand((unsigned)time(NULL));
    int randomNum = rand() % 1000 + 1;   //1~1000间的随机数

    return randomNum;
}

float FireDistance(float angle)
{
    return 0;
}

int Fire()
{
    int distance = randomNum();
    std::cout << "The enemy is " << distance << " feet away!!!" << std::endl;
    std::cout << "What angle? ";

    return 0;

}

int main(void)
{
    StartUp();
    int killed = 0;
    char done;
    do {
        killed = Fire();
        std::cout << "I see another one, care to shoot again? (Y/N) " << std::endl;
        std::cin >> done;
    } while (done != 'n');

    return 0;
}