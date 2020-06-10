class Solution {
public:
    TreeNode* build_Tree(vector<int>& inorder, vector<int>& postorder, int a, int b, int c, int d){
        if(a > b || c > d) return NULL;
        TreeNode* root = new TreeNode(postorder[d]);
        int i = a-1;
        while(i <= b && inorder[++i]!=postorder[d]);
        root->left = build_Tree(inorder, postorder, a, i-1, c, c+i-a-1);
        root->right = build_Tree(inorder, postorder, i+1, b, c+i-a, d-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build_Tree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};