#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

int lengthOfPassword(const char *s);
int isSpecialCharacters(const char *pw);
int main()
{
    char *str = "NguyenK hai";
    if(lengthOfPassword(str) && isSpecialCharacters(str))
        printf("Valid password\n");
    else
        printf("Password must have from 8 to 32 characters and not containing valid characters\n");
}

int lengthOfPassword(const char *s)
{
    int count;
    if((count = strlen(s)) < 8 || count > 32)
        return false;
    return true;
}

int isSpecialCharacters(const char *pw){
    char *invalidChacracters ="\'\"@#$^<>";
    for(; *pw != '\0'; pw++)
        if(isspace(*pw))
            return false;
        if(strchr(invalidChacracters, *pw))
            return false;
    return true;
}
