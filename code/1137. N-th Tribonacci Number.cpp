/**
The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int ans = 1;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        for(int i = 3; i <= n; i++){
            ans = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = ans;
        }
        return ans;
    }
};
