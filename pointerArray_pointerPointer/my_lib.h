#ifndef MY_LIB_H
#define MY_LIB_H
#define MAXLINE 5000
int getline(char *s, int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
#endif