#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool saveToFile(char* pin_list[4]);

int main()
{
    char* pin;
    char* pin_list[4];

    printf("Set pin for upper-left wheel");
    scanf("%s", pin);
    pin_list[0] = pin;

    printf("Set pin for lower-left wheel");
    scanf("%s", pin);
    pin_list[1] = pin;

    printf("Set pin for upper-right wheel");
    scanf("%s", pin);
    pin_list[2] = pin;

    printf("Set pin for lower-right wheel");
    scanf("%s", pin);
    pin_list[3] = pin;

    saveToFile(pin_list);
}

//Create a file containing the pin info
bool saveToFile(char* pin_list[4])
{
    /*char pin_list[4];
    pin_list[0] = PLU;
    pin_list[1] = PLD;
    pin_list[2] = PRU;
    pin_list[3] = PRD;*/

    FILE* fp;
    fp = fopen("PinData.txt", "w");
    int i;

    for(i = 0; i < 4; i++){
        fprintf(fp, strcat(pin_list[i], "\n"), 1);
    }

    fclose(fp);
}
