/**
 * Given a pattern and a string s, return true if s matches the pattern.
 * A string s matches a pattern if there is some bijective mapping of single
 * characters to strings such that if each character in pattern is replaced
 * by the string it maps to, then the resulting string is s. A bijective mapping
 * means that no two characters map to the same string, and no character maps to
 * two different strings.
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/word-pattern-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "string"
#include "vector"
#include "unordered_map"
#include "unordered_set"
using namespace std;

/**
 * backtracking:
 * 1、中止条件：pattern的index到达终点
 *      这时候判断如果s的index也到达终点，不需要继续匹配，则返回true。（需要把匹配的过程写在进入函数前，也就是说发现匹配不成功的就不进入函数，直接backtracking）
 *      如果s的index没有到达终点，代表匹配不成功，则返回false
 * 2、递推关系：
 *      (a) 下一个pattern的char 在m.key中
 *          s中是否是m.value，如果是返回true，如果不是返回false
 *      (b) 下一个pattern的char 不在m中
 *          for loop s中全部长度可能组合的substr
 *              如果substr在set中出现过，则continue（因为pattern的char是没出现过的，所以一定不会匹配成功）
 *              如果substr在set中没出现过，记录以后调用函数
 *                  函数结果为true，直接返回true
 *                  函数结果为false，删除记录，continue
 *          结束for loop以后没有true返回，返回false。
 */
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        this->pattern = pattern;
        this->s = s;
        unordered_map<char, string> map_;
        unordered_set<string> check_;
        return backtracking(0, 0, map_, check_);
    }

private:
    string pattern;
    string s;
    bool backtracking(int index1, int index2, unordered_map<char, string>& map_, unordered_set<string>& check_){
        //1.Stop condition: the index of pattern reaches the end
        if(index1 == pattern.length()){
            if(index2 == s.length()){
                return true;
            }else{
                return false;
            }
        }
        //2.Recurrence relations.
        if(map_.find(pattern[index1]) != map_.end()){ //has been stored.
            string str = map_[pattern[index1]];
            if(index2 + str.length() <= s.length() && s.substr(index2, str.length()) == str){
                return backtracking(index1+1, index2 + str.length(), map_, check_);
            }else{
                return false;
            }
        }else{ //hasn't been stored.
            for(int i = 1; i <= s.length()-index2; i++){
                string str = s.substr(index2, i);
                if(check_.find(str) == check_.end()){
                    check_.emplace(str);
                    map_[pattern[index1]] = str;
                    if(backtracking(index1+1, index2+i, map_, check_)){
                        return true;
                    }
                    map_.erase(pattern[index1]);
                    check_.erase(str);
                }
            }
            return false;
        }
    }
};