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
    vector<int> arr;
    void helper(TreeNode* root, int k){
        if(arr.size()==k) return;
        if(root->left)
            kthSmallest(root->left, k);
        arr.push_back(root->val);
        if(root->right)
            kthSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k); 
        return arr[k-1];
    }
};