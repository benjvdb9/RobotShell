#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdbool.h>

#define Taille 10000

int main()
{
    int fd;
    char buffer[Taille];
    ssize_t result;
    char *token;
    int longueurChaine;
    char *SecondToken;
    char *suiteChaine;
    int LongueurSecondToken;
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
	    //printf(buffer);

	    token = strtok(buffer, "$");
            //printf("split '$' :  %s \n", token);

	    longueurChaine = strlen(token);
	    //printf("La chaîne : %s compte %d caractères. \n", token ,longueurChaine);
    	    
	    suiteChaine = strstr(token, "GPRMC");
	    if (suiteChaine != NULL)
    	    {
	        //printf("Chaine voulue : %s \n", suiteChaine);
		
		SecondToken = strtok(suiteChaine, ",");
    	    	//printf("SecondToken : %s \n", SecondToken);
		
		i = 0;
		while(SecondToken != NULL)
		{
		    SecondToken = strtok(NULL, ",");
		    //printf("SecondToken : %s \n", SecondToken);
		    //printf("Valeur de I : %d \n", i);

		    if (i<3)
		    {
			LongueurSecondToken = strlen(SecondToken);
			//printf("LongueurSecondToken : %d \n", LongueurSecondToken);
			
			// Pour la Longitude
		        if (LongueurSecondToken == 10)
		        {
			    if (i==2) // car 3ème élément à prendre (0 -> 1 -> 2)
			    {
				printf("Longitude : %s \n \n", SecondToken);
			    }
			    i++;
		        }

			// Pour la latitude
			if (LongueurSecondToken == 9)
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

