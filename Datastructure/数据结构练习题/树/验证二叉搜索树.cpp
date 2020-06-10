// https://leetcode-cn.com/problems/validate-binary-search-tree/
// 二叉搜索树 中序遍历为升序
class Solution {
public:
    void inorder(vector<int>& rem, TreeNode* root){
        if(!root) return;
        if(root->left) inorder(rem, root->left);
        rem.push_back(root->val);
        if(root->right) inorder(rem, root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> rem;
        inorder(rem, root);
        for(int i=0; i<rem.size()-1; i++)
            if(rem[i] >= rem[i+1])
                return false;

        return true;
    }
};