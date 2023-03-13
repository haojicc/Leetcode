/*
A trie (pronounced as "try") or prefix tree is a tree data structure
used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously
inserted string word that has the prefix prefix, and false otherwise.
*/

type Trie struct {
    children [26]*Trie
    isWord bool
}


func Constructor() Trie {
    return Trie{}
}


func (this *Trie) Insert(word string)  {
    curr := this
    for _, ch := range word{
        idx := ch - 'a'
        if curr.children[idx] == nil{
            curr.children[idx] = &Trie{}
        }
        curr = curr.children[idx]
    }
    curr.isWord = true
}


func (this *Trie) Search(word string) bool {
    curr := this
    for _, ch := range word{
        idx := ch - 'a'
        if curr.children[idx] == nil{
            return false
        }
        curr = curr.children[idx]
    }
    return curr.isWord
}


func (this *Trie) StartsWith(prefix string) bool {
    curr := this
    for _, ch := range prefix{
        idx := ch - 'a'
        if curr.children[idx] == nil{
            return false
        }
        curr = curr.children[idx]
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */