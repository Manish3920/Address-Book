#include "header.h"

Status validateLogin() {
    char idtemp[15];
    char ptemp[15];
    int idMatch = 0;
    int passMatch = 0;

    printf(" Enter the user id: ");
    scanf("%s", idtemp);
    printf(" Enter the password: ");
    scanf("%s", ptemp);

    FILE *ifptr = fopen("userdetail.txt", "r");

    if (ifptr == NULL) {
        printf(RED" [ERROR] Failed to open the file.\n"RESET);
        return FAILURE;
    }

    char userIdFromFile[15];
    char passwordFromFile[15];

    // Read each line from the file
    while (fscanf(ifptr, "%s %s", userIdFromFile, passwordFromFile) != EOF) {
        if (strcmp(userIdFromFile, idtemp) == 0) {
            idMatch = 1;
            if (strcmp(passwordFromFile, ptemp) == 0) {
                passMatch = 1;
                break; 
            }
        }
    }

    fclose(ifptr);

    if (idMatch == 0 )
    {
        printf(RED" [ERROR] Please enter valid id\n"RESET);
        system("clear");
        return FAILURE;
    }
    if(passMatch == 0)
    {
         printf(RED" [ERROR] Please enter valid id\n"RESET);
         system("clear");
         return FAILURE;
    }

}
