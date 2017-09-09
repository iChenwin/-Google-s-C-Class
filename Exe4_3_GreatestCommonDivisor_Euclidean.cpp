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

//欧几里得算法，递归
int GreatestCommonDivisor(unsigned int small, unsigned int large) {

    //递归到差值为零了，large即为最大公约数，返回。
    if (small == 0) {
        return large;
    }

    //若能整除，直接返回small，即为最大公约数
    if ((large % small) == 0) {
        return small;
    }

    //求差值，比较大小，进行下一层递归
    unsigned int diff = large - small;
    if (small > diff) {
        large = small;
        small = diff;
    } else {
        large = diff;
    }

    GreatestCommonDivisor(small, large);
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

    gcd = GreatestCommonDivisor(small, large);

    std::cout << "The greatest common divisor of " << small << " and " << large << " is " << gcd << std::endl;

    return 0;
}