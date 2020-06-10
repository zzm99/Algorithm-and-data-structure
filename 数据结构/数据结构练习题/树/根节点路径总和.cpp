class Solution {
public:
    void helper(TreeNode* root, int cur, vector<vector<int>>& ret, vector<int> c){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            if(cur-root->val == 0){
                c.push_back(root->val); ret.push_back(c); return;
            }
        }
        c.push_back(root->val);
        if(root->left) helper(root->left, cur-root->val, ret, c);
        if(root->right) helper(root->right, cur-root->val, ret, c);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;// 根节点路径总和
        if(!root) return ret;
        vector<int> ord;
        helper(root, sum, ret, ord);
        return ret;
    }
};