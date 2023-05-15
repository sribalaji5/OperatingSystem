#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i;
    pid_t pid[4];
    for (i = 0; i < 4; i++)
    {
        pid[i] =fork();
        if (pid[i] == -1)
        {
            printf("Error");
            exit(1);
        }
        else if (pid[i] == 0)
        {
            if (i == 0)
            {
                printf("Odd numbers: ");
                for (int j = 1; j <= 10; j += 2)
                    printf("%d ", j);
            }
            else if (i == 1)
            {
                printf("\nEven numbers: ");
                for (int j = 2; j <= 10; j += 2)
                    printf("%d ", j);
            }
            else if (i == 2)
            {
                printf("\nMultiples of 3: ");
                for (int j = 3; j <= 30; j += 3)
                    printf("%d ", j);
            }
            else if (i == 3)
            {
                printf("\nMultiples of 5: ");
                for (int j = 5; j <= 50; j += 5)
                    printf("%d ", j);
            }
            printf("\nProcess ID: %d\n", getpid());
            exit(0);
        }
    }
    return 0;
}