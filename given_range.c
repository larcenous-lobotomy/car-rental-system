#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void given_range()
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

    int u,l;

    int i, count = 0, flag = 0;
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
    for (;;)
    {
        fflush(stdin);
        // system("clear");
        printf("\nTo go back enter 0 0 in the input\nEnter the required base fare range in format <lower> <upper>: ");
        scanf("%d %d", &l,&u);

        if (l==0 && u==0)
            break;

        rewind(fp);
        printf("\nManufacturer Model Base Fare Kilometer Fare Seats Transmission Stock\n\n");
        for (i = 1; i <= count; i++)
        {
            fscanf(fp, "%s %s %d %d %d %s %d", temp.mfg, temp.model, &temp.base_fare, &temp.km_fare,
                &temp.seats, temp.trans, &temp.stock);
            if (temp.base_fare > l && temp.base_fare < u && temp.stock != 0)
            {
                printf("%s %s %d %d %d %s %d\n", temp.mfg, temp.model, temp.base_fare, temp.km_fare,
                    temp.seats, temp.trans, temp.stock);
                flag = 1;
            }
            else if (temp.base_fare > l && temp.base_fare < u && temp.stock == 0)
            {
                printf("%s %s %d %d %d %s (Out of stock)\n", temp.mfg, temp.model, temp.base_fare,
                    temp.km_fare, temp.seats, temp.trans);
                flag = 1;
            }
        }
    }
    fclose(fp);
}
