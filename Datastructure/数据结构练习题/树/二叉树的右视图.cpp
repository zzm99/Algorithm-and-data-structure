class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> qq; 
        qq.push(root);
        while(!qq.empty()){
            vector<int> tmp;
            int size = qq.size();
            for(int i=0; i<size; i++){
                TreeNode* cur = qq.front();
                qq.pop();
                tmp.push_back(cur->val);
                if(cur->left) qq.push(cur->left);
                if(cur->right) qq.push(cur->right);
            }
            ret.push_back(tmp.back());
        }
        return ret;
    }
};