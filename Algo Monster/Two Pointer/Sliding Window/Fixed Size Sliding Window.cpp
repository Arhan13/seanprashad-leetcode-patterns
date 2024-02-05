#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
using namespace std;

int subarray_sum_fixed(std::vector<int> nums, int k)
{
    // WRITE YOUR BRILLIANT CODE HERE
    if (nums.size() < k)
    {
        return 0;
    }
    int left = 0;
    int right = k - 1;
    int maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        maxSum += nums[i];
    }
    int currSum = maxSum;
    while (right < nums.size() - 1)
    {
        currSum = currSum - nums[left] + nums[right + 1];
        maxSum = max(maxSum, currSum);
        left++;
        right++;
    }
    return maxSum;
}

template <typename T>
std::vector<T> get_words()
{
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    int res = subarray_sum_fixed(nums, k);
    std::cout << res << '\n';
}
