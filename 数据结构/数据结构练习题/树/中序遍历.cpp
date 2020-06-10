// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ret){
        if(!root) return;
        if(root->left) helper(root->left, ret);
        ret.push_back(root->val);
        if(root->right) helper(root->right, ret);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        helper(root, ret);
        return ret;
    }
};