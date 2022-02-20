#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_all()
{
    system("clear");
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

    int i, count = 0;
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
    printf("\nManufacturer Model Base Fare Kilometer Fare Seats Transmission Stock\n\n");
    for (i = 1; i <= count; i++)
    {
        fscanf(fp, "%s %s %d %d %d %s %d", temp.mfg, temp.model, &temp.base_fare, &temp.km_fare,
            &temp.seats, temp.trans, &temp.stock);
        if (temp.stock != 0)
            printf("%s %s %d %d %d %s %d\n", temp.mfg, temp.model, temp.base_fare, temp.km_fare,
                temp.seats, temp.trans, temp.stock);
    }

    rewind(fp);

    printf("\nThe following are currently out of stock\n");
    printf("Manufacturer  Model  Base Fare  Kilometer Fare  Seats  Transmission\n\n");
    for (i = 1; i <= count; i++)
    {
        fscanf(fp, "%s %s %d %d %d %s %d", temp.mfg, temp.model, &temp.base_fare, &temp.km_fare,
            &temp.seats, temp.trans, &temp.stock);
        if (temp.stock == 0)
            printf("%s %s %d %d %d %s\n", temp.mfg, temp.model, temp.base_fare, temp.km_fare,
                temp.seats, temp.trans);
    }


    fclose(fp);
}
