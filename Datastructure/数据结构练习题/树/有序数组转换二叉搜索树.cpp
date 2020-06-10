class Solution {
public:
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int mid = l + ((r-l)>>1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid-1);
        root->right = helper(nums, mid+1, r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);    
    }
};