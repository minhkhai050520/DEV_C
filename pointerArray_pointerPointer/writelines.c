#include <stdio.h>
#include "my_lib.h"

/*write output lines ver1*/
// void writelines(char *lineptr[], int nlines)
// {
//     int i;
//     for(i = 0; i < nlines ; ++i)
//         printf("%s\n", lineptr[i]);
// }

/*write output lines ver2*/
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}