#include "header.h"

#define MAX_LINE_LENGTH 100

Status showDetails() {
    FILE *fptr = NULL;
    char line[MAX_LINE_LENGTH];
    char option;

    do {
        fptr = fopen("details.csv", "r");
        if (fptr == NULL) {
            printf("[ERROR] Failed to open the file\n");
            return FAILURE;
        } else {
            system("clear");
            printf(YELLOW"_____________________________________________________________\n");
            printf(RED"\n                        ADDRESS BOOK\n");
            printf(YELLOW"_____________________________________________________________\n\n"RESET);
        }

        int isEmpty = 1;
        while (fgets(line, sizeof(line), fptr)) {
            isEmpty = 0;
            // Split the line into ID, name, mobile number, and email
            char *token = strtok(line, " ");
            if (token != NULL) {
                printf(" ID\t\t: \t\t%s\n", token);
                token = strtok(NULL, " ");
            }
            if (token != NULL) {
                printf(" User Name\t: \t\t%s\n", token);
                token = strtok(NULL, " ");
            }
            if (token != NULL) {
                printf(" Mobile Number\t: \t\t%s\n", token);
                token = strtok(NULL, " ");
            }
            if (token != NULL) {
                printf(" Email Id\t: \t\t%s\n"RESET, token);
            }
            printf(YELLOW"-------------------------------------------------------------\n"RESET);
        }

        if (isEmpty) {
            printf(RED" The address book is empty\n\n"RESET);
        }

        fclose(fptr);
        printf(GREEN" Do you want to continue(y/n): "RESET);
        scanf(" %c", &option);
    } while (option == 'y' || option == 'Y');

    system("clear");
    return SUCCESS;
}
