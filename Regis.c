#include "header.h"

Status userLogin()
{
    login uLogin;
    FILE *ifptr = fopen("userdetail.txt","w");

    if(ifptr == NULL)
    {
        printf(RED" [ERROR] Faild to open the file.\n"RESET);
        return FAILURE;
    }

    printf(" Enter the Unique Id: ");
    scanf(" %[^\n]",uLogin.userId);
    printf(" Set the password: ");
    scanf(" %[^\n]",uLogin.upass);

    fprintf(ifptr, "%s %s\n", uLogin.userId, uLogin.upass);
    fclose(ifptr);


    printf(GREEN" [SUCCESS] Registration successfull\n"RESET);
    return SUCCESS;
}