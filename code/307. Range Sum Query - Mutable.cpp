#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums): sums_(nums.size() + 1), nums_(nums) {
        for(int i = 0; i < nums.size(); i++){
            updataProcess(i+1, nums_[i]);
        }
    }

    void update(int index, int val) {
        updataProcess(index + 1, val - nums_[index]);
        nums_[index] = val;
    }

    int sumRange(int left, int right) {
        return cumulativePrefixSum(right + 1) - cumulativePrefixSum(left);
    }

private:
    vector<int> sums_;
    vector<int> nums_;

    int getLowBit(int index){
        return index & (-index);
    }

    void updataProcess(int index, int val){
        while(index < sums_.size()){
            sums_[index] += val;
            index += getLowBit(index);
        }
    }

    int cumulativePrefixSum(int index){
        int sum = 0;
        while(index > 0){
            sum += sums_[index];
            index -= getLowBit(index);
        }
        return sum;
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/*
In this binary indexed tree, there are two different structures.
One is the structure used as updata value,
and the other is the structure used as cumulative prefix sum.
The structure used to updata_value is (index += index & -index).
And the structure used to cumulative_prefix_sum is (index -= index & -index).

*/