// 267. Palindrome Permutation II
// Medium

// 380

// 49

// Add to List

// Share
// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

// Example 1:

// Input: "aabb"
// Output: ["abba", "baab"]
// Example 2:

// Input: "abc"
// Output: []

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    string reverse(const string& s){
        string ret = s;
        int l=0, r=s.size()-1;
        while(l<r){
            std::swap(ret[l], ret[r]);
            l++;r--;
        }
            
        return ret;
    }
    void perm(vector<string>& ret, unordered_map<char, int>& cnt, string odd, int len, string tmpStr){
        if(tmpStr.size() == len){
            ret.push_back(tmpStr + odd + reverse(tmpStr));
            return;
        }
        for(auto itr=cnt.begin(); itr != cnt.end(); itr++){
            if(itr->second == 0) continue;
            itr->second--;
            perm(ret, cnt, odd, len, tmpStr + itr->first);
            itr->second++;
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ret;
        if(s.size()==0) return ret;
        unordered_map<char, int> cnt;
        for(auto c: s)
            cnt[c]++;
        string odd="";
        for(auto itr = cnt.begin(); itr != cnt.end(); itr++){
            if(itr->second % 2 != 0){
                if(odd.size()>0)
                    return ret;
                odd += itr->first;
                itr->second--;
            }
            itr->second /= 2;
        }
        int len = s.size() / 2;
        string tmpStr = "";
        perm(ret, cnt, odd, len, tmpStr);
        return ret;
    }
};


int main(){
    Solution sol;
    string str {"aabbc "};
    vector<string> ret = sol.generatePalindromes(str);
    for(auto s: ret){
        cout<<s<<endl;
    }
    return 0;
}