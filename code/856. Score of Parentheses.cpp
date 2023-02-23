/**
 * Given a balanced parentheses string s, return the score of the string.
 * The score of a balanced parentheses string is based on the following rule:
 * "()" has score 1.
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 */
#include "string"
using namespace std;

/**
 * Because string s must be balanced, it is possible to count from the outside to the inside layer by layer.
 * But there may be two parallel balanced substrings, and it is necessary to do the addition operation.
 * So use a for loop to check for the presence of balanced substrings.
 * If there is no such substring, remove one layer and the result *2.
 */

class Solution1 {
public:
    int scoreOfParentheses(string s) {
        return sc(s, 0, s.length()-1);
    }

private:
    int sc(string& s, int l, int r){
        if(r - l == 1) return 1;
        int b = 0;
        for(int i = l; i < r; i++){
            if(s[i] == '('){
                b++;
            }else{
                b--;
            }
            if(b == 0){
                return sc(s, l, i) + sc(s, i+1, r);
            }
        }
        return 2 * sc(s, l+1, r-1);
    }
};
/**
* It also can be solved by the idea of a stack.
 * When () appears, we add scores to the result, and exactly how many scores to add depends on how many layers are outside ().
*/

class Solution2 {
public:
    int scoreOfParentheses(string s) {
        int d = -1;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                d++;
            }else{
                d--;
            }
            if(s[i] == '(' && s[i+1] == ')'){
                res += 1 << d;
            }
        }
        return res;
    }
};