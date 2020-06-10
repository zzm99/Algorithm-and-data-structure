// https://leetcode-cn.com/problems/invert-binary-tree/
// 输入：

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// 输出：

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* rightTree = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(rightTree);
        return root;
    }
};