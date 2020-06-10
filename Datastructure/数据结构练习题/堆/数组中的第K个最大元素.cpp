class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums, k);
        int len = nums.size();
        for(int i=k; i<len; i++){
            if(nums[i] > nums[0]){
                swap(nums[i], nums[0]);
                heapAdjust(nums, 0, k);
            }
        }
        return nums[0];
    }
    void swap(int & a, int & b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void heapSort(vector<int> & nums, int len){
        for(int i = len / 2 - 1; i >= 0; --i)
            heapAdjust(nums, i, len);
    }
    void heapAdjust(vector<int> & nums, int k, int len){
        int lch = k * 2 + 1, rch = 2 * k + 2;
        if(lch >= len) return;
        int p = lch; 
        if(rch < len && nums[lch] > nums[rch]) p = rch;
        if(nums[k] <= nums[p]) return; 
        swap(nums[k], nums[p]); 
        heapAdjust(nums, p, len);
    }
};