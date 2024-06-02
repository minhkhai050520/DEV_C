#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define true 1
#define false 0

int isValidPassword(const char *s);
int main()
{
    char *myPassword = "nguyenphanLminhkha123123123$%";
    if(isValidPassword(myPassword))
        printf("Valid Password\n");
    else
        printf("Invalid password\n");
    return 0;
}

int isValidPassword(const char *pw)
{
    char *validChar ="$#-+";
    char *invalidChacracters ="\'\"@^<>*";
    int hasUpper = false;
    int hasLower = false;
    int hasDigit = false;
    int hasSpecial = false;
    int count = 0;

    // Check for the length of the Password
    if((count = strlen(pw)) < 8 || count > 32)
        return false;
    // Check for the requirements for the password
    for(; *pw != '\0'; pw++)
        if(isspace(*pw)) // Check for whitespace
            return false;
        else if(strchr(invalidChacracters, *pw)) // Check for invalid password
            return false;
        else if(isupper(*pw)) // Check for capital characters
            hasUpper = true;
        else if(islower(*pw)) // Check for lowercase characters
            hasLower = true;
        else if(isdigit(*pw)) // check for digits
            hasDigit = true;
        else if(strchr(validChar, *pw)) // check for valid characters
            hasSpecial = true;
    return hasDigit && hasLower && hasUpper && hasSpecial;
}