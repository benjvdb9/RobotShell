#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

pid_t fork(void);
void wait(int*);

int main()
{
    while (1)
    {

        char commandes[3][50] = {"goForward", "goBackward", "TurnLeft", "TurnRight", "gps", "setpin", ""};
        char commande[50];
        int i;
        bool commandExist = 0;
        printf(">");
        scanf("%s",commande);
        for (i = 0 ; i < 3 ; i++)
        {
            if (strcmp(commande, commandes[i]) == 0)
            {
                commandExist = 1 ;
            }
        }

        if (commandExist)
        {
            pid_t pid = fork();
            if(pid < 0)
            {
                printf("une erreur s'est produite. \n");
            }
            else if (pid == 0)
            {
                char *const argv[] = {};
                printf("hello");
                fflush(stdout);
                if (strcmp(commande,"goForward") == 0)
                {
                    if (execv("./goForward", NULL) == -1)
                    {
                        perror("execv");
                        return 0;
                    }

                }
                else if (strcmp(commande, "gps") == 0)
                {
                    if (execv("./gps", NULL) == -1) {
                        perror("execv");
                        return 0;
                    }
;
                }
                else if (strcmp(commande, "setpin") == 0)
                {
                    if (execv("./setPin", NULL) == -1) {
                        perror("execv");
                        return 0;
                    }
                    ;
                }
            }
            else
            {
                wait(NULL);
                return 0;
            }
        }


    }
}
