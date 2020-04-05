// 90. Subsets II
// Medium
// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    void helper(vector<vector<int>>& ret, vector<int>& nums, int pos, vector<int>& tmpList){
        ret.push_back(tmpList);
        if(pos >= nums.size())
            return;
        for(int i = pos; i < nums.size(); i++){
            if(i > pos && nums[i] == nums[i-1]) continue;
            tmpList.push_back(nums[i]);
            helper(ret, nums, i+1, tmpList);
            tmpList.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if(nums.size()==0) return ret;
        vector<int> tmpList;
        helper(ret, nums, 0, tmpList);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> nums {1,2,2};
    vector<vector<int>> ret = sol.subsetsWithDup(nums);
    for(auto v: ret){
        for(auto n: v)
            cout<<n<<",";
        cout<<endl;
    }
    return 0;
}