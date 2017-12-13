#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool writeInFile(char* file, char* content);


bool setPin(char* pinNumber, char* value)
{
    if(writeInFile("/sys/class/gpio/export", pinNumber))
    {
        if(writeInFile(strcat(strcat("/sys/class/gpio/gpio",pinNumber),"/direction"), "out"))
        {
            writeInFile(strcat(strcat("/sys/class/gpio/gpio",pinNumber),"/value"), value);
        }

    }
}

bool writeInFile(char* file, char* content)
{
    FILE* fichier = NULL;
    fichier = fopen(file, "w");

    if (fichier != NULL)
    {
        fputs(content, fichier);
        fclose(fichier);
        return 1;
    }
    else
    {
        printf(strcat("Impossible d'ouvrir le fichier ", file));
        return 0;
    }
}