#include <stdio.h>
#define MAXLEN 100

int getline(char *line, int maxline);

int main(){
    // double sum, v;

    // sum = 0;
    // while(scanf("%lf", &v) == 1){
    //     printf("\t%.2f\n", sum += v);
    // }
    // return 0;

    // int day, year;
    // char monthname[20];
    // scanf("%d %s %d", &day,monthname,&year);
    // printf("%d %s %d", day, monthname, year);
    // return 0;
    
    char line[MAXLEN];
    int day, month, year;
    char monthname[20];


    while(getline(line, MAXLEN) > 0){
        if(sscanf(line, "%d %d %d", &day, &month, &year) == 3)
            printf("valid: %s\n", line);
        else if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line);
        else
            printf("invalid\n");
    }
}


int getline(char *line,int maxline){
    int c, i;
    // while((c = getchar()) != EOF && c != '\n'){
    //     if(i < MAXLEN)
    //         line[i++] = c;
    // }

    for(i = 0; i < MAXLEN && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }

    if(c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}