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

        char commandes[3][50] = {"go", "gps", ""};
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
                if (strcmp(commande,"go") == 0)
                {
                    if (execv("./go", NULL) == -1)
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
            }
            else
            {
                wait(NULL);
                return 0;
            }
        }


    }
}
