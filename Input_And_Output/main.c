#include<stdio.h>
#include <ctype.h>
#include <stdarg.h>
/*
int main()
{
    int c;
    while((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}
*/
void minprintf(char *fmt, ...);

int main(){
    int a = 5;
    int b = 7;
    double c = 5.5;
    char *my_string = "Nguyen Phan Minh Khai";
    minprintf("a = %d, c = %f, b = %d, string: %s\n", a, c, b, my_string);
    return 0;
}

void minprintf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);

    for(p = fmt; *p ; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p)
        {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; ++sval){
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        } // end switch
    } // end for loop
    va_end(ap);
}