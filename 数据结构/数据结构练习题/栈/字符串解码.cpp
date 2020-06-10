class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        int num = 0;
        stack<int> numstack;
        stack<string> strstack;
        string cur = "";
        for(int i=0; i<len; i++){
            if(s[i]>='0'&&s[i]<='9') num = 10*num+s[i]-'0';
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) cur += s[i];
            else if(s[i]=='['){
                numstack.push(num);
                strstack.push(cur);
                num = 0;
                cur.clear();
            }
            else if(s[i] == ']')
            {
                int k = numstack.top();
                string curtop = strstack.top();
                strstack.pop();
                numstack.pop();
                for(int j=0; j<k; ++j)
                    curtop += cur;
                cur = curtop;
            }
        }
        return cur; 
    }
};