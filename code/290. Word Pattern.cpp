/**
 * Given a pattern and a string s, find if s follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
 */

#include "string"
#include "vector"
#include "unordered_map"
#include "unordered_set"
using namespace std;

/**
 * The key point is that consistency needs to be determined in both directions.
 * pattern: abba
 * s: do do do do
 */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        string temp = "";
        int i = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] != ' '){
                temp += s[i++];
            }
            i++;
            str.push_back(temp);
            temp = "";
        }
        if(str.size() != pattern.length()) return false;

        unordered_map<char, string> dict1;
        unordered_set<string> dict2;
        for(int j = 0; j < pattern.length(); j++){
            if(dict1.find(pattern[j]) == dict1.end()){
                if(dict2.find(str[j]) != dict2.end()) return false;
                dict1[pattern[j]] = str[j];
                dict2.insert(str[j]);
            }else{
                if(dict1[pattern[j]] != str[j]) return false;
            }
        }
        return true;
    }
};