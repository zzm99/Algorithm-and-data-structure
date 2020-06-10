// 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

// 调用 next() 将返回二叉搜索树中的下一个最小的数。

// next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode*> S;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            S.push_back(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* t = S.back();
        S.pop_back();
        int val = t->val;
        t = t->right;
        while(t){
            S.push_back(t);
            t = t->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */