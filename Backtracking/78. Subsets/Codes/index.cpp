#include<iostream>
using namespace std;

class Solution {
public:
    void generateSubsets(vector<int> nums, vector<vector<int>>& ans, vector<int>& availNums, int currentIndex){
        //If the size of the currentIndex >= nums.size() then these are the elements at the
        //bottom of the tree and these contain all the subsets.
        if(currentIndex >= nums.size()){
            ans.push_back(availNums);
            return;
        }
        //Get the current number
        int currentNumber = nums[currentIndex];
        //Add it to the available numbers
        availNums.push_back(currentNumber);
        generateSubsets(nums, ans, availNums, currentIndex+1);
        //Now without the current number
        availNums.pop_back();
        generateSubsets(nums, ans, availNums, currentIndex+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> availNums;
        int currIndex = 0;
        generateSubsets(nums, ans, availNums, 0);
        return ans;
    }
};