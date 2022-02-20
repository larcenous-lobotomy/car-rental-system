#include <stdlib.h>
// will have to drop this
#include <stdio.h>
// relogin
int main()
{
    char curr_pass[10],password[10]="codewithc", new_pass[10];
	int i;
    enter : printf("\n\n\t\tEnter the current password:");
    scanf("%s",curr_pass);
    
	if (strcmp(curr_pass,password)!=0)
	{
		printf("You have two more tries left.");
		
	}
    else
    {
    printf("\n\n\t\tEnter the new password:");
    scanf("%s",new_pass);
    for (i=0;new_pass[i]!='\0';i++)
    {
    	password[i] = new_pass[i];
	}
    password[i]='\0';
    // go back to main menu
	}
	
    return 0;
}
