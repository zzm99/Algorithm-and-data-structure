// 输入: [1,2,1]
// 输出: [2,-1,2]
// 解释: 第一个 1 的下一个更大的数是 2；
// 数字 2 找不到下一个更大的数； 
// 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int N = nums.size();
        vector<int> res(N, -1);
        stack<int> st;
        for (int i = 0, k = 0; k < 2;) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
            i = (i + 1) % N;
            k += i == N - 1;
        }
        return res;
    }
};