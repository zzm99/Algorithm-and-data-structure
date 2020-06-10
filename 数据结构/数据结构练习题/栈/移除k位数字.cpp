// 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

// 单调栈算法
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto c : num){
            while(!st.empty() && st.top() > c && k > 0){
                k--;
                st.pop();
            }
            if(st.empty() && c == '0') continue;
            st.push(c);
        }
        while(!st.empty() && k > 0){
            st.pop(); k--;
        }
        string res;
        while(!st.empty()){
            res += st.top(); st.pop();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
