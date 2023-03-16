#include <vector>
#include "iostream"
#include "string"
#include "unordered_map"

class MapSum1 {
public:
    MapSum1() {

    }

    void insert(std::string key, int val) {
        int cur = val;
        if(m1.count(key)){
            cur -= m1[key];
        }
        m1[key] = val;
        for(int i = 1; i <= key.length(); i++){
            m2[key.substr(0, i)] += cur;
        }
    }

    int sum(std::string prefix) {
        return m2[prefix];
    }

private:
    std::unordered_map<std::string, int> m1;
    std::unordered_map<std::string, int> m2;
};


class MapSum2 {
public:
    MapSum2() {

    }
    void insert(std::string key, int val) {
        int cur = val - m[key];
        Trie* p = &root;
        for(const char c: key){
            int idx = c -'a';
            if(!p->children[idx]){
                p->children[idx] = new Trie();
            }
            p->children[idx]->sum += cur;
            p = p->children[idx];
        }
        m[key] = val;
    }

    int sum(std::string prefix) {
        Trie* p = &root;
        for(const char c: prefix){
            int idx = c - 'a';
            if(!p->children[idx]){
                return 0;
            }
            p = p->children[idx];
        }
        return p->sum;
    }

private:
    struct Trie{
        Trie() :children(26, nullptr), sum(0){}
        ~Trie(){
            for(auto child: children){
                if(child) delete child;
            }
            children.clear();
        }
        std::vector<Trie*> children;
        int sum;
    };

    Trie root;
    std::unordered_map<std::string, int> m;
};
