#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

Status editDetails() {
    char option;
    char tempBuff[30];
    int found = 0;
    int soption;

    do {
        // Open files for reading and writing
        FILE *fptr = fopen("details.csv", "r");
        FILE *tfptr = fopen("temp.csv", "w");

        if (fptr == NULL || tfptr == NULL) {
            printf("[ERROR] Failed to open the file\n");
            return FAILURE;
        }

        system("clear");
        printf(YELLOW "_____________________________________________________________\n");
        printf(RED "\n                        Edit Menu\n");
        printf(YELLOW "_____________________________________________________________\n\n" RESET);
        printf(" 1. Name\n");
        printf(" 2. Mobile no.\n");
        printf(" 3. Email id\n");
        printf(YELLOW "_____________________________________________________________\n\n" RESET);
        printf(GREEN" Please select the option: "RESET);
        scanf("%d", &soption);
        system("clear");

        switch (soption) {
            case 1:
                printf(GREEN" Please Enter the name: "RESET);
                scanf("%s", tempBuff);
                break;

            case 2:
                printf(GREEN" Please Enter the mobile no: "RESET);
                scanf("%s", tempBuff);
                break;

            case 3:
                printf(GREEN" Please Enter the email id: "RESET);
                scanf("%s", tempBuff);
                break;

            default:
                printf("[ERROR] Invalid option");
                return FAILURE;
        }

        // Reset the flag
        found = 0;

        // Reset file pointer to beginning of file
        fseek(fptr, 0, SEEK_SET);

        // Display the saved contact
        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), fptr)) {
            char *id = strtok(line, " ");
            char *name = strtok(NULL, " ");
            char *mobile = strtok(NULL, " ");
            char *email = strtok(NULL, "\n");

            if ((soption == 1 && strcmp(name, tempBuff) == 0) ||
                (soption == 2 && strcmp(mobile, tempBuff) == 0) ||
                (soption == 3 && strcmp(email, tempBuff) == 0)) {
                found = 1;
                printf(YELLOW "_____________________________________________________________\n");
                printf(RED "\n                        EDIT CONSOLE\n");
                printf(YELLOW "_____________________________________________________________\n\n" RESET);
                printf(" User Name\t: \t\t%s\n", name);
                printf(" Mobile Number\t: \t\t%s\n", mobile);
                printf(" Email Id\t: \t\t%s\n" RESET, email);
                printf(YELLOW "-------------------------------------------------------------\n" RESET);

                printf("\n 1. Edit Name\n");
                printf(" 2. Edit Mobile Number\n");
                printf(" 3. Edit Email Id\n");
                printf(YELLOW "-------------------------------------------------------------\n" RESET);
                printf(GREEN "\n > Enter your choice: " RESET);
                scanf(" %c", &option);

                switch (option) {
                    case '1':
                        printf(YELLOW "   Enter the new name: " RESET);
                        scanf(" %[^\n]", name);
                        break;
                    case '2':
                        printf(YELLOW "   Enter the new mobile number: " RESET);
                        scanf("%s", mobile);
                        break;
                    case '3':
                        printf(YELLOW "   Enter the new email id: " RESET);
                        scanf(" %[^\n]", email);
                        break;
                    default:
                        printf(YELLOW "   Invalid choice\n");
                        break;
                }
                fprintf(tfptr, "%s %s %s %s\n", id, name, mobile, email);
            } else {
                fprintf(tfptr, "%s %s %s %s\n", id, name, mobile, email);
            }
        }

        // Close files
        fclose(fptr);
        fclose(tfptr);

        // Delete the original file
        remove("details.csv");

        // Rename the temp file to original file
        rename("temp.csv", "details.csv");

        if (!found) {
            printf(" User not found. Do you want to try again (y/n): ");
            scanf(" %c", &option);
            system("clear");
        } else {
            printf(GREEN "   Do you want to continue editing (y/n): " RESET);
            scanf(" %c", &option);
            system("clear");
        }
    } while (option == 'y' || option == 'Y');

    return SUCCESS;
}
