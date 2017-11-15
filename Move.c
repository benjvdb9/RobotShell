//
// Created by 13152 on 15-11-17.
//

#include <stdio.h>
#include <stdlib.h>

int main( )
{
    char sentence[1000];
    char num = 11;
    FILE *export;
    FILE *direction;
    FILE *value;

    export = fopen("/sys/class/gpio/export", "w");
    if (export == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fprintf(export,"%s", num);
    fclose(export);

    char *gpio_location = "/sys/class/gpio/gpio%f/";
    char *gpio_destination = sprintf(gpio_location, num);
    char *strncat(gpio_destination, "destination");

    direction = fopen(gpio_destination, "w");
    if (direction == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fprintf(direction,"%s", "out");
    fclose(direction);

    char *gpio_value = sprintf(gpio_location, num);
    char *strncat(gpio_value, "value");

    value = fopen(gpio_value, "w");
    if (value == NULL)
    {
        printf("Error!");
        exit(1);
    }

    fprintf(value,"%s", "out");
    fclose(value);
}
