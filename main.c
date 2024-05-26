#include "header.h"
int main()
{
    int lchoice;
	system("clear");
   
    while (lchoice != 3)
    {
		printf(YELLOW"___________________________________\n\n");
        printf(RED"\t  LOGIN PAGE \n");
        printf(YELLOW"___________________________________\n"RESET);
        printf("\n 1. Register");
        printf("\n 2. Login");
        printf("\n 3. Exit");
        printf(YELLOW"\n___________________________________\n"RESET);
        printf(BLUE"\n Enter the choice: "RESET);
        scanf("%d", &lchoice);

        switch (lchoice)
        {
        case 1:
            if (userLogin() != SUCCESS)
            printf(" [ERROR] Failed to register\n");
			system("clear");
            break;
        case 2:
            if (validateLogin() == SUCCESS) {
				system("clear");
                printf(GREEN"\n Login Successful!\n\n"RESET);
                int choice;

                // Display the contact menu
                while (choice != 6)
                {
                    printf(YELLOW"___________________________________\n\n");
                    printf(RED"\t  ADDRESS BOOK\n");
                    printf(YELLOW"___________________________________\n"RESET);
                    printf("\n 1. Add Contact");
                    printf("\n 2. Show Contact");
                    printf("\n 3. Search Contact");
                    printf("\n 4. Delete Contact");
                    printf("\n 5. Edit Contact");
                    printf("\n 6. Exit");
                    printf(YELLOW"\n___________________________________\n"RESET);
                    printf(BLUE"\n Enter the choice: "RESET);
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        if (addDetails() != SUCCESS)
                            system("clear");
                        printf(RED" [ERROR] Failed to add details\n"RESET);
                        break;

                    case 2:
                        if (showDetails() != SUCCESS)
                            printf(RED" [ERROR] Failed to display details\n");
                        break;

                    case 3:
                        if (searchDetails() != SUCCESS)
                            printf(RED" [ERROR] Failed to search details\n");
                        break;

                    case 4:
                        system("clear");
                        if (deleteDetails() != SUCCESS)
                            printf(RED" [ERROR] Failed to delete details\n");
                        break;

                    case 5:
                        system("clear");
                        if (editDetails() != SUCCESS)
                            printf(RED" [ERROR] Failed to edit details\n");
                        break;

                    case 6:
                        system("clear");
                        printf("Thank you!!\n");
                        break;

                    }
                }
            } 
			else 
			{
                printf(RED"\n [ERROR] Enter valid ID & PASSWORD\n"RESET);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf(RED"\n [ERROR] Invalid choice\n"RESET);
            break;
        }
    }
    return 0;
}
