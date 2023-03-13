/*
In English, we have a concept called root, which can be followed by
some other word to form another longer word - let's call this word
successor. For example, when the root "an" is followed by the successor
word "other", we can form a new word "another".
Given a dictionary consisting of many roots and a sentence consisting
of words separated by spaces, replace all the successors in the
sentence with the root forming it. If a successor can be replaced
by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled
by the battery"
Output: "the cat was rat by the bat"
*/

func replaceWords(dictionary []string, sentence string) string {
    trie := Constructor()
    for _, word := range dictionary{
        trie.Insert(word)
    }
    strs := split(sentence)
    for i := 0; i < len(strs); i++{
        if s := trie.StartsWith(strs[i]); s != ""{
            strs[i] = s
        }
    }
    return merge(strs)
}

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

func (this *Trie) StartsWith(prefix string) string {
    curr := this
    str := ""
    for _, ch := range prefix{
        idx := ch - 'a'
        if curr.isWord == true{
            return str
        }
        if curr.children[idx] == nil{
            return ""
        }
        str += string(ch)
        curr = curr.children[idx]
    }
    return str
}

func split(str string) []string{
    res, i, s := []string{}, 0, 0
    for i < len(str){
        if str[i] == ' '{
            res = append(res, str[s:i])
            s = i+1
        }
        i++
    }
    return append(res, str[s:i])
}

func merge(str []string) string{
    res := ""
    for _, v := range str{
        if res == ""{
            res  = v
        }else{
            res = res + " " + v
        }
    }
    return res
}