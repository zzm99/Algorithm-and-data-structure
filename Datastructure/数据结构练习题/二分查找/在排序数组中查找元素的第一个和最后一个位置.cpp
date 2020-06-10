class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        int n = nums.size(); 
        int l = 0, r = n-1;
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] >= target) r = m;
            else l = m+1;
        }
        if(nums[l] != target) return res;
        res[0] = l;
        r = n; // [1]; 1
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] <= target) l = m+1;
            else r = m;
        }
        res[1] = l-1;
        return res;
    }
};