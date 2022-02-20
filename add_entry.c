#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_entry()
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
    } list;

    system("clear");
    FILE* fp;
    fp = fopen("car_rental.txt", "a");

    for (;;)
    {
        fflush(stdin);
        printf("\nTo exit enter Q/q in the input\nManufacturer: ");
        scanf("%s", list.mfg);

        if (strcmp(list.mfg, "Q") == 0 || strcmp(list.mfg, "q") == 0)
	{
		fclose(fp);            
		break;
	}
        fflush(stdin);
        printf("Model: ");
        scanf("%s", list.model);
        fflush(stdin);
        printf("Base fare: ");
        scanf("%d", &list.base_fare);
        fflush(stdin);
        printf("Kilometer fare: ");
        scanf("%d", &list.km_fare);
        fflush(stdin);
        printf("Seats: ");
        scanf("%d", &list.seats);
        fflush(stdin);
        printf("Transmission: ");
        scanf("%s", list.trans);
        printf("Stock: ");
        scanf("%d", &list.stock);

        fprintf(fp, "%s %s %d %d %d %s %d\n", list.mfg, list.model, list.base_fare, list.km_fare,
            list.seats, list.trans, list.stock);
    }
    //fseek(fp,0,SEEK_END);
    fclose(fp);
}
