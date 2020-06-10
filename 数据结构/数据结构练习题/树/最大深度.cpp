// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxsum = 0;
    void getHeight(TreeNode* root, int cur){
        if(root == NULL) return;
        if(cur > maxsum) maxsum = cur;
        if(root->left) getHeight(root->left, cur+1);
        if(root->right) getHeight(root->right, cur+1);
    }
    int maxDepth(TreeNode* root) {
        getHeight(root, 1);
        return maxsum;
    }
};