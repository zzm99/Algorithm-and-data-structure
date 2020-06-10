// 二叉搜索树中的两个节点被错误地交换。

// 请在不改变其结构的情况下，恢复这棵树。

// 中序遍历，结果中如果有一个降序对，说明该两个node需交换；若有两个降序对，说明第一对的前一个node和第二对的后一个node需要交换。
class Solution {
public:
    TreeNode *pre, *first, *second;
    void helper(TreeNode* root){
        if(!root) return;
        helper(root->left);
        if(pre == NULL){
            pre = root;
        }else{
            if(pre->val > root->val){
                if(first == NULL)
                    first = pre; 
                second = root;
            }
            pre = root;
        }
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        helper(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};