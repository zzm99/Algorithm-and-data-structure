class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];
        int cou = 0;
        for(int i=0; i<nums.size(); i++){
            if(cou == 0){
                cou = 1; cur = nums[i];
            }else{
                if(nums[i] == cur) cou++;
                else cou--;
            }
        }
        return cur;
    }
};