// Description: Illustrate the use of cin to get input.

#include <iostream>

int Input(char *s)
{
    int inputValue = 0;

    std::cout << "Enter the score for the " << s <<". ";

    do
    {
        if (std::cin >> inputValue)
            break;
        
        std::cout << "Number only! Retry: ";
    } while(1);

    return inputValue;
}

int main()
{
    char *assignments[4] = {(char *)"first assignment", (char *)"second assignment", (char *)"third assignment", (char *)"fourth assignment"};
    int assignmentScores[4] = {0};
    float assignmentAverage = 0;

    for (int i = 0; i < 4; i++)
    {
        assignmentScores[i] = Input(assignments[i]);
        assignmentAverage += assignmentScores[i];
    }

    assignmentAverage /= 4;

    int midtermScore = Input((char *)"midterm");
    int finalScore = Input((char *)"final");
    int classScore = Input((char *)"section grade");
    float finalGrade = assignmentAverage * 0.4 + midtermScore * 0.15 + finalScore * 0.35 + classScore * 0.1;
    std::cout << "The final grade is: " << finalGrade << std::endl;
}