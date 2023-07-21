#include <iostream>
#include <vector>
using namespace std;

// Question - https://www.chegg.com/homework-help/questions-and-answers/develop-function-c-called-date-thirdlatest-std-vector-dates-returns-third-latest-date-q29665441

struct Date
{
    int day, month, year;
};

bool isEarlier(Date d1, Date d2)
{
    if (d1.year != d2.year)
    {
        return d1.year < d2.year;
    }
    else if (d1.month != d2.month)
    {
        return d1.month < d2.month;
    }
    else
    {
        return d1.day < d2.day;
    }
}

Date thirdLatestDate(vector<Date> dates)
{
    Date latest = dates[0], secondLatest = dates[1], thirdLatest = dates[2];
    for (int i = 3; i < dates.size(); i++)
    {
        if (isEarlier(dates[i], latest))
        {
            thirdLatest = secondLatest;
            secondLatest = latest;
            latest = dates[i];
        }
        else if (isEarlier(dates[i], secondLatest))
        {
            thirdLatest = secondLatest;
            secondLatest = dates[i];
        }
        else if (isEarlier(dates[i], thirdLatest))
        {
            thirdLatest = dates[i];
        }
    }
    return thirdLatest;
}

int main()
{
    vector<Date> dates = {{14, 4, 2001}, {29, 12, 2061}, {21, 10, 2019}, {7, 1, 1973}, {19, 7, 2014}, {11, 3, 1992}, {21, 10, 2019}};
    Date thirdLatest = thirdLatestDate(dates);
    cout << thirdLatest.day << "-" << thirdLatest.month << "-" << thirdLatest.year << endl;
    return 0;
}