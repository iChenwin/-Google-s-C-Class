#include <iostream>

float CalcMethod2(int weeklySales);
float CalcMethod3(int weeklySales);
float HighestSalary(float salary2, float salary3);

int main()
{
    int weeklySales = 0;
    std::cout << "Input weekly sales:";
    std::cin >> weeklySales;

    float salary2 = CalcMethod2(weeklySales);
    float salary3 = CalcMethod3(weeklySales);

    std::cout << "The salary for " << weeklySales << " weekly sales:" << std::endl;
    std::cout << "  1. Method1: 600" << std::endl;
    std::cout << "  2. Method2: " << salary2 << std::endl;
    std::cout << "  3. Method3: " << salary3 << std::endl;
    std::cout << "------------------ " << std::endl;
    std::cout << "  The highest is " << HighestSalary(salary2, salary3) << std::endl;

    return 0;
}

float CalcMethod2(int weeklySales)
{
    return 7 * 5 * 8 + weeklySales * 225 * 0.1;
}

float CalcMethod3(int weeklySales)
{
    return 20 * weeklySales + weeklySales * 225 * 0.2;
}

float HighestSalary(float salary2, float salary3)
{
    float highest = 600;
    if (highest < salary2)
        highest = salary2;

    if (highest < salary3)
        highest = salary3;

    return highest;
}