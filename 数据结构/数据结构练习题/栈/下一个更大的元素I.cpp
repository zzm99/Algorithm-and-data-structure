// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
// 解释:
//     对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
//     对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
//     对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int> stack;

        for(int value: nums1) {
            mp[value] = -1;
        }
        
        for(int i=0;i<nums2.size();i++) {
            while (!stack.empty()&&stack.top()<nums2[i]) {
                mp[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++) {
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};