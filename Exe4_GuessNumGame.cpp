#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    //生成随机数：http://blog.csdn.net/candyliuxj/article/details/4396666
    //配合srand()随机数发生器一起使用，产生不同的随机数，得给srand()一个变化的随机数子数，通常使用时间作为随机种子
    srand((unsigned)time(NULL));
    int secretNum = rand() % 100 + 1;   //1~100间的随机数
    int guessNum = 0;
    int i = 0;

    do
    {
        std::cout << "Enter your number(between 1~100, -1 to quit!):";

        if (!(std::cin >> guessNum))
        {
            std::cout << "Not a number, try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (guessNum == -1)
        {
            std::cout << "Quit!" << std::endl;
            break;
        }

        if (secretNum == guessNum)
        {
            std::cout << "You win! You have tried " << i+1 << " times" << std::endl;
        } else if (secretNum > guessNum)
        {
            i++;
            std::cout << "Too small, try a larger number" << std::endl;
        } else
        {
            i++;
            std::cout << "Too large, try a smaller number" << std::endl;
        }
    } while(guessNum != secretNum);

    return 0;
}