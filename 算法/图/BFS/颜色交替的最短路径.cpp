// https://leetcode-cn.com/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ret(n, INT_MAX);
        ret[0] = 0;
        vector<int> redgh[n];
        vector<int> bluegh[n];
        for(auto& red: red_edges) redgh[red[0]].push_back(red[1]);
        for(auto& blue: blue_edges) bluegh[blue[0]].push_back(blue[1]);
        queue<pair<int, int>> q; 
        q.push({0, 0}); q.push({0, 1});
        vector<vector<int>> visited(n, vector<int>(2));
        int tmp = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++) {
                int cur = q.front().first, color = q.front().second; 
                q.pop();
                if(color == 0) {
                    for(auto& j: bluegh[cur]){
                        if(visited[j][0] == 1) continue;
                        ret[j] = min(ret[j], tmp);
                        q.push({j, 1});
                        visited[j][0] = 1;
                    }
                } else {
                    for(auto& j: redgh[cur]){
                        if(visited[j][1] == 1) continue;
                        ret[j] = min(ret[j], tmp);
                        q.push({j, 0});
                        visited[j][1] = 1;
                    }
                }
            }
            tmp++;
        }
        for(int i=1; i<n; i++) if(ret[i] == INT_MAX) ret[i] = -1;
        return ret;
    }
};