// https://leetcode-cn.com/contest/weekly-contest-178/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int inf = 0x3f3f3f3f;
        vector<vector<int> > cost(n, vector(m, inf));
        cost[0][0] = 0;
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int x = cur.first, y = cur.second, tx, ty;
            for (int i = 1; i <= 4; ++i) {
                tx = x, ty = y;
                if (i == 1) ty++;
                else if (i == 2) ty--;
                else if (i == 3) tx++;
                else tx--;
                
                if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
                    int extra = i != grid[x][y];
                    if (cost[tx][ty] > extra + cost[x][y]) {
                        cost[tx][ty] = extra + cost[x][y];
                        Q.push({tx, ty});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};