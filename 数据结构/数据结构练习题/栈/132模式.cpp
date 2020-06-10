// 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

// 注意：n 的值小于15000。

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int i=0, j=0, k=0;
        int n = nums.size();
        while(i < n){
            while(i < n-1 && nums[i]>=nums[i+1]) i++;
            j = i+1;
            while(j < n-1 && nums[j]<=nums[j+1]) j++;
            k = j+1;
            while(k<n){
                if(nums[j] > nums[k] && nums[i] < nums[k]) return true;
                k++;
            }
            i = j+1;
        }
        return false;
    }
};


//////////////////////////

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> minn(nums.size(), 0);
        if(nums.size() < 3) return false;
        minn[0] = INT_MAX;
        minn[1] = nums[0];
        for(int i=2; i<nums.size(); i++)
            minn[i] = min(minn[i-1], nums[i-1]);
        for(int i=1; i<nums.size(); i++){
            int mm = minn[i];
            int kk = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] < kk && nums[j] > mm) return true;
            }
        }
        return false;
    }
};