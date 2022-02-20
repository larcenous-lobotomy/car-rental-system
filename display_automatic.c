#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_automatic()
{

    struct car
    {
        char mfg[10];
        char model[10];
        int base_fare;
        int km_fare;
        int seats;
        char trans[9];
        int stock;
    } temp;

    int i, count = 0, flag=0;
    char ch;
    FILE* fp;
    fp = fopen("car_rental.txt", "r");

    while (1) // counting number of entries
    {
        ch = fgetc(fp);
        if (ch == '\n')
        {
            count++;
        }
        if (ch == EOF)
            break;
    }

    rewind(fp);
    system("clear");
    printf("\nManufacturer Model Base Fare Kilometer Fare Seats Stock\n\n");
    for (i = 1; i <= count; i++)
    {
        fscanf(fp, "%s %s %d %d %d %s %d", temp.mfg, temp.model, &temp.base_fare, &temp.km_fare,
            &temp.seats, temp.trans, &temp.stock);
        if (strcmp(temp.trans, "Auto") == 0 && temp.stock != 0)
        {
            printf("%s %s %d %d %d %d\n", temp.mfg, temp.model, temp.base_fare, temp.km_fare,
                temp.seats, temp.stock);
            flag = 1;
        }
        else if (strcmp(temp.trans, "Auto") == 0 && temp.stock == 0)
        {
            printf("%s %s %d %d %d (Out of stock)\n", temp.mfg, temp.model, temp.base_fare,
                temp.km_fare, temp.seats);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("No automatic cars available right now\n");
    fclose(fp);
}
