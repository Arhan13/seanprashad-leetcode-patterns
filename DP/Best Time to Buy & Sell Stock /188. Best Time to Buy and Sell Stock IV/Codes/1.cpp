#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back

// DP Pattern - Partition Problem
// Is this problem a variation of the Partition Problem?
// Yes, this problem is a variation of the Partition Problem. In this problem, we have to divide the given array into two subsets such that the difference between the sum of the elements of the two subsets is equal to the given value k. In the Partition Problem, we have to divide the given array into two subsets such that the difference between the sum of the elements of the two subsets is minimum.
// is this problem a variation of the 0/1 Knapsack Problem?
// Yes, this problem is a variation of the 0/1 Knapsack Problem. In this problem, we have to divide the given array into two subsets such that the difference between the sum of the elements of the two subsets is equal to the given value k. In the 0/1 Knapsack Problem, we have to divide the given array into two subsets such that the sum of the elements of one subset is maximum and the sum of the elements of the other subset is less than or equal to the given value k.
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
// n: size of prices vector
// k: given value
// What is the pattern of DP that this question comes under?
// This question comes under the pattern of Partition Problem. In this pattern, we divide the given problem into multiple subproblems and then combine the results of these subproblems to obtain the final result. The subproblems in this pattern do not overlap.
// What is the recurrence relation for this problem?
// The recurrence relation for this problem is as follows:
// dpSolve(isBuy, currentIndex, k) = max(dpSolve(isBuy, currentIndex + 1, k), -prices[currentIndex] + dpSolve(false, currentIndex + 1, k), prices[currentIndex] + dpSolve(true, currentIndex + 1, k - 1))
// Here, isBuy is a boolean variable that tells us whether we have bought a stock or not. If isBuy is true, it means that we have bought a stock and if isBuy is false, it means that we have not bought a stock.
// currentIndex is the index of the current element in the prices vector.
// k is the number of transactions that we can make.
// dpSolve(isBuy, currentIndex, k) is the maximum profit that we can make if we have made k transactions and the current index is currentIndex and the isBuy status is isBuy.
// dpSolve(isBuy, currentIndex + 1, k) is the maximum profit that we can make if we do not buy or sell the stock at the current index and move to the next index.
// -prices[currentIndex] + dpSolve(false, currentIndex + 1, k) is the maximum profit that we can make if we buy the stock at the current index and move to the next index.
// prices[currentIndex] + dpSolve(true, currentIndex + 1, k - 1) is the maximum profit that we can make if we sell the stock at the current index and move to the next index.
// What is the base case for this problem?
// The base case for this problem is as follows:
// if (currentIndex == prices.size())
// {
//     return 0;
// }
// Here, we return 0 if the currentIndex is equal to the size of the prices vector. This is because we have reached the end of the prices vector and we cannot make any more transactions.
// What is the direction of computation for this problem?
// The direction of computation for this problem is from the base case to the final answer. This is because we are using memoization to store the results of subproblems and avoiding recomputation of the same subproblems.
// What is the order of computation for this problem?
// The order of computation for this problem is as follows:
// dpSolve(isBuy, currentIndex, k) -> dpSolve(isBuy, currentIndex + 1, k) -> dpSolve(false, currentIndex + 1, k) -> dpSolve(true, currentIndex + 1, k - 1)
// Here, we first compute dpSolve(isBuy, currentIndex, k) and then we compute dpSolve(isBuy, currentIndex + 1, k) and so on.
// What is the size of the memo table for this problem?
// The size of the memo table for this problem is O(nk), where n is the size of the prices vector and k is the given value. This is because we are using memoization to store the results of subproblems and the memo table has nk entries.
// What is the time complexity for this problem?
// The time complexity for this problem is O(n*k), where n is the size of the prices vector and k is the given value. This is because we are using memoization to store the results of subproblems and avoiding recomputation of the same subproblems.
// What is the space complexity for this problem?
// The space complexity for this problem is O(nk), where n is the size of the prices vector and k is the given value. This is because we are using memoization to store the results of subproblems and the memo table has nk entries.
// What is the difficulty level of this problem?
// The difficulty level of this problem is hard.
// What is the key observation for this problem?
// The key observation for this problem is that we can either buy or sell a stock at a particular index. If we buy a stock at a particular index, we can sell it at a later index. If we sell a stock at a particular index, we can buy it at a later index. We can make at most k transactions. We can buy a stock only if we have not bought a stock before. We can sell a stock only if we have bought a stock before.
// What is the intuition behind the solution for this problem?
// The intuition behind the solution for this problem is that we can either buy or sell a stock at a particular index. If we buy a stock at a particular index, we can sell it at a later index. If we sell a stock at a particular index, we can buy it at a later index. We can make at most k transactions. We can buy a stock only if we have not bought a stock before. We can sell a stock only if we have bought a stock before.
// What is the approach to solve this problem?
// The approach to solve this problem is as follows:
// We use memoization to store the results of subproblems and avoid recomputation of the same subproblems.
// We use a 3D memo table to store the results of subproblems.
// The dimensions of the memo table are as follows:
// The first dimension is the isBuy status. It can be either true or false.
// The second dimension is the currentIndex. It can be from 0 to n - 1, where n is the size of the prices vector.
// The third dimension is the k value. It can be from 0 to k, where k is the given value.
// We initialize the memo table with -1.
// We return dpSolve(true, 0, k).
// What is the implementation of the approach?
// The implementation of the approach is as follows:
// We define a function dpSolve(isBuy, currentIndex, k) to solve this problem.
// We check if the currentIndex is equal to the size of the prices vector. If it is, we return 0.
// We check if the memo table has the value for the current state. If it does, we return the value.
// We define a variable ans to store the maximum profit.
// We set ans to dpSolve(isBuy, currentIndex + 1, k).
// We check if isBuy is true. If it is, we set ans to max(ans, -prices[currentIndex] + dpSolve(false, currentIndex + 1, k)).
// We check if isBuy is false. If it is, we set ans to max(ans, prices[currentIndex] + dpSolve(true, currentIndex + 1, k - 1)).
// We set the value of the memo table for the current state to ans.
// We return ans.
// What is the order of the algorithm for this problem?
// The order of the algorithm for this problem is O(nk), where n is the size of the prices vector and k is the given value. This is because we are using memoization to store the results of subproblems and avoiding recomputation of the same subproblems.
// What is the space complexity of the algorithm for this problem?
// The space complexity of the algorithm for this problem is O(nk), where n is the size of the prices vector and k is the given value. This is because we are using memoization to store the results of subproblems and the memo table has nk entries.
// What are the limitations of the algorithm for this problem?
// The limitations of the algorithm for this problem are as follows:
// The algorithm does not work if the prices vector is empty.
// The algorithm does not work if the k value is less than 0.
// The algorithm does not work if the k value is greater than the size of the prices vector.
// The algorithm does not work if the prices vector has negative values.
// The algorithm does not work if the prices vector has duplicate values.
// The algorithm does not work if the prices vector has values greater than 100000.
// The algorithm does not work if the prices vector has values less than 0.

