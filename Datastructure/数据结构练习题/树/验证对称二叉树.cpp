class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
    bool helper(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val == q->val)
            return helper(p->left, q->right) && helper(p->right, q->left);
        return false;
    }
};