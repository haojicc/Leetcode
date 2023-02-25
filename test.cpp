#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"
using namespace std;


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
        for(auto item: str){
            cout << item << endl;
        }
        if(str.size() != pattern.length()) return false;

        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;
        for(int j = 0; j < pattern.length(); j++){
            if(dict1.find(pattern[j]) == dict1.end()){
                if(dict2.find(str[j]) != dict2.end()) return false;
                dict1[pattern[j]] = str[j];
                dict2[str[j]] = pattern[j];
            }else{
                if(dict1[pattern[j]] != str[j]) return false;
            }
        }
        return true;
    }
};

int main(){
    Solution obj;
    string p = "abba";
    string s = "do ca ca do";

    bool ret = obj.wordPattern(p,s);
    cout << ret <<endl;

    return 0;
}