class Solution
{
public:
    int dpSolve(bool isBuy, int currentIndex, int k, vector<int> &prices, vector<vector<vector<int>>> &memo)
    {
        if (currentIndex == prices.size())
            return 0;
        int ans = 0;
        // Do nothing
        // The isBuy status does not change
        // We move to the next element
        if (memo[isBuy ? 1 : 0][currentIndex][k] != -1)
        {
            return memo[isBuy ? 1 : 0][currentIndex][k];
        }
        // We do nothing
        ans = dpSolve(isBuy, currentIndex + 1, k, prices, memo);
        if (k == 0)
            return 0;
        // If you buy
        // The next transaction will be a sell so isBuy is false
        // We will move to the next element in prices
        if (isBuy)
        {
            ans = max(ans, -prices[currentIndex] + dpSolve(false, currentIndex + 1, k, prices, memo));
        }
        else
        {
            // If you sell
            // The next transaction will be a buy so isBuy is true
            // We will move to the next element in prices
            // We reduce k by one because we finish a transaction
            ans = max(ans, prices[currentIndex] + dpSolve(true, currentIndex + 1, k - 1, prices, memo));
        }
        memo[isBuy ? 1 : 0][currentIndex][k] = ans;
        return ans;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(prices.size() + 1, vector<int>(k + 1, -1)));
        return dpSolve(true, 0, k, prices, memo);
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    Solution S;
    cout << S.maxProfit(k, prices) << endl;
    return 0;
}