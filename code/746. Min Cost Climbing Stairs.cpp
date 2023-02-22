/**
You are given an integer array cost where cost[i] is the cost of ith step
 on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp1 = 0;
        int dp2 = 0;
        for(int i = 2; i <= cost.size(); ++i){
            int dp = min(dp1 + cost[i-1] ,dp2 + cost[i-2]);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};
