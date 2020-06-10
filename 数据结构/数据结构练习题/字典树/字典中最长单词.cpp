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