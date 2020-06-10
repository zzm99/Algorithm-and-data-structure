// https://leetcode-cn.com/problems/remove-invalid-parentheses/
class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int left=0;
        int right=0;
        for(char i:s){
            if(i=='(') left++;
            if(i==')'){
                if(left>0)left--;
                else right++;
            }
        }
        dfs(s, 0, left, right);
        return ans;
    }
    void dfs(string s, int st, int l, int r){
        if(l==0&&r==0){
            if(check(s))  ans.push_back(s);
            return;
        }
        for(int i=st;i<s.size();i++){
            if(i-1>=st&&s[i]==s[i-1])continue;
            if(l>0&&s[i]=='('){
                dfs(s.substr(0, i)+s.substr(i+1, s.size()-i-1), i, l-1, r);
            }
            if(r>0&&s[i]==')'){
                dfs(s.substr(0, i)+s.substr(i+1, s.size()-i-1), i, l, r-1);
            }
        }
    }
    bool check(string s){
        int cnt=0;
        for(char i:s){
            if(i=='(') cnt++;
            if(i==')'){
                cnt--;
                if(cnt<0)return false;
            }
        }
        return cnt==0;
    }
};