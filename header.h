/* ALL REQUIRE HEADER FILE AND FUNCTION PROTOTYPES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* MACRO DEFINATION */

#define nSize 50
#define eSize 50

/* COLOUR MACRO */
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"

/* Global variable */
extern int loginFlag ;


/* Enum for success and failure */
typedef enum {
    SUCCESS,
    FAILURE
} Status;

/* STRUCTURE FOR DETAILS */

typedef struct uDetails
{
    char userName[50];
    char pNumber[11];
    char emailId[50];
}user;

/* STRUCTURE FOR LOGIN */
typedef struct Dlogin
{
    char userId[10];
    char upass[10];
}login;

/* FUNCTION PROTOTYPES */

Status addDetails();
Status searchDetails();
Status deleteDetails();
Status showDetails();
Status editDetails();
Status userLogin();
Status validateLogin();




