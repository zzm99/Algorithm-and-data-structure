// https://leetcode-cn.com/problems/reconstruct-itinerary/
class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> airpots;
        for(auto v: tickets){
            string c1 = v[0], c2 = v[1];
            if(find(airpots.begin(), airpots.end(), c1) == airpots.end()) airpots.push_back(c1);
            if(find(airpots.begin(), airpots.end(), c2) == airpots.end()) airpots.push_back(c2);
        }
        sort(airpots.begin(), airpots.end());
        int n = airpots.size();
        for(int i=0; i<n; i++) mp[airpots[i]] = i;
        vector<vector<int>> gh(n, vector<int>(n));
        for(auto v: tickets){
            int from = mp[v[0]], to = mp[v[1]];
            gh[from][to]++;
        }
        vector<string> ret;
        vector<string> cur;
        int curid = mp["JFK"];
        dfs(gh, ret, curid);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void dfs(vector<vector<int>>& gh, vector<string>& ret, int i){
        for (int j = 0; j < gh.size(); ++j) {
            if (gh[i][j] > 0) {
                --gh[i][j];
                dfs(gh, ret, j);
            }
        }
        for(auto m: mp){
	        if(m.second == i){
	            ret.push_back(m.first);
	            break;
	        }
        }
    }
};