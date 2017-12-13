#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <iostream>

#define Taille 10000

int main()
{
    int fd;
    char buffer[Taille];
    
    fd = open("/dev/ttyS0", O_RDONLY);
    
    if(fd == -1)
    {
        perror("Ouverture impossible");
        return (EXIT_FAILURE);
    }

    int i = 0;
    while(i < 200)
    {
        result = read(fd, buffer, sizeof(buffer) - 1);
        
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
            i++;
        }
        
        // data received
        if(result > 0)
        {
            buffer[result] = 0;
            printf("string : %s number : %d\n", buffer, result);
        }
    }
    close(fd1);
    close(fd2);
    return (EXIT_SUCCESS);
}




tcsetattr(fd, TCSANOW, &storedOptions);
