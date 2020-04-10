// 311. Sparse Matrix Multiplication
// Medium
// Given two sparse matrices A and B, return the result of AB.

// You may assume that A's column number is equal to B's row number.

// Example:

// Input:

// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]

// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]

// Output:

//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        if(m == 0) return vector<vector<int>>();
        int nA = A[0].size(); 
        int n = B[0].size();
        
        vector<vector<int>> ret(m, vector<int>(n, 0));
        vector<vector<int>> sparseA;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < nA; j++){
                if(A[i][j]!=0)
                    sparseA.push_back({A[i][j], i, j});
            }
        }
        
        for(auto ele: sparseA){
            for(int col = 0; col < n; col++){
                if(B[ele[2]][col] != 0)
                    ret[ele[1]][col] += ele[0] * B[ele[2]][col];
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> A {{1,0,0}, {-1,0,3}};
    vector<vector<int>> B {{7,0,0}, {0,0,0}, {0,0,1}};
    vector<vector<int>> ret = sol.multiply(A, B);
    for(auto row: ret){
        for(auto cell: row){
            cout<<cell<<",";
        }
        cout<<endl;
    }
    return 0;
}
