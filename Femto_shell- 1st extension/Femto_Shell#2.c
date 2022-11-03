#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int main(void)
{
    while (1)
    {
        char str1[MAX] = {0};
        fflush(stdin);
        fflush(stdout);
        fgets(str1, MAX, stdin);
        if (!strcmp(str1, "rand\n"))
        {
            printf("%d\n", rand());
        }
        else if (!strcmp(str1, "fact\n"))
        {
            int num = 1, sum = 1, number = 0;
            printf("Enter a number: ");
            scanf("%d", &number);
            for (int i = 0; i < number; i++)
            {
                sum *= num;
                num++;
            }
            printf("Result is: %d", sum);
            printf("\n");
        }
        else if (!strcmp(str1, "fib\n"))
        {
            int num = 0;
            int first = 0;
            int second = 1;
            int third = 0;
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("\n");
            printf("The sequence is: %d, %d", first, second);
            for (int i = 2; i < num; i++)
            {
                third = first + second;
                printf(", %d", third);
                first = second;
                second = third;
            }
            printf("\n");
        }
        else
        {
            puts(str1);
        }
    }
    return 0;
}