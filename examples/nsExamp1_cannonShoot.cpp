// Description: A simple game with a little physics

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const double kVelocity = 200.0;  // initial velocity of 200 ft/sec
const double kGravity = 32.2;  // gravity for distance calculation
const double kPi = 3.1415;

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
    int randomNum = rand() % 1000 + 1;   //1~1000间的随机�?

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

    return angle * kPi / 100;
}

float FireDistance(float angle)
{
    // in_angle is the angle the player has entered, converted to radians.
    float time_in_air = (2.0 * kVelocity * sin(angle)) / kGravity;
    float distance = round((kVelocity * cos(angle)) * time_in_air);

    return distance;
}

int CheckShot() {
  
    int distance;
    double angle;
    std::cout << "What angle? " << std::endl;
    if (!(std::cin >> angle))
        return -1;

    // Convert to radians.
    angle = (angle * kPi) / 180.0;
    distance =  FireDistance(angle);
    return distance;
  }

int Fire(int killed)
{
    int enemy = randomNum();
    std::cout << "The enemy is " << enemy << " feet away!!!" << std::endl;
    // std::cout << "What angle? ";

    // float angle = InputAngle();
    
    float distance = 0;
    int hit = 0;
    int i = 0;
    do
    {
        distance = CheckShot();
        
        if (abs(distance - enemy) <= 1)
        {
            hit = 1;
            killed++;
            std::cout << "You hit him!!!" << std::endl;
            std::cout << "It took you " << i + 1 << " shots." << std::endl;
            std::cout << "You have killed " << killed << " enemies." << std::endl;
        } else {
            if (distance > enemy)
                std::cout << "You over shot by " << distance - enemy << std::endl;
            else
                std::cout << "You under shot by " << enemy - distance << std::endl;
        }

        i++;
    } while ((!(hit)) && (i < 10));

    if (10 == i)
        std::cout << "You have run out of ammo..." << std::endl;

    return killed;

} 

int main(void)
{
    StartUp();
    int killed = 0;
    char done;
    do {
        killed = Fire(killed);
        // std::cout << "You have killed " << killed << " enemy." << std::endl;
        std::cout << "I see another one, care to shoot again? (Y/N) " << std::endl;
        std::cin >> done;
    } while (done != 'n');

    return 0;
}