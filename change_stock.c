#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change_stock()
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
	system("clear");
	char model[10];
	int i,count=0, new_stock,flag=0;
	FILE* fp;
	FILE* ft;
	char ch;
	fp=fopen("car_rental.txt","r");
	ft=fopen("temp.txt","w");


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
    for (;;)
    {
        fflush(stdin);
        printf("\nTo exit enter Q/q in the input\n");
        printf("Enter the model of car to modify stock: ");
        scanf("%s",model);

	if (strcmp(model,"q") == 0 || strcmp(model,"Q")==0)
	{
	return;
	}

	printf("Enter the new stock: ");
	scanf("%d",&new_stock);


	for(i=1;i<=count;i++)
	{
		fscanf(fp,"%s %s %d %d %d %s %d",temp.mfg,temp.model,&temp.base_fare,&temp.km_fare,&temp.seats,temp.trans,&temp.stock);
		if (strcmp(temp.model,model)==0)
			{fprintf(ft,"%s %s %d %d %d %s %d\n",temp.mfg,temp.model,temp.base_fare,
				            temp.km_fare,temp.seats,temp.trans,new_stock); flag=1;}

		else
			fprintf(ft,"%s %s %d %d %d %s %d\n",temp.mfg,temp.model,temp.base_fare,
				            temp.km_fare,temp.seats,temp.trans,temp.stock);
	}

	if (flag==0)
		printf("\nNo match found for the given car in our database");
	fclose(fp);
	fclose(ft);
	remove("car_rental.txt");
	rename("temp.txt","car_rental.txt");
    }
}
