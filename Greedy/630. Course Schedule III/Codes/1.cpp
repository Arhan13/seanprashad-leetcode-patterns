#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// One line explanation: We will sort the courses based on the increasing order of thier lastDay
// and then we will use a max heap to store the courses with the longest duration on top

class Solution
{
private:
    static bool mycmp(vector<int> v1, vector<int> v2)
    {
        return v1[1] < v2[1];
    }

public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        // Sort the courses based on the increasing order of thier lastDay
        sort(courses.begin(), courses.end(), mycmp);
        // We need a max heap as we need the courses with the longest duration of top
        priority_queue<int> maxH;
        int currentDuration = 0;
        for (auto course : courses)
        {
            if (course[0] + currentDuration <= course[1])
            {
                // If the course is completed before the deadline then add it to the heap
                currentDuration += course[0];
                maxH.push(course[0]);
            }
            else if (maxH.size() > 0 && maxH.top() > course[0])
            {
                // If the course cannot be completed before the deadline
                // Check if there is a course with a longer duration than the current course, and remove it from the heap and replace it
                currentDuration -= maxH.top() - course[0];
                if (currentDuration <= course[1])
                {
                    maxH.pop();
                    maxH.push(course[0]);
                }
            }
        }
        return maxH.size();
    }
};