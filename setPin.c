#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool writeInFile(char* file, char* content);

bool setPin(char* pinNumber, char* value)
{
    printf("0");
    fflush(stdout);
    if(writeInFile("/sys/class/gpio/export", "1"))
    {
	char* buffer[100];
        
	
	if(writeInFile(strcat(buffer,"/direction"), "out"))
        {
	    printf("2");
	    fflush(stdout);
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
