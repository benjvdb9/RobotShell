#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include<fcntl.h>
#include <stdbool.h>

#define Taille 10000

int main()
{
    int fd;
    char buffer[Taille];
    ssize_t result;
    printf("test");
    fflush(stdout);

    fd = open("/dev/ttyS0", O_RDONLY);
    
    if(fd == -1)
    {
        perror("Ouverture impossible");
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
        }
        
        // data received
        if(result > 0)
        {
            buffer[result] = 0;
            printf("string : %s number : %d\n", buffer, result);
        }
    }
    close(fd);
    return (EXIT_SUCCESS);
}

