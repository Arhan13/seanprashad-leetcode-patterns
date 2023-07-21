#include <iostream>
#include <vector>
using namespace std;

// Question - https://www.chegg.com/homework-help/questions-and-answers/develop-function-c-called-date-thirdlatest-std-vector-dates-returns-third-latest-date-q29665441

struct Date
{
    int day, month, year;
};

class Solution
{
private:
    bool isEarlier(Date date1, Date date2)
    {
        if (date1.year != date2.year)
        {
            return date1.year < date2.year;
        }
        else if (date1.month != date2.month)
        {
            return date1.month < date2.month;
        }
        else
        {
            return date1.day < date2.day;
        }
    }

public:
    Date getThirdLatestDate(vector<Date> &dates)
    {
        Date firstLatestDate = dates[0], secondLatestDate = dates[1], thirdLatestDate = dates[2];
        for (int i = 3; i < dates.size(); i++)
        {
            if (isEarlier(dates[i], firstLatestDate))
            {
                thirdLatestDate = secondLatestDate;
                secondLatestDate = firstLatestDate;
                firstLatestDate = dates[i];
            }
            else if (isEarlier(dates[i], secondLatestDate))
            {
                thirdLatestDate = secondLatestDate;
                secondLatestDate = dates[i];
            }
            else if (isEarlier(dates[i], thirdLatestDate))
            {
                thirdLatestDate = dates[i];
            }
        }
        return thirdLatestDate;
    }
};

int main()
{
    Solution S;
    vector<Date> dates = {{14, 4, 2001}, {29, 12, 2061}, {21, 10, 2019}, {7, 1, 1973}, {19, 7, 2014}, {11, 3, 1992}, {21, 10, 2019}};
    Date thirdLatest = S.getThirdLatestDate(dates);
    cout << thirdLatest.day << "-" << thirdLatest.month << "-" << thirdLatest.year << endl;
    return 0;
}
