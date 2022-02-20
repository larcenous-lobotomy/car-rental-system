#include <stdlib.h>
#include <stdio.h>

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
int main()
{
    char pass[10],password[10]="codewithc";
    int i=0,main_exit;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            // go to menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
