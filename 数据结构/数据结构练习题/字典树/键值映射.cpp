class MapSum {
public:
    struct TreeNode{
        int isEnd;
        int data;
        TreeNode* children[26];
        TreeNode(){
            isEnd = false;
            data = 0;
            for(int i=0; i<26; i++) children[i] = NULL;
        }
    };
    TreeNode* root;
    
    MapSum() {
        root = new TreeNode();    
    }
    
    void insert(string key, int val) {
        TreeNode* cur = root;
        for(int i=0; i<key.size(); i++){
            int curc = key[i]-'a';
            if(cur->children[curc] == NULL) cur->children[curc] = new TreeNode();
            cur = cur->children[curc];
        }
        cur->isEnd = true;
        cur->data = val;
    }
    
    void dfs(TreeNode* curroot, int &sum){
        if(curroot->isEnd) sum += curroot->data;
        for(int i=0; i<26; i++){
            if(curroot->children[i]){
                dfs(curroot->children[i], sum);
            }
        }
    }

    int sum(string prefix) {
        TreeNode* cur = root;
        for(int i=0; i<prefix.size(); i++){
            int cc=prefix[i]-'a';
            if(cur->children[cc] == NULL) return 0;
            cur = cur->children[cc];
        }
        int ret = 0;
        dfs(cur, ret);
        return ret;
    }
};
