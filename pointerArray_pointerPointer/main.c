#include <stdio.h>
#include "my_lib.h"
int main()
{
    char myName[100];
    getline(myName, 100);
    printf("ok\n");
    printf("My name: %s\n",myName);
    return 0;
}