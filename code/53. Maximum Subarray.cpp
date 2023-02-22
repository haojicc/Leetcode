/**
 *
 * Given an integer array nums, find the subarray
 * with the largest sum, and return its sum.
 */

#include <iostream>
#include <vector>
using namespace std;

class dymanicProgramming {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] = max(nums[i-1] + nums[i], nums[i]);//subarray ,that is end with nums[i], with the largest sum.
            largest = max(largest, nums[i]);
        }
        return largest;
    }
};

class divideAndConquer {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums, 0, nums.size() - 1);
    }

private:
    int maxSub(vector<int>& nums, int L, int R){
        if(L > R) return INT_MIN;
        int mid = L + (R - L) / 2;

        int leftSum = 0;
        int rightSum = 0;

        for(int i = mid - 1, currSum = 0; i >= L; i--){
            currSum += nums[i];
            leftSum = max(leftSum, currSum);
        }


        for(int i = mid + 1, currSum = 0; i <= R; i++){
            currSum += nums[i];
            rightSum = max(rightSum, currSum);
        }

        return max({maxSub(nums, L, mid-1), maxSub(nums, mid+1, R), leftSum + rightSum + nums[mid]});
    }
};