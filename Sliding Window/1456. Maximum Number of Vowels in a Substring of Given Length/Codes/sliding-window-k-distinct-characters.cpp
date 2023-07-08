#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        string vowels = "aeiou";
        int left = 0;
        int right = 0;
        int numberOfVowels = 0;
        int maxNumberOfVowels = 0;
        while (right < s.size())
        {
            if (vowels.find(s[right]) < vowels.length())
            {
                numberOfVowels++;
            }
            while (right - left + 1 > k)
            {
                if (vowels.find(s[left]) < vowels.length())
                {
                    numberOfVowels--;
                }
                left++;
            }
            maxNumberOfVowels = max(maxNumberOfVowels, numberOfVowels);
            right++;
        }
        return maxNumberOfVowels;
    }
};