#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpcndr.h>

boolean writeInFile(char* file, char* content);

int main()
{
    char* pinForward[2] = {"11","12"};      //gauche, droite
    char* pinBackward[2]= {"13","14"};
    int i;
    char sens[1];
    printf("f : forward, b : backward, r : right, l : left");
    scanf("%s",sens);

    if (sens == "f")
    {
        char* pinToHigh[2] = {pinForward[0], pinBackward[1]};
        char* pinToLow[2] = {pinBackward[0], pinBackward[1]};
    }
    else if (sens == "b")
    {
        char* pinToHigh[2] =  {pinBackward[0], pinBackward[1]};
        char* pinToLow[2] =  {pinForward[0], pinBackward[1]};
    }
    else if (sens == "r")
    {
        char* pinToHigh[2] =  {pinForward[0], pinBackward[1]};
        char* pinToLow[2] =  {pinBackward[0], pinForward[1]};
    }
    else if (sens == "l")
    {
        char* pinToHigh[2] =  {pinBackward[0], pinForward[1]};
        char* pinToLow[2] =  {pinForward[0], pinBackward[1]};
    }


    else
    {
        return 0;
    }

    for (i = 0 ; i < 2 ; i++)
    {

        if(writeInFile("/sys/class/gpio/export", pinForward[i]))
        {
            if(writeInFile(strcat(strcat("/sys/class/gpio/gpio",pinForward[i]),"/direction"), "out"))
            {
                writeInFile(strcat(strcat("/sys/class/gpio/gpio",pinForward[i]),"/value"), "1");
            }
        }
        if(writeInFile("/sys/class/gpio/export", pinBackward[i]))
        {
            if(writeInFile(strcat(strcat("/sys/class/gpio/gpio",pinBackward[i]),"/direction"), "out"))
            {
                writeInFile(strcat(strcat("/sys/class/gpio/gpio",pinBackward[i]),"/value"), "0");
            }
        }
    }

    int key = getchar();
    while(key!=115)
    {
        key = getchar();
    }

    return 0;
}

boolean writeInFile(char* file, char* content)
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

