class Solution {
public:
    int toint(string n){
        stringstream ss;
        ss << n;
        int cur;
        ss >> cur;
        return cur;
    }
    int check(char c){
        return c >= '0' && c <= '9';
    }
    int eva(int c1, int c2, string cc){
        if(cc == "+") return c1 + c2;
        if(cc == "-") return c1 - c2;
        if(cc == "*") return c1 * c2;
        if(cc == "/") return c1 / c2;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nibo;
        for(auto s: tokens){
            if(check(s[0])||(s.size()>1 && s[0]=='-')){
                int cur = toint(s);
                nibo.push(cur);
            }else{
                int c1 = nibo.top(); nibo.pop();
                int c2 = nibo.top(); nibo.pop();
                int re = eva(c2, c1, s);
                nibo.push(re);
            }
        }
        return nibo.top();
    }
};