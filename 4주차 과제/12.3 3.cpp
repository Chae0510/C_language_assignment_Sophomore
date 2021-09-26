#include <stdio.h>

struct Date {
    int month;
    int day;
    int year;
};


void Days(Date& date) {
    int P_days;

    P_days = (date.year - 2000) * 360 + (date.month - 1) * 30 + date.day - 1;

    printf("2000/01/01 ~ %4d.%2d.%2d => the number of days: %d days\n", date.year, date.month, date.day, P_days);
}

int main() {
    Date d[] = {
        {05,10,2001},
        {8,29,1999},
        {07,18,1972},
        {05,03,1966},
        {03,24,2021}
    };

    for (int i = 0; i < 5; i++) {
        Days(d[i]);
    }


    return 0;

}
