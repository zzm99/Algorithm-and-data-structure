// 对于search方法，你将被给定一个单词，并且判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。

class MagicDictionary {
public:
    struct TreeNode{
        bool isEnd;
        TreeNode* children[26];
        TreeNode(){
            isEnd = false;
            for(int i=0; i<26; i++) children[i] = NULL;
        }
        ~TreeNode(){
            for(TreeNode* child: children)
                if(child) delete child;
        }
    };
    TreeNode* root;

    MagicDictionary() {
        root = new TreeNode();
    }
    void addnode(string str){
        TreeNode* cur = root;
        for(int i=0; i<str.size(); i++){
            if(cur->children[str[i]-'a'] == NULL) cur->children[str[i]-'a'] = new TreeNode();
            cur = cur->children[str[i]-'a'];
        }  
        cur->isEnd = true;
    }

    void buildDict(vector<string> dict) {
        for(int i=0; i<dict.size(); i++)
            addnode(dict[i]);
    }
    
    bool newfind(string word, int curidx, bool ischange, TreeNode* curroot){
        if(curroot == NULL) return false;
        if(word.size() == curidx) return ischange && curroot->isEnd;
        for(int i=0; i<26; i++){
            if(curroot->children[i] != NULL){
                if('a'+i == word[curidx]){
                    if(newfind(word, curidx+1, ischange, curroot->children[i]))
                        return true;
                }
                else {
                    if(ischange == false && newfind(word, curidx+1, true, curroot->children[i]))
                        return true;
                }
            }
        }
        return false; 
    }

    bool search(string word) {
        return newfind(word, 0, false, root);
    }
};
