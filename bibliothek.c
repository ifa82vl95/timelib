#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"


//Viktor Lai
//get number of day with date as parameter
//implementation of functions
//check if year is a leapyear (parameter year)
int is_leapyear(int year){
    int is_true = 0;
    if(year%4 == 0)
    {
        if(year%100 == 0)
        {
            if(year%400 == 0)
            {
                is_true = 1;
            }
            else
            {
                is_true = 0;
            }
        }
        else
        {
            is_true = 1;
        }
    }
    else
    {
        is_true = 0;
    }
    return is_true;
}

//get number of the day of the year (parameter: day, month and year)
int day_of_the_year(int day, int month, int year)
{
    int day_number = 0;

    int exist_date = exists_date(day, month, year);

    if (exist_date == 0)
    {
        return -1;
    }

    static const int days[2][13] =
    {
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };

    int leap = is_leapyear(year);

    day_number = days[leap][month] + day;

    return day_number;
}

//get the numbers of days of a month(parameter month and year)
int get_days_for_month(int month, int year)
{
    if (month < 1 || month > 12)
    {
        return -1;
    }

    int days[13] =
    {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (is_leapyear(year) == 1)
    {
        days[2] = 29;
    }

    return days[month];
}

//check if the date is valid (parameter day, month, year)
//a date is valid if its between 01.01.1582 and 31.12.2400
int exists_date(int day, int month, int year)
{
    if (year < 1582 || year > 2400 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return 0;
    }
    if (is_leapyear(year) == 1 && month == 2 && day > 29)
    {
        return 0;
    }
    if (is_leapyear(year) == 0 && month == 2 && day > 28)
    {
        return 0;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return 0;
    }
    return 1;
}

//check if input date is valid if not repeat until it is valid
int input_date(int *day, int *month, int *year)
{
    int exist_date = 0;
    do{
        printf("Gueltiges Datum angeben \n");
        printf("Tag angeben \n");
        scanf("%d", day);
        printf("Monat angeben \n");
        scanf("%d", month);
        printf("Jahr angeben \n");
        scanf("%d", year);
        exist_date = exists_date(*day, *month, *year);
    }while (exist_date == 0);

    printf("Datum ist gueltig \n");
    return 0;
}
