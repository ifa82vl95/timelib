#include <stdlib.h>
#include <stdio.h>
#include "bibliothek.h"

//viktor Lai
//get number of day with date as parameter

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(7, 2, 2018));
    printf("Tage des Monats: %i\n", get_days_for_month(5, 2013));
    int day, month, year;
    input_date(&day, &month, &year);
    return 0;
}
