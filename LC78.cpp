// 78. Subsets
// Medium
// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    void helper(vector<vector<int>>& ret, const vector<int>& nums, int pos, vector<int>& tmpList){
        ret.push_back(tmpList);
        for(int i = pos; i < nums.size(); i++){
            tmpList.push_back(nums[i]);
            helper(ret, nums, i+1, tmpList);
            tmpList.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ret;
        if(nums.size()==0) return ret;
        vector<int> tmpList;
        helper(ret, nums, 0, tmpList);
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> nums {1,2,3};
    vector<vector<int>> ret = sol.subsets(nums);
    for(auto v: ret){
        for(auto n: v)
            cout<<n<<",";
        cout<<endl;
    }
    return 0;
}