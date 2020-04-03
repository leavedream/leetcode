#include <vector>
#include <iostream>
using namespace std;

// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ret;
        perm(nums, ret, 0);
        return ret;
    }
private:
    void perm(vector<int>& nums, vector<vector<int>>& ret, int start){
        if(start == nums.size()){
            ret.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            std::swap(nums[i], nums[start]);
            perm(nums, ret, start+1);
            std::swap(nums[i], nums[start]);
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums {1,2,3};
    vector<vector<int>> ret;
    ret = sol.permute(nums);
    for(auto v: ret){
        cout<<endl;
        for(auto n: v)
            cout<<n<<",";
    }
    return 0;
}
