// https://leetcode-cn.com/problems/as-far-from-land-as-possible
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int maxDis = 0;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        if(q.size() == 0 || q.size() == n*m) return -1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int x = q.front().first, y = q.front().second; q.pop();
                for(int z=0; z<4; z++){
                    int nx = x + dx[z], ny = y + dy[z];
                    if(nx < 0 || ny < 0 || nx == n || ny == m) continue;
                    if(grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            maxDis++;
        }
        return maxDis-1; 
    }
};