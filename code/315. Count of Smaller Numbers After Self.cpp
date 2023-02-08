/**
Given an integer array nums, return an integer array counts where counts[i]
 is the number of smaller elements to the right of nums[i].
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution0 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        for(int i = 0; i < n-1; i++){
            int cur = nums[i];
            for(int j = i + 1; j < n; j++){
                if(cur > nums[j]){
                    count[i]++;
                }
            }
        }
        return count;
    }
};

class Solution1 {
    vector<int> count;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count = vector<int> (n, 0);
        auto sorted = nums;
        divid(nums, sorted, 0, n - 1);
        return count;
    }
private:
    void divid(vector<int>& nums, vector<int>& sorted, int l, int r){
        if(l >= r){
            return;
        }
        int m = l + (r - l)/2;
        divid(nums, sorted, l, m);
        divid(nums, sorted, m + 1, r);

        for(int i = l; i <= m; i++){
            auto iter = lower_bound(sorted.begin()+m+1, sorted.begin()+r+1, nums[i]);
            count[i] += iter - (sorted.begin()+m+1);
        }

//        sort(sorted.begin()+l, sorted.begin()+r+1);
        merge(nums, sorted, l, m, r);
    }

    void merge(vector<int>& nums, vector<int>& sorted, int l, int m, int r){
        if(l >= r){
            return;
        }
        int n = nums.size();
        vector<int> tempNums(r-l+1, 0);

        int i = l;
        int j = m + 1;
        int k = l;
        while(i <= m && j <= r && k <= r){
            if(sorted[i] < sorted[j]){
                tempNums[k++] = sorted[i++];
            }else{
                tempNums[k++] = sorted[j++];
            }
        }

        while(j <= r && k <= r){
            tempNums[k++] = sorted[j++];
        }


        while(i <= m && k <= r){
            tempNums[k++] = sorted[i++];
        }
        
        for(int index = 0; index < r-l+1; index++){
            sorted[l + index] = tempNums[index];
        }
    }
};


int main() {
    Solution0 obj;
    Solution1 obj1;

    vector<int> nums{5,2,6,1};
    vector<int> res = obj.countSmaller(nums);
    vector<int> res1 = obj1.countSmaller(nums);

    for(auto item: res){
        cout << item << "|";
    }
    cout << "\n";
    for(auto item: res1){
        cout << item << "|";
    }

}
