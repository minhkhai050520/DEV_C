#include <stdio.h>
#include<string.h>

int strend(char *s, char *t);
int main(void)
{
    char *s = "Khai";
    char *t = "Khai";

    if(strend(s, t))
        printf("yes\n");
    else
        printf("No\n");

    return 0;
}

int strend(char *s, char *t)
{
    int length_of_s = strlen(s);
    int length_of_t = strlen(t);

    if(length_of_t > length_of_s)
        return 0;

    for(; length_of_t > 0; length_of_t--,length_of_s--)
        if(s[length_of_s - 1] != t[length_of_t -1])
            return 0;
    
    return 1;

}