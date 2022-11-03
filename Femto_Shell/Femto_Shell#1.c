#include <stdio.h>
#include<string.h>
#define MAX 20
int main(void)
{
    while (1)
    {
        /* code */
        char str1[MAX]={0};
        fflush(stdin);
        fflush(stdout);
        fgets(str1,MAX,stdin);
         if(!strcmp(str1,"exit\n")){
            printf("Good Bye :)\n");
            break;
         }
          puts(str1);
    }       
    return 0;
}