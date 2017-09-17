#include <iostream>
#include <stdio.h>

#define HORSE 10
#define PIG   3
#define RABBIT 0.5

int main()
{
    int horses = 100 / HORSE;
    int pigs = 100 / PIG;
    int rabbits = 100 / RABBIT; 
    for (int i = 0; i < horses; i++)
    {
        for (int j = 0; j < pigs; j++)
        {
            for (int k = 0; k < rabbits; k++)
            {
                if ((i * HORSE + j * PIG + k * RABBIT) == 100)
                {
                    printf("horses:%d, pig:%d, rabbit:%d\n", i, j, k);
                }
            }
        }
    }

    return 0;
}
