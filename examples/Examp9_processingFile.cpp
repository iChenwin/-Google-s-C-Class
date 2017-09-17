#include <fstream>
#include <iostream>

int main()
{
    char first_name[30], last_name[30];
    int age;
    char file_name[20];

    std::cout << "Enter First name: " ; std::cin >> first_name;
    std::cout << "Enter last name:"; std::cin >> last_name;
    std::cout << "Enter Age: "; std::cin >> age;
    std::cout << std::endl << "Enter the name of the file: "; std::cin >> file_name;

    std::ofstream People(file_name, std::ios::out);

    People << first_name << std::endl << last_name << std::endl << age << std::endl; 
    
    std::ifstream Info(file_name, std::ios::in);
    char firstName[30], lastName[30];
    char ageOf[10];
    Info.getline(firstName, 100);
    Info.getline(lastName, 100);
    Info.getline(ageOf, 100);

    std::cout << firstName << std::endl << lastName << std::endl << ageOf << std::endl;
    
    return 0;
}