// https://leetcode-cn.com/problems/inter-node-access-lcci/
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<int> visited(n);
        unordered_set<int> gh[n];
        for(auto& g: graph){
            gh[g[0]].insert(g[1]);
        }
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int cur = q.front(); q.pop();
                visited[cur] = 1;
                if(cur == target) return true;
                for(auto& j: gh[cur]){
                    if(visited[j] == 0) q.push(j);
                }
            }
        }
        return false;
    }
};