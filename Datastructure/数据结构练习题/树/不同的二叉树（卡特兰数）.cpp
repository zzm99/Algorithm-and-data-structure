// 列出可能数目：
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=i; j++)
                dp[i] += dp[j-1]*dp[i-j];
         
        return dp[n];
    }
};

// 列出所有可能：
class Solution {
public:
    vector<TreeNode*> helper(int l, int r){
        vector<TreeNode*> ans;
        if(l > r) {
            ans.push_back(NULL);
            return ans;
        }
        for(int i=l; i<= r; i++){
            vector<TreeNode*> leftnode = helper(l, i-1);
            vector<TreeNode*> rightnode = helper(i+1, r);
            for(auto a: leftnode){
                for(auto b: rightnode){
                    TreeNode* t = new TreeNode(i);
                    t->left = a;
                    t->right = b;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n!=0) return helper(1, n);
        return ret;
    }
};