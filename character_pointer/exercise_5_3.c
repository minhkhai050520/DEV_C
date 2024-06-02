#include <stdio.h>
void my_strcat_v1(char *s, char *t);
int main()
{
    char str1[] = "Nguyen ";
    char str2[] = "Khai";
    my_strcat_v1(str1, str2);
    printf("str1: %s\n", str1);
    return 0;
}

void my_strcat_v1( char *s, char *t)
{
    while(*s != '\0')
        s++;
    while((*s++ = *t++) != '\0')
        ;
}