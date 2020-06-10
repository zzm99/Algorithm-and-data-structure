class Trie {
public:
    class TreeNode{
    public:
        TreeNode* ch[26];
        bool isEnd;
        TreeNode(){
            isEnd = false;
            for(int i=0; i<26; i++){
                ch[i] = NULL;
            }
        }
    };
    TreeNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TreeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* cur = root;
        for(int i=0; i<word.size(); i++){
            if(cur->ch[word[i]-'a'] == NULL){
                cur->ch[word[i]-'a'] = new TreeNode();
            }
            cur = cur->ch[word[i]-'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* cur = root;
        for(int i=0; i<word.size(); i++){
            if(cur->ch[word[i]-'a'] == NULL) return false;
            cur = cur->ch[word[i]-'a'];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(int i=0; i<prefix.size(); i++){
            if(cur->ch[prefix[i]-'a'] == NULL) return false;
            cur = cur->ch[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */