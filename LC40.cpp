// 40. Combination Sum II
// Medium

// 1429

// 56

// Add to List

// Share
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void helper(vector<vector<int>>& ret, vector<int>& nums, int pos, int target, vector<int>& tmpList){
        if(target==0){
            ret.push_back(tmpList);
            return;
        }
        if(pos >= nums.size())
            return;
        for(int i = pos; i < nums.size(); i++){
            if(i > pos && nums[i] == nums[i-1]) continue;
            if(target<nums[i]) continue;
            tmpList.push_back(nums[i]);
            helper(ret, nums, i+1, target - nums[i], tmpList);
            tmpList.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if(candidates.size()==0) return ret;
        std::sort(candidates.begin(), candidates.end());
        vector<int> tmpList;
        helper(ret, candidates, 0, target, tmpList);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> nums {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    int target {27};
    vector<vector<int>> ret;
    ret = sol.combinationSum2(nums, target);
    for(auto v: ret){
        for(auto n: v){
            cout<<n<<",";
        }
        cout<<endl;
    }
    return 0;
}