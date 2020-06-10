class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        int ret = 0;
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && heights[st.top()] > heights[i]){
                int tmp = st.top();  st.pop();
                ret = max(ret, heights[tmp]*(i-1-st.top()));
            }
            st.push(i);
        }
        while(st.top() != -1){
            int tmp = st.top(); st.pop();
            ret = max(ret, heights[tmp]*(n-1-st.top()));
        }
        return ret;
    }
};