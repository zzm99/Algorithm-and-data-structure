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
    vector<int> t;
    void inorder(TreeNode* root){
        if(root->left) inorder(root->left);
        t.push_back(root->val);
        if(root->right) inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        inorder(root);
        int minn = INT_MAX;
        for(int i=0; i<t.size()-1; i++){
            minn = min(minn, abs(t[i+1]-t[i]));
        }
        return minn;
    }
};