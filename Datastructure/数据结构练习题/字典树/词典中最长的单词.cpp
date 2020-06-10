// 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。

// 若无答案，则返回空字符串。

class Solution {
public:
    int curmax = 0;
    string curmaxstr = "";

    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            this->isEnd = false;
            for(int i=0; i<26; i++) this->children[i] = NULL;
        }
    };

    void insert(TrieNode* root, string key){
        TrieNode* p = root;
        for(int i=0; i<key.length()-1; i++){
            int index = key[i]-'a';
            if(!p->children[index]) return;
            p = p->children[index];
        }
        if(p->isEnd){
            int index = key[key.length()-1]-'a';
            if(!p->children[index]) p->children[index] = new TrieNode();
            p = p->children[index];
            if(key.length() > curmax){
                curmax = key.length();
                curmaxstr = key;
            }
        }
        p->isEnd = true;
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        TrieNode* root = new TrieNode();
        root->isEnd = true;
        for(auto s: words){
            insert(root, s);
        }
        return curmaxstr;
    }
};