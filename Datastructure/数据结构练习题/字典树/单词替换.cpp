class Solution {
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
    void addnode(string str){
        TreeNode* cur = root;
        for(int i=0; i<str.size(); i++){
            if(cur->children[str[i]-'a'] == NULL) cur->children[str[i]-'a'] = new TreeNode();
            cur = cur->children[str[i]-'a'];
        }  
        cur->isEnd = true;
    }

    string myfind(string word){
        string ret = "";
        string n = "";
        TreeNode* curnode = root;
        for(int i=0; i<word.size(); i++){
            if(curnode->children[word[i]-'a'] == NULL) return n;
            ret += word[i];
            curnode = curnode->children[word[i]-'a'];
            if(curnode->isEnd) return ret;
        }
        return n;
    }

    string replaceWords(vector<string>& dict, string sentence) {
        root = new TreeNode();
        for(auto& s: dict) addnode(s);
        stringstream myin(sentence);
        string curstr = "";
        string ret = "";
        while(myin >> curstr){
            string t = myfind(curstr);
            if(t != "")
                ret += t + " ";
            else
                ret += curstr + " ";
        }
        ret.pop_back();
        return ret;
    }
};