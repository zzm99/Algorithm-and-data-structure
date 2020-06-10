// https://leetcode-cn.com/problems/find-eventual-safe-states/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto& j: graph[i]){
                adj[j].push_back(i);
                ++indegree[i];
            }
        }
        queue<int> q;
        vector<int> issafe(n);
        for(int i=0; i<n; i++)
            if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            issafe[cur] = 1;
            for(auto i: adj[cur]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        vector<int> ret;
        for(int i=0; i<n; i++)
            if(issafe[i]) ret.push_back(i);
        return ret;
    }
};