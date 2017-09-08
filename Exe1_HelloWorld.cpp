#include <iostream>
#include <iomanip>  //setw()

int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //setw(int) 规定列宽度
            std::cout << std::left << std::setw(17) << "Hello world!";
        }
        std::cout << std::endl;
    }

    return 0;
}
