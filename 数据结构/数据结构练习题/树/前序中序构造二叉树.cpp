class Solution {
public:
    TreeNode* build_Tree(vector<int>& preorder, vector<int>& inorder, int a, int b, int c, int d){
        if(a > b || c > d) return NULL;
        TreeNode* root = new TreeNode(preorder[a]);
        int i = c-1;
        while(i <= d && inorder[++i]!=preorder[a]);
        root->left = build_Tree(preorder, inorder, a+1, a+i-c, c, i-1);
        root->right = build_Tree(preorder, inorder, a+i-c+1, b, i+1, d);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build_Tree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
