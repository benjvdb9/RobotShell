#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdbool.h>

#define SIZE 10000

int main()
{
    int fd;
    char buffer[SIZE];
    ssize_t result;
    char *token;
    char *SecondToken;
    int LenToken;
    int LenSecondToken;
    char *ChoiceChar;
    int i;

    fd = open("/dev/ttyS0", O_RDONLY);
    
    if(fd == -1)
    {
        perror("Ouverture impossible \n");
        return (EXIT_FAILURE);
    }

    while(1)
    {
        result = read(fd, buffer, sizeof(buffer));
        
        // read fail
        if(result == -1)
        {
            perror("ERROR (read process) ");
            exit(EXIT_FAILURE);
        }
        
        // no data
        if(!result)
        {
            printf("no data\n");
            printf(buffer);
        }
        
        // data received
        if(result > 0)
        {
            buffer[result] = 0;
            
            // Split data by $
            token = strtok(buffer, "$");

            LenToken = strlen(token);
            //printf("La chaîne : %s compte %d caractères. \n", token ,LenToken);
            
            // Specify the interresting data
            ChoiceChar = strstr(token, "GPRMC");
            if (ChoiceChar != NULL)
                {
                    /* Split "token data" by "," because with GPRMC, there are
                     several data like speed, time, ... separated by ',' */
                    SecondToken = strtok(ChoiceChar, ",");
                    //printf("SecondToken : %s \n", SecondToken);
                    
                    i = 0;
                    while(SecondToken != NULL)
                    {
                        SecondToken = strtok(NULL, ",");
                        //printf("SecondToken : %s \n", SecondToken);
                        //printf("Valeur de I : %d \n", i);

                        // To sort out the different SecondToken
                        if (i<3)
                        {
                            LenSecondToken = strlen(SecondToken);
                            //printf("LenSecondToken : %d \n", LenSecondToken);
                            
                            // To Longitude
                            if (LenSecondToken == 10)
                            {
                                if (i==2) // 3rd elem to get (0 -> 1 -> 2)
                                {
                                    printf("Longitude : %s \n \n", SecondToken);
                                }
                                i++;
                            }

                            // To latitude
                            if (LenSecondToken == 9)
                            {
                                printf("Latitude : %s \n", SecondToken);
                                i++;
                            }
                        }
                     }
                 }
             }
        }
    close(fd);
    return (EXIT_SUCCESS);
}

