/*
You are given a 0-indexed integer array books of length n where books[i] denotes the number of books on the ith shelf of a bookshelf.
You are going to take books from a contiguous section of the bookshelf spanning from l to r where 0 <= l <= r < n. For each index i 
in the range l <= i < r, you must take strictly fewer books from shelf i than shelf i + 1.
Return the maximum number of books you can take from the bookshelf.

Example 1:

Input: books = [8,5,2,7,9]
Output: 19
Explanation:
- Take 1 book from shelf 1.
- Take 2 books from shelf 2.
- Take 7 books from shelf 3.
- Take 9 books from shelf 4.
You have taken 19 books, so return 19.
It can be proven that 19 is the maximum number of books you can take.

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-number-of-books-you-can-take
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
dp[i]:= Maxinum number of taken off end with i-th shelf.
（1）If i to 0 can be taken as a series of equal differences with -1, then dp[i] can be easily calculated by summation.
（2）Otherwise, dp[i] = dp[j] + summation(j+1 to i).  books[j] < books[i] - (i - j) ==> books[j] - j < book[i] - i
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;

class Solution {
public:
    ll calSum(ll tail, ll len){
        ll res = (tail + tail - len + 1) * len / 2LL;
        return res;
    }

    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<pair<int, int>> stk;
        vector<ll> dp(n);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int cur = books[i] - i;
            while(stk.size() && stk.back().first > cur){
                stk.pop_back();
            }

            int j = max(-1, i - books[i]);
            if(stk.size()){
                j = stk.back().second;
                dp[i] = max(dp[i], dp[j]);
            }
            stk.push_back({cur, i});
            dp[i] += calSum(books[i], i - j);
            ans = max(ans, dp[i]);
            printStk(stk);
        }
        return ans;
    }

private:
    void printStk(vector<pair<int, int>> stk){
        for(auto item: stk){
            cout << "first:" << item.first << "    second:" << item.second << endl;
        }
    }
};
