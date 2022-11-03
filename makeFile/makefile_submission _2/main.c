#include"register.h"
int main(void)
{
    DDRC = DDRC | 0X1;
    while (1)
    {
        /* code */
        PORTC = PORTC | 0X1;
    }
    return 0;
}