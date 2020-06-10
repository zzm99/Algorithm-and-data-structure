// 给定二叉树

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// 将其展开为：

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right != NULL) root = root->right;
        root->right = temp;
    }
};