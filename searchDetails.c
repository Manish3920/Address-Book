#include "header.h"

#define MAX_LINE_LENGTH 100

Status searchDetails() {
    FILE *fptr;
    char tempBuff[30];
    int flag = 0; // Flag to track if user is found
    char option;
    int soption;

    do {
        // Open the CSV file for reading
        fptr = fopen("details.csv", "r");
        if (fptr == NULL) {
            printf("[ERROR] Failed to open the file\n");
            return FAILURE;
        }

        system("clear");
        printf(YELLOW "_____________________________________________________________\n");
        printf(RED "\n                        Search Menu\n");
        printf(YELLOW "_____________________________________________________________\n\n" RESET);
        printf(" 1. Search Name\n");
        printf(" 2. Search Mobile no.\n");
        printf(" 3. Search Email id\n");
        printf(YELLOW "_____________________________________________________________\n\n" RESET);
        printf(GREEN " Please select the option: " RESET);
        scanf("%d", &soption);
        system("clear");

        switch (soption) {
            case 1:
                printf(GREEN " Please Enter the name: " RESET);
                scanf("%s", tempBuff);
                break;

            case 2:
                printf(GREEN " Please Enter the mobile no: " RESET);
                scanf("%s", tempBuff);
                break;

            case 3:
                printf(GREEN " Please Enter the email id: " RESET);
                scanf("%s", tempBuff);
                break;

            default:
                printf("[ERROR] Invalid option\n");
                fclose(fptr);
                return FAILURE;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), fptr)) {
            // Assuming CSV format: "#001 name number email"
            char *id = strtok(line, " ");
            char *name = strtok(NULL, " ");
            char *mobile = strtok(NULL, " ");
            char *email = strtok(NULL, "\n");

            if ((soption == 1 && strcmp(name, tempBuff) == 0) ||
                (soption == 2 && strcmp(mobile, tempBuff) == 0) ||
                (soption == 3 && strcmp(email, tempBuff) == 0)) {
                flag = 1;
                system("clear");
                printf(YELLOW "_____________________________________________________________\n");
                printf(RED "\n                        Contact Found\n");
                printf(YELLOW "_____________________________________________________________\n\n" RESET);
                printf(" User Name\t: \t\t%s\n", name);
                printf(" Mobile Number\t: \t\t%s\n", mobile);
                printf(" Email Id\t: \t\t%s\n" RESET, email);
                printf(YELLOW "-------------------------------------------------------------\n" RESET);
                break;
            }
        }

        if (!flag) {
            printf(RED "[ERROR] User detail not found\n" RESET);
        }

        // Close the file
        fclose(fptr);

        printf(GREEN "\n Do you want to continue(y/n): " RESET);
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    system("clear");

    return SUCCESS;
}
