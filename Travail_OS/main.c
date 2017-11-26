#include <stdio.h>
#include <unistd.h>
#include <rpcndr.h>
#include <sys/types.h>

pid_t fork(void);
void wait(int*);

int main()
{
    while (1)
    {

        char* commandes[3] = {"go", "gps", ""};
        char commande[50];
        int i;
        boolean commandExist = 0;
        printf(">");
        scanf("%s",commande);

        for (i = 0 ; i < 3 ; i++)
        {
            if (commande == commandes[i])
            {
                commandExist = 1;
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
                if (commande == "go")
                {
                    execlp("/bin/go","go","", NULL);
                }
                else if (commande == "gps")
                {
                    execlp("/bin/gps", "gps", "", NULL);
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
