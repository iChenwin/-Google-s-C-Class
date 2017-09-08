#include <iostream>

//获取一个大于0的整数
unsigned int InputANumber()
{
    unsigned int input_var = 0;

    do
    {
        if (!(std::cin >> input_var))
        {
            std::cout << "a non-numeric character" << std::endl;
            //清空缓存区，http://blog.sina.com.cn/s/blog_8d3652760100wl9r.html
            //http://www.cplusplus.com/reference/limits/numeric_limits/
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (input_var <= 0)
            std::cout << "Illegal number, retry(>0):";
    } while (input_var <= 0);

    return input_var;
}

int main()
{
    unsigned int small = 0, large = 0, gcd = 1;

    std::cout << "Enter a number(>0):";
    small = InputANumber();
    std::cout << "Enter another number(>0):";
    large = InputANumber();

    if (small > large)
    {
        unsigned int temp = small;
        small = large;
        large = temp;
    }

    if ((large % small) == 0)
    {
        std::cout << "The greatest common divisor of " << small << " and " << large << " is " << small << std::endl;
        return 0;
    }

    for (unsigned int i = 1; i < small; i++)
    {
        if ((small % i) == 0 && (large % i) == 0) {
            gcd = i;
        }
    }

    std::cout << "The greatest common divisor of " << small << " and " << large << " is " << gcd << std::endl;

    return 0;
}