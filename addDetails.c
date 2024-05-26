#include "header.h"

Status addDetails() {
    char option;
    FILE *fptr = NULL;
    char ntemp[30];
    char mtemp[11];
    char etemp[30];
    int id = 0;
    
    // Open the file in append mode
    fptr = fopen("details.csv", "a+");
    if (fptr == NULL) {
        printf("[ERROR] Failed to open the file\n");
        return FAILURE;
    }

    // Count the number of entries to determine the next available ID
    fseek(fptr, 0, SEEK_SET);
    while (!feof(fptr)) {
        char line[100];
        fgets(line, sizeof(line), fptr);
        id++;
    }
    id++; // Increment to get the next ID

    do {
        system("clear");
        printf(YELLOW"___________________________________\n");
        printf(RED"\n Enter the contact details"RESET);
        printf(YELLOW"\n___________________________________\n"RESET);

        // Prompt for name
        printf("\n Enter the name: ");
        scanf(" %[^\n]", ntemp);

        // Validate name
        int nameValid = 1;
        for (int i = 0; ntemp[i] != '\0'; i++) {
            if (!isalpha(ntemp[i])) {
                nameValid = 0;
                break;
            }
        }

        if (!nameValid) {
            printf(RED" [ERROR] The name format is invalid\n"RESET);
            fclose(fptr);
            printf(BLUE"\n Do you want to continue(y/n): "RESET);
            scanf(" %c", &option);
            if (option == 'y' || option == 'Y') {
                continue; // Restart the loop
            } else {
                break; // Exit the loop and function
            }
        }

        // Prompt for mobile number
        printf("\n Enter the mobile no: ");
        scanf(" %[^\n]", mtemp);

        // Validate mobile number
        int mobileValid = 1;
        if (strlen(mtemp) != 10) {
            mobileValid = 0;
        }
        for (int i = 0; mtemp[i] != '\0'; i++) {
            if (!isdigit(mtemp[i])) {
                mobileValid = 0;
                break;
            }
        }

        if (!mobileValid) {
            printf(RED" [ERROR] The mobile number format is invalid\n"RESET);
            fclose(fptr);
            printf(BLUE"\n Do you want to continue(y/n): "RESET);
            scanf(" %c", &option);
            if (option == 'y' || option == 'Y') {
                continue; // Restart the loop
            } else {
                break; // Exit the loop and function
            }
        }

        // Prompt for email id
        printf("\n Enter the email id: ");
        scanf(" %[^\n]", etemp);

        // Validate email id
        int emailValid = 1;
        if (strlen(etemp) <= 10 || strstr(etemp, "@gmail.com") == NULL) {
            emailValid = 0;
        }

        if (!emailValid) {
            printf(RED" [ERROR] The email id format is invalid\n"RESET);
            fclose(fptr);
            printf(BLUE"\n Do you want to continue(y/n): "RESET);
            scanf(" %c", &option);
            if (option == 'y' || option == 'Y') {
                continue; // Restart the loop
            } else {
                break; // Exit the loop and function
            }
        }

        // Format the data
        char entry[100];
        sprintf(entry, "#%03d %s %s %s", id, ntemp, mtemp, etemp);

        // Write the data to the file
        fprintf(fptr, "%s\n", entry);
        printf(GREEN"\n Record saved successfully....\n"RESET);

        printf(BLUE"\n Do you want to continue(y/n): "RESET);
        scanf(" %c", &option);
        id++; // Increment ID for the next entry
    } while (option == 'y' || option == 'Y');

    fclose(fptr); // Close the file
    system("clear");
    return SUCCESS;
}
