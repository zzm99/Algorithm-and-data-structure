// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{') S.push(c);
            else{
                if(c == ')'){
                    if(!S.empty() && S.top()=='(') S.pop();
                    else return false;
                }else if(c == ']'){
                    if(!S.empty() && S.top()=='[') S.pop();
                    else return false;
                }else if(c == '}'){
                    if(!S.empty() && S.top()=='{') S.pop();
                    else return false;
                }
            }
        }
        return S.empty();
    }
};