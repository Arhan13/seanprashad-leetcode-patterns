#include <algorithm> // copy
#include <iostream>  // boolalpha, cin, cout
#include <iterator>  // back_inserter, istream_iterator
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector

int find_boundary(std::vector<bool> arr)
{
    // WRITE YOUR BRILLIANT CODE HERE
    int left = 0;
    int right = arr.size() - 1;
    int boundaryIndex = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid])
        {
            boundaryIndex = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return boundaryIndex;
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

int main()
{
    std::vector<bool> arr = get_words<bool>();
    int res = find_boundary(arr);
    std::cout << res << '\n';
}
