/**
Given an integer array arr and an integer difference, return the length
of the longest subsequence in arr which is an arithmetic sequence such
that the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some
 or no elements without changing the order of the remaining elements.
 */
#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        for(auto x: arr){
            dp[x] = dp[x - difference] + 1;
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr{1,2,3,4};
    int difference = 1;
    int res = obj.longestSubsequence(arr, difference);
    cout << res << endl;
}
