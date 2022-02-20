#include <stdio.h>
#include <stdlib.h>
#include "display_all.h"
#include "least_base_fare.h"
#include "most_base_fare.h"
#include "display_automatic.h"
#include "given_capacity.h"
#include "given_range.h"
#include "given_kmfare.h"
#include "same_mfg.h"
#include "change_stock.h"
#include "add_entry.h"
#include "remove_entry.h"
#include "billing.h"

int main()
{
    int ch;
main: // goto label
    system("clear");
    printf("\n\t\t**** Welcome to Car Rental System ****\n\n");
    printf("1. Display all the cars\n");
    printf("2. Display car(s) with least base fare\n");
    printf("3. Display car(s) with most base fare\n");
    printf("4. Display all automatic cars\n");
    printf("5. Display cars with a given seating capacity\n");
    printf("6. Display all cars within a given base fare range\n");
    printf("7. Display cars of same manufacturers\n");
    printf("8. Display all cars with a given kilometer fare\n");
    printf("9. Add and remove stock\n");
    printf("10.Add entry\n");
    //printf("11.Remove entry\n");
    printf("11.Generate bill\n");
    printf("0. Exit\n\n"); 
    printf("Enter the choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 0:
            printf("\n\n\t\tAre you sure you want to exit?");
            break;

        case 1:
            display_all();
            break;

        case 2:
            least_base_fare();
            break;

        case 3:
            most_base_fare();
            break;

	case 4:
            display_automatic();
            break;

        case 5:
            given_capacity();
            break;

        case 6:
            given_range();
            break;

        case 7:
            same_mfg();
            break;

        case 8:
            given_kmfare();
            break;

        case 9:
            change_stock();
            break;

        case 10:
            add_entry();
            break;

        //case 11:
            //remove_entry();
            //break;

        case 11:
            billing();
            break;

        default:
            system("clear");
            printf("Invalid choice, try again...");
            goto main;
    }

retry:
    printf("\n\n[1] Main Menu\t\t[0] Exit\n");
    printf("Enter the  choice: ");
    scanf("%d", &ch);

    switch (ch)
    {

        case 1:
            goto main;

        case 0:
            system("clear");
	    break;

        default:
	printf("\nInvalid choice, try again...\n");            
	goto retry; // if user enters number other than 0 or 1; user should enter numbers only as our switch is number based
    }

    return 0;
}
