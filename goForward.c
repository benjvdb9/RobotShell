#include <stdio.h>
#include "setPin.h"
#include <stdbool.h>

int main()
{
    char* pinToHigh[2] = {};
    char* pinToLow[2] = {};

    FILE* file = NULL;
    char line[50] = "";
    file = fopen("PinData.txt", "r");
    if (file != NULL)
    {
       int i = 0;
       while (fgets(line, 50, file) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
	   switch (i)
            {
                case 0 :
                    pinToHigh[0] = line;
                    break;
                case 1 :
                    pinToLow[0] = line;
                    break;
                case 2 :
                    pinToHigh[1] = line;
                    break;
                case 3 :
                    pinToLow[1] = line;
                    break;
                default :
                    break;
            }

            i++;
        }
        fclose(file);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier DataPin.txt");
	return -1;
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
	printf("4");
	fflush(stdout);
        key = getchar();
    }

    for (i = 0 ; i < 2 ; i++)
    {
        setPin(pinToHigh[i],"0");
        setPin(pinToLow[i],"0");
    }

    return 0;
}
