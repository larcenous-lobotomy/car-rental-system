#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void billing()
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

    char model[10];
    int km;
    int i, count = 0, flag = 0, bill = 0;
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
        //fflush(stdin);
        // system("clear");
        printf("\nTo go back enter Q/q in the input\nEnter the car model: ");
        scanf("%s", model); // should tell then and there that model not found

        if (strcmp(model, "Q") == 0 || strcmp(model, "q") == 0)
            break;

        printf("Enter the kilometers used: ");
        scanf("%d", &km);
        rewind(fp);

        for (i = 1; i <= count; i++)
        {
            fscanf(fp, "%s %s %d %d %d %s %d", temp.mfg, temp.model, &temp.base_fare, &temp.km_fare,
                &temp.seats, temp.trans, &temp.stock);
            if (strcmp(temp.model, model) == 0)
            {
                bill = temp.base_fare + km * temp.km_fare;
                printf("\nCar : %s %s\n", temp.mfg, temp.model);
		printf("Base fare = %d\n", temp.base_fare);
		printf("Kilometer fare = %d\n", temp.km_fare);
		printf("Bill amount = %d\n", bill);	
                flag = 1;
            }
        }
        if (flag == 0)
            printf("Model not found, try again...\n");
        fclose(fp);
    }
}
