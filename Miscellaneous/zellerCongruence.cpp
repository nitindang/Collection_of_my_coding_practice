/**
 * An implementation to use Zeller's congruence calculate the day of the week for any Julian or Gregorian calendar date
 * if the date is given. The function will not check if the given date is valid.
 */

#include <bits/stdc++.h>

std::string ZellerCongruence(int year, int month, int day) {

    std::string result;

    bool flag = false;
    if (year <= 1581 || (year == 1582 && month <= 9) || (year == 1582 && month == 10 && month <= 4))
        flag = true;

    if (month == 1 || month == 2) {
        --year;
        month += 12;
    }
    int c = year / 100;
    int y = year - c * 100;
    int week = 0;

    if (!flag) {
        week = c / 4 - 2 * c + y + y / 4 + 13 * (month + 1) / 5 + day - 1;
        while (week < 0)
            week += 7;
        week %= 7;
    } else {
        week = y + y / 4 + c / 4 - 2 * c + 13 * (month + 1) / 5 + day + 2;
        while (week < 0)
            week += 7;
        week %= 7;
    }

    switch (week) {
        case 1:
            // printf("Monday\n");
            result = "Monday";
            break;
        case 2:
            // printf("Tuesday\n");
            result = "Tuesday";
            break;
        case 3:
            // printf("Wednesday\n");
            result = "Wednesday";
            break;
        case 4:
            // printf("Thursday\n");
            result = "Thursday";
            break;
        case 5:
            // printf("Friday\n");
            result = "Friday";
            break;
        case 6:
            // printf("Saturday\n");
            result = "Saturday";
            break;
        default:
            // printf("Sunday\n");
            result = "Sunday";
            break;
    }
    return result;
}

int main() {
    assert(ZellerCongruence(2019, 8, 16) == "Friday");
    assert(ZellerCongruence(2019, 8, 17) == "Saturday");
    assert(ZellerCongruence(2019, 8, 15) == "Thursday");
    assert(ZellerCongruence(2019, 8, 14) != "Thursday");
    return 0;
}
