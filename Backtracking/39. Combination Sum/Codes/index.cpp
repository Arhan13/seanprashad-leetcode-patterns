#include<iostream>
using namespace std;

class Solution {
public:
    void findCombinations(
        vector<vector<int>>& ans, 
        vector<int> candidates, 
        vector<int>& currentCandidates, 
        int currentIndex, 
        int currentTarget
    ){
        //Check if the currentTarget is less than equal to 0
        if(currentTarget <= 0 || currentIndex >= candidates.size()){
            //If target is equal to 0, the we need to add it to the solution
            if(currentTarget == 0){
                ans.push_back(currentCandidates);
            }
            return;
        }
        //Now we have two cases, 
        //We either continue with the current element
        int currentElement = candidates[currentIndex];
        if(currentElement <= currentTarget){
            currentCandidates.push_back(currentElement);
            findCombinations(
                ans,
                candidates,
                currentCandidates, 
                currentIndex, 
                currentTarget - currentElement
            );
            currentCandidates.pop_back();
        }
        //Or we don't continue with the current element and move to the next element
        findCombinations(
            ans, 
            candidates, 
            currentCandidates, 
            currentIndex + 1,
            currentTarget
        );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currentCandidates;
        int currentIndex = 0;
        findCombinations(
            ans,
            candidates,
            currentCandidates,
            currentIndex,
            target
        );
        return ans;
    }
};