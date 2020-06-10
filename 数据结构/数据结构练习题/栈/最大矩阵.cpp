class Solution {
public:
    int getMax(vector<int> heights){
        stack<int> st;
        int n = heights.size();
        int ret = 0;
        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.top() != -1 && heights[st.top()] > heights[i]){
                int tmp = st.top(); st.pop();
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int ret = 0;
        vector<vector<int>> hs(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<matrix[0].size(); i++) hs[0][i] = matrix[0][i] == '1' ? 1 : 0;
        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '0')  hs[i][j] = 0;
                else hs[i][j] = hs[i-1][j] + 1;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            ret = max(ret, getMax(hs[i]));
        }
        return ret;
    }
};