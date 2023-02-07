/**
Given an integer n, return the number of structurally unique BST's (binary search trees)
which has exactly n nodes of unique values from 1 to n.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        for(int len = 2; len <= n; len++){
            dp[len] = 0;
            for(int j = 0; j < len; j++){
                dp[len] += (dp[j] * dp[len - 1 - j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution obj;
    int num = 10;
    int res = obj.numTrees(num);
    cout << res << endl;
}
