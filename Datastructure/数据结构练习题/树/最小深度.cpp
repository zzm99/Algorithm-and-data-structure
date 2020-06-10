// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if((!root->left) && (!root->right)) return 1;
        int minn = 1e7;
        if(root->left) minn = minDepth(root->left)+1;
        if(root->right) minn = min(minDepth(root->right)+1, minn);
        return minn;
    }
};