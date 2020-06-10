class WordDictionary {
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
    WordDictionary() {
        root = new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode* cur = root;
        for(int i=0; i<word.size(); i++){
            if(cur->ch[word[i]-'a'] == NULL){
                cur->ch[word[i]-'a'] = new TreeNode();
            }
            cur = cur->ch[word[i]-'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool helper(string word, TreeNode* cur, int idx){
        if(idx == word.size()){
            return cur->isEnd;
        }
        if(word[idx] == '.'){
            for(int i=0; i<26; i++){
                if(cur->ch[i]!=NULL){
                    if(helper(word, cur->ch[i], idx+1)) return true;
                }
            }
            return false;
        }
        if(cur->ch[word[idx]-'a'] == NULL) return false;
        cur = cur->ch[word[idx]-'a'];
        return helper(word, cur, idx+1);
    }
    bool search(string word) {
        TreeNode* cur = root;
        return helper(word, cur, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */