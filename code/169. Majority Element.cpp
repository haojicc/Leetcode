/**
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.
 */
#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(const int x: nums){
            if(m[x] >= n / 2){
                return x;
            }else{
                m[x]++;
            }
        }

        return 0;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution obj;
    Solution2 obj2;
    vector<int> arr{3,2,3};
    int res = obj.majorityElement(arr);
    int res2 = obj2.majorityElement(arr);
    cout << res << res2 << endl;
}
