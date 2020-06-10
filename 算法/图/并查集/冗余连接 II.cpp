// https://leetcode-cn.com/problems/redundant-connection-ii/
/*
有根树（有向图）的并查集：
1. 有入度为2的点：记录对应的两条边：
	遍历-构建并查集：忽略后面那条边，若剩余的边构成环：返回第一条边
									若剩余的边不构成环： 返回第二条边
2. 无入度为2的点：正常并查集
*/
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int from[n+1] = {};
        int ind2 = 0, from1 = 0, from2 = 0;
        for (auto &e : edges) { // 试图找入度为2的点
            if (from[e[1]]) {
                ind2 = e[1];
                from1 = from[e[1]];
                from2 = e[0];
                break;
            } 
            from[e[1]] = e[0];
        }
        vector<int> p(n+1); 
        for (int i = 1; i <= n; ++i) p[i] = i;
        for (auto &e : edges) {
            if (from2 == e[0] && ind2 == e[1])
                continue;
            int p1 = find(p, e[0]), p2 = find(p, e[1]);
            if (p1 == p2) 
                return ind2 ? vector<int>{from1, ind2} : e;
            p[p1] = p2;
        }
        return {from2, ind2};
    }
    int find(vector<int> &p, int n) {
        return p[n] == n ? n : p[n] = find(p, p[n]);
    }
};
