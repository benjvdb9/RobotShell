#include <stdio.h>
#include "setPin.h"
#include <stdbool.h>

int main()
{
    char* pinToHigh[2] = {};
    char* pinToLow[2] = {};

    FILE* file = NULL;
    char line[2] = "";
    file = fopen("PinData.txt", "r");

    if (file != NULL)
    {
        int i = 0;
        while (fgets(line, 2, file) != NULL)
        {
            switch (i)
            {
                case 0 :
                    pinToLow[0] = line;
                    break;
                case 1 :
                    pinToHigh[0] = line;
                    break;
                case 2 :
                    pinToLow[1] = line;
                    break;
                case 3 :
                    pinToHigh[1] = line;
                    break;
                default :
                    break;
            }

            i++;
        }

        fclose(file);
    }
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }

    int i;

    for (i = 0 ; i < 2 ; i++)
    {
        setPin(pinToHigh[i],"1");
        setPin(pinToLow[i],"0");
    }

    int key = getchar();
    while(key!=115)
    {
        key = getchar();
    }

    for (i = 0 ; i < 2 ; i++)
    {
        setPin(pinToHigh[i],"0");
        setPin(pinToLow[i],"0");
    }

    return 0;
}
