#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/*day_of_year: set day of year from month & day*/
int day_of_year(int year, int month, int day)
{
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(int i = 1; i < month; ++i)
        day += daytab[leap][i];
    return day;
}

/*month_day: set month and day from day of year*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap, i;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i = 1; yearday > daytab[leap][i]; ++i)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
int main(void)
{
    int dayOfYear;
    int month;
    int day;
    printf("convert 15/2/2024 to day of year\n");
    printf("%d\n", dayOfYear = day_of_year(2024, 2, 15));


    printf("Convert 46th, 2024 to month and day\n");
    month_day(2024, dayOfYear, &month, &day);
    printf("month: %d, day: %d\n",month, day);
    return 0;
}