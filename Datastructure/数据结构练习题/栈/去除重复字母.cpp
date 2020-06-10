// 给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(128, 0);
        vector<bool> visited(128, false);
        for(char x: s) hash[x]++;
        string result = "0";
        for(char x: s){
            hash[x]--;
            if(visited[x]) continue;
            while(x < result.back() && hash[result.back()]){
                visited[result.back()] = false;
                result.pop_back();
            }
            result += x;
            visited[x] = true;
        }
        return result.substr(1);
    }
};