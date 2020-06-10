/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int help(TreeNode* root, int& ans){
        if(!root) return 0;
        int l = help(root->left, ans);
        int r = help(root->right, ans);
        int l2 = 0, r2 = 0;
        if(root->left && root->val == root->left->val) l2=l+1;
        if(root->right && root->val == root->right->val) r2=r+1;
        ans = max(ans, l2+r2);
        return max(l2, r2);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans;
    }
};