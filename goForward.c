#include <stdio.h>
#include <setPin.h>
#include <stdbool.h>

bool setPin(char* pinNumber, char* value)

int main()
{
    char* pinToHigh[2] = {"11","12"};
    char* pinToLow[2] = {"13","14"};
    int i;

    for (i = 0 ; i < 2 ; i++)
    {
        setPin(pinToHigh[i],1);
    }

    int key = getchar();
    while(key!=115)
    {
        key = getchar();
    }

    return 0;
}
