// 普通层次遍历： https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> out;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                out.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ret.push_back(out);
        }
        return ret;
    }
};

// 锯齿形层次遍历：
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            vector<int> out;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                out.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(flag % 2==1){
                reverse(out.begin(), out.end());
            }
            ret.push_back(out);
            flag++;
        }
        return ret;
    }
};