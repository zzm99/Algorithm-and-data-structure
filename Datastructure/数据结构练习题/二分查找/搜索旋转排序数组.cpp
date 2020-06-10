// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }
    int helper(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            return max(helper(nums, target, left, mid-1), helper(nums, target, mid+1, right));
        }
        return -1;
    }
};

/////

class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int mid = left + (right-left)/2;

        while(left <= right){
            if(nums[mid] == target){
                return mid;
            }

            if(nums[left] <= nums[mid]){  //左边升序
                if(target >= nums[left] && target <= nums[mid]){//在左边范围内
                    right = mid-1;
                }else{//只能从右边找
                    left = mid+1;
                }

            }else{ //右边升序
                if(target >= nums[mid] && target <= nums[right]){//在右边范围内
                    left = mid +1;
                }else{//只能从左边找
                    right = mid-1;
                }

            }
            mid = left + (right-left)/2;
        }

        return -1;  //没找到
    }
}