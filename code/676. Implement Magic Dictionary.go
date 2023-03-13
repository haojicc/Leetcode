/*
Design a data structure that is initialized with a list of different words.
Provided a string, you should determine if you can change exactly one
character in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array
of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one
character in searchWord to match any string in the data structure, otherwise
returns false.
*/

type MagicDictionary struct {
    children [26]*MagicDictionary
    isWord bool
}

func Constructor() MagicDictionary {
    return MagicDictionary{}
}

func (this *MagicDictionary) insert(word string){
    curr := this
    for _, ch := range word{
        idx := ch - 'a'
        if curr.children[idx] == nil{
            curr.children[idx] = &MagicDictionary{}
        }
        curr = curr.children[idx]
    }
    curr.isWord = true
}

func (this *MagicDictionary) BuildDict(dictionary []string)  {
    for _, word := range dictionary{
        this.insert(word)
    }
}

func (this *MagicDictionary) Search(searchWord string) bool {
    return dfs(this, searchWord, 0, 1)
}

func dfs(r *MagicDictionary, w string, i int, limit int) bool{
    if limit < 0{
        return false
    }

    if i == len(w){
        return r.isWord && limit == 0
    }

    ch := w[i] - 'a'
    for c, t := range r.children{
        if t == nil{
            continue
        }
        if c == int(ch) && dfs(t, w, i+1, limit){
            return true
        }
        if c != int(ch) && dfs(t, w, i+1, limit-1){
            return true
        }
    }
    return false
}
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.BuildDict(dictionary);
 * param_2 := obj.Search(searchWord);
 */