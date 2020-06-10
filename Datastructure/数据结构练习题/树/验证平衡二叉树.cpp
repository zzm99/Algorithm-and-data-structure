class Solution {
public:
    int getHeight(TreeNode* root){
        if(!root) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left == NULL) return getHeight(root->right)+1;
        if(root->right == NULL) return getHeight(root->left)+1;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(root->left == NULL){
            if(getHeight(root->right) > 1) return false;
            return isBalanced(root->right);
        }
        if(root->right == NULL) {
            if(getHeight(root->left) > 1) return false;
            return isBalanced(root->left);
        }
        if(abs(getHeight(root->left)-getHeight(root->right))>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};