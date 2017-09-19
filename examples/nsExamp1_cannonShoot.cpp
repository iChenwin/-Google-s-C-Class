
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

float InputAngle(void)
{
    float angle;

    do
    {
        if (!(std::cin >> angle))
        {
            std::cout << "Number only! retry: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        break;
    } while (1);

    return angle;
}

float FireDistance(float angle)
{

    float Velocity = 200.0; // initial velocity of 200 ft/sec
    float Gravity = 32.2; // gravity for distance calculation

    // in_angle is the angle the player has entered, converted to radians.
    float time_in_air = (2.0 * Velocity * sin(angle)) / Gravity;
    float distance = round((Velocity * cos(angle)) * time_in_air);

    return distance;
}

int Fire()
{
    int distance = randomNum();
    std::cout << "The enemy is " << distance << " feet away!!!" << std::endl;
    std::cout << "What angle? ";

    float angle = InputAngle();
    
    float fireDistance = FireDistance(angle);

    int i = 0;
    while (fireDistance != distance && i < 9)
    {
        if (fireDistance > distance)
            std::cout << "You over shot by " << fireDistance - distance << std::endl;
        else
            std::cout << "You under shot by " << distance - fireDistance << std::endl;

        std::cout << "What angle? ";
        angle = InputAngle();
        fireDistance = FireDistance(angle);

        i++;
    }

    if (i == 9)
    {
        std::cout << "enemy arrived!" << std::endl;
        return 0;
    }

    return 1;

}

int main(void)
{
    StartUp();
    int killed = 0;
    char done;
    do {
        killed = Fire();
        std::cout << "You have killed " << killed << " enemy." << std::endl;
        std::cout << "I see another one, care to shoot again? (Y/N) " << std::endl;
        std::cin >> done;
    } while (done != 'n');

    return 0;
}