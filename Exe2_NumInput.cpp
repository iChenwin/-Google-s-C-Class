#include <iostream>
#include <limits>

int main()
{
    int input_var = 0;

    do
    {
        std::cout << "Enter a number(-1 to quit):";

        if (!(std::cin >> input_var))
        {
            std::cout << "a non-numeric character" << std::endl;
            //清空缓存区，http://blog.sina.com.cn/s/blog_8d3652760100wl9r.html
            //http://www.cplusplus.com/reference/limits/numeric_limits/
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }

        if (input_var != -1)
        {
            std::cout << "You have entered " << input_var << std::endl;
        }
    } while (input_var != -1);

    std::cout << "All done" << std::endl;

    return 0;
}