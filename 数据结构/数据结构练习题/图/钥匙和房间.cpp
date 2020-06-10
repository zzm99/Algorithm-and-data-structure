class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int curid, vector<int>& visited){
        if(visited[curid] == 1) return;
        visited[curid] = 1;
        for(int i=0; i<rooms[curid].size(); i++){
            dfs(rooms, rooms[curid][i],visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        dfs(rooms, 0, visited);
        for(int i=0; i<visited.size(); i++)
            if(visited[i] == 0) return false;
        return true;
    }
};