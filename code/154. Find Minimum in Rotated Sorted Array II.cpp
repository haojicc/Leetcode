/**
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.
From:https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findM(nums, 0, nums.size()-1);
    }

private:
    int findM(vector<int>& nums, int i, int j){
        if(i+1 >= j){
            return min(nums[i], nums[j]);
        }
        if(nums[i] < nums[j]){
            return nums[i];
        }
        int m = i + (j - i)/2;
        int left = findM(nums, i, m);
        int right = findM(nums, m+1, j);
        return min(left, right);
    }
};


int main() {
    Solution obj;

    vector<int> nums{5,6,0,1};
    int res = obj.findMin(nums);
    cout << res;
}
