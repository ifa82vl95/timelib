/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/

int is_leapyear(year){
    int isTrue = 0;
    if(year%4 == 0){
        if(year%100 == 0){
            if(year%100 == 0){
                isTrue = 1;
            }
            else{
                isTrue = 0;
            }
        }
        else{
            isTrue = 1;
        }
    }
    else{
        isTrue = 0;
    }
    return isTrue;
}

int day_of_the_year(int day, int month, int year)
{
    int dayOfTheYear = 0;

    static const int days[2][13] = {
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };

    int leap = is_leapyear(year);

    dayOfTheYear = days[leap][month] + day;

    return dayOfTheYear;
}

int get_days_for_month(int month, int year){
    int daysNumberOfMonth = 0;
    if (month < 1 || month > 12){
        return -1;
    }

    int days[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (is_leapyear(year) == 1){
        days[2] = 29;
    }

    return days[month];
}

int exists_date(int day, int month, int year){
    if (year < 1582 || year > 2400 || month < 1 || month > 12 || day < 1 || day > 31){
        return 0;
    }
    if (is_leapyear(year) == 1 && month == 2 && day > 29){
            return 0;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11 && day > 30){
        return 0;
    }
    else {
        return 1;
    }
}

int input_date(){

}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(28, 03, 2018));
    return 0;
}
