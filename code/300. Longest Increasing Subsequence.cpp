/**
Given an integer array nums, return the length of the longest strictly increasing subsequence.
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(auto c: nums){
            auto item = lower_bound(dp.begin(), dp.end(), c);
            if(item == dp.end()){
                dp.push_back(c);
            }else{
                *item = c;
            }
        }
        return dp.size();
    }
};
