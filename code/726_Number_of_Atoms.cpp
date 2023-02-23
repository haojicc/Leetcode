#include "string"
#include "map"
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        auto counts = count(formula, i);
        string res = "";
        for(auto item:counts){
            res += item.first;
            if(item.second > 1){
                res += to_string(item.second);
            }
        }
        return res;
    }
private:
    map<string, int> count(string& formula, int& i){
        map<string, int> counts;
        while(i < formula.length()){
            if(formula[i] == '('){
                auto temp_counts = count(formula, ++i);
                int times = getTimes(formula, i);
                for(auto item: temp_counts){
                    counts[item.first] += item.second * times;
                }
            }else if(formula[i] == ')'){
                ++i;
                return counts;
            }else{
                const string name = getName(formula, i);
                int times = getTimes(formula, i);
                counts[name] += times;
            }
        }
        return counts;
    }

    string getName(string& formula, int& i){
        string name = "";
        while(isalpha(formula[i]) && (name.empty() || islower(formula[i]))){
            name += formula[i++];
        }
        return name;
    }

    int getTimes(string& formula, int& i){
        string temp = "";
        while(i < formula.length() && isdigit(formula[i])){
            temp += formula[i++];
        }
        return temp.length() == 0 ? 1 : stoi(temp);
    }
};