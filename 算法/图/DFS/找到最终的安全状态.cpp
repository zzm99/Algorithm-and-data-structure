// https://leetcode-cn.com/problems/find-eventual-safe-states/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        vector<int> ret;
        for(int i=0; i<n; i++)
            if(dfs(graph, color, i)) 
                ret.push_back(i);
        return ret;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int id){
        if(color[id]) return color[id] == 2; // 1: bad ; 2 : good ;
        color[id] = 1;
        for(int i=0; i<graph[id].size(); i++){
            if(color[graph[id][i]] == 1 || !dfs(graph, color, graph[id][i]))
                return false;
        }
        color[id] = 2;
        return true;
    }
};