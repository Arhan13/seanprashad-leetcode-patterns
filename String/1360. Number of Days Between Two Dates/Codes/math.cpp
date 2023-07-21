#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int numOfDaysInANonLeapYear = 365;
    int numOfDaysInLeapYear = 366;

private:
    bool isLeapYear(int year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? true : false;
    }
    int daysInMonth(int month, int year)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            return 31;
        }
        else if (month == 2)
        {
            return isLeapYear(year) ? 29 : 28;
        }
        else
        {
            return 30;
        }
    }

private:
    int daysToInt(string date)
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int days = stoi(date.substr(8, 2));

        int sumOfDaysUsingYearAndMonth = 0;

        // Sum up the number of days using year
        for (int currYear = 1971; currYear < year; currYear++)
        {
            sumOfDaysUsingYearAndMonth += isLeapYear(currYear) ? numOfDaysInLeapYear : numOfDaysInANonLeapYear;
        }

        // Sum of the number of days using month
        for (int currMonth = 1; currMonth < month; currMonth++)
        {
            sumOfDaysUsingYearAndMonth += daysInMonth(currMonth, year);
        }

        return sumOfDaysUsingYearAndMonth + days;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(daysToInt(date2) - daysToInt(date1));
    }
};