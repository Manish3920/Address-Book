#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

Status deleteDetails() {
    char valueToDelete[30]; // Variable to store the value to delete
    char line[MAX_LINE_LENGTH];
    int match = 0; 
    char option;
    int soption;

    do {
        system("clear");
        printf(YELLOW "_____________________________________________________________\n");
        printf(RED "\n                        Edit Menu\n");
        printf(YELLOW "_____________________________________________________________\n\n" RESET);
        printf(" 1. Name \n");
        printf(" 2. Mobile no.\n");
        printf(" 3. Email id\n");
        printf(YELLOW "_____________________________________________________________\n\n" RESET);
        printf(GREEN" Please select the option: "RESET);
        scanf("%d", &soption);
        system("clear");

        switch (soption) {
            case 1:
                printf(GREEN" Please Enter the name: "RESET);
                scanf("%s", valueToDelete);
                break;

            case 2:
                printf(GREEN" Please Enter the mobile no: "RESET);
                scanf("%s", valueToDelete);
                break;

            case 3:
                printf(GREEN" Please Enter the email id: "RESET);
                scanf("%s", valueToDelete);
                break;

            default:
                printf("[ERROR] Invalid option");
                break;
        }

        FILE *fptr = fopen("details.csv", "r");
        FILE *tfptr = fopen("temp.csv", "w");

        if (fptr == NULL || tfptr == NULL) {
            printf("[ERROR] Failed to open file\n");
            return FAILURE;
        }

        // Loop through each line in the original file
        while (fgets(line, sizeof(line), fptr)) {
            char *id = strtok(line, " ");
            char *name = strtok(NULL, " ");
            char *mobile = strtok(NULL, " ");
            char *email = strtok(NULL, "\n");

            // Check if the current line matches the criteria for deletion
            if ((soption == 1 && strcmp(name, valueToDelete) == 0) ||
                (soption == 2 && strcmp(mobile, valueToDelete) == 0) ||
                (soption == 3 && strcmp(email, valueToDelete) == 0)) {
                match = 1;
            } else {
                fprintf(tfptr, "%s %s %s %s\n", id, name, mobile, email);
            }
        }

        // Close files
        fclose(fptr);
        fclose(tfptr);

        // Delete the original file
        remove("details.csv");
        // Rename the temporary file
        rename("temp.csv", "details.csv");

        if (match) {
            printf(YELLOW"\n Record with value '%s' deleted successfully.\n"RESET, valueToDelete);
        } else {
            printf(RED"\n Record with value '%s' not found.\n"RESET, valueToDelete);
            return FAILURE;
        }

        printf("_______________________________________________________\n");
        printf(GREEN"\n Do you want to continue(y/n): "RESET);
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    system("clear");
    return SUCCESS;
}
