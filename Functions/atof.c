#include<stdio.h>
#include <ctype.h>

#define MAXLINE 100

double my_atof(const char *s);
int getline(char *line, int max);

int main()
{
    double sum;
    char line[MAXLINE];

    while(getline(line, MAXLINE) > 0)
    {
        sum  += my_atof(line);
        printf("\t%g\n", sum);
    }
    return 0;
}

double my_atof(const char *s){
    int sign;
    double val;
    int power;

    for(; isspace(*s); ++s)
        ;
    
    sign = (*s == '-')? -1 : 1;

    for(val = 0.0; isdigit(*s); ++s)
        val = val*10 + (*s - '0');

    if(*s == '.')
        ++s;
    
    for(power = 1 ;isdigit(*s); ++s)
    {
        val = val*10 + (*s -'0');
        power *= 10;
    }

    return sign * val / power;
}

int getline(char *line, int max)
{
    char c;
    int i = 0;

    while(--max > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *line++ = c;
        ++i;
    }

    if(c == '\n')
    {
        *line++ = c;
        ++i;
    }

    *line = '\0';
    return i;
}