#include <iostream> // cin, cout
#include <string>   // getline, string
#include <bits/stdc++.h>
using namespace std;

int longest_substring_without_repeating_characters(std::string s)
{
    // WRITE YOUR BRILLIANT CODE HERE
    unordered_map<char, int> ump;
    int left = 0;
    int right = 0;
    int length = 0;
    while (right < s.size())
    {
        ump[s[right]]++;
        while (ump[s[right]] > 1)
        {
            ump[s[left]]--;
            left++;
        }
        length = max(length, right - left + 1);
        right++;
    }

    return length;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    int res = longest_substring_without_repeating_characters(s);
    std::cout << res << '\n';
}
