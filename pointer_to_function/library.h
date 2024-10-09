#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#define MAXLINES 5000
#define MAXLENGTH 1000
int readLines(char *lineptr[], int nlines);
int getlines(char *s, int lim);
int numcmp(const char *s1, const char *s2);
void qsort_v2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
#endif