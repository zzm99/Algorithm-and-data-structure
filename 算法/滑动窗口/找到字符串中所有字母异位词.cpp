// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()==0 || p.size()==0 || p.size()>s.size()) return {};
        vector<int> ret;
        unordered_map<char, int> mp;
        for(auto& c: p) mp[c]++;
        int i=0, j=0, cnt = p.size();
        while(j < s.size()){
            if(mp[s[j]] > 0) cnt--;
            if(cnt == 0) ret.push_back(i);
            mp[s[j]]--;
            j++;
            if(j-i == p.size()){
                if(mp[s[i]]>=0) cnt++;
                mp[s[i]]++;
                i++;
            }
        }
        return ret;
    }
};