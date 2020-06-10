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
    int sum = 0;
    void bstToGstCore(TreeNode* root){
        if(root->right != NULL)
            bstToGstCore(root->right);
        root->val += sum;
        sum = root->val;
        if(root->left != NULL){
            bstToGstCore(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return NULL;
        bstToGstCore(root);
        return root;
    }
};