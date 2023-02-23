#include "string"
#include "vector"
#include "unordered_map"
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                str.push_back(temp);
                temp = "";
            }else{
                temp += s[i];
            }
        }
        if(temp != ""){
            str.push_back(temp);
        }
        if(str.size() != pattern.length()){
            return false;
        }

        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;

        for(int i = 0; i < pattern.size(); i++){
            if(dict1.find(pattern[i]) == dict1.end()){
                if(dict2.find(str[i]) != dict2.end()){
                    return false;
                }
                dict1[pattern[i]] = str[i];
                dict2[str[i]] = pattern[i];
            }else{
                if(dict2[str[i]] != pattern[i]){
                    return false;
                }
            }
        }
        return true;
    }
};