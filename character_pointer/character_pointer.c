#include <stdio.h>
#include <string.h>
void my_strcpy1(char *s, char *t);
void my_strcpy2(char *s, char *t);
void my_strcpy3(char *s, char *t);
int my_strcmp_v1(char *s, char *t);
int my_strcmp_v2(char *s, char *t);
int main()
{
    // int count;
    // char amessage[] = "Now is the time";
    // count = strlen(amessage);
    // amessage[count -1] = 'E';
    // printf("amessage: %s\n", amessage);
    char str1[20] = "this is string 1";
    char str2[20];
    char *str3 = "this is string 3";
    my_strcpy3(str2, str1);
    printf("str2: %s\n", str2);
    printf("String comparation: %d\n", my_strcmp_v2(str1, str3));
    return 0;
}

void my_strcpy1(char *s, char *t)
{
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

void my_strcpy2(char *s, char *t)
{
    while((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

void my_strcpy3(char *s, char *t)
{
    while((*s++ = *t++))
        ;
}

int my_strcmp_v1(char *s, char* t)
{
    int i;
    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int my_strcmp_v2(char *s, char *t)
{
    int i;
    for(i = 0; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;
    return *s - *t;

}