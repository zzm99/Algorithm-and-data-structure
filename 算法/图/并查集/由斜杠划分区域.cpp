// https://leetcode-cn.com/problems/regions-cut-by-slashes/
class Solution {
public:
    class UnionFind {
        public:
            vector<int> parent;
            UnionFind(int size) {
                parent.resize(size);
                for(int i=0; i<parent.size(); i++)
                    parent[i] = i;
            }
            int find(int p) {
                while(p != parent[p]) {
                    parent[p] = parent[parent[p]];
                    p = parent[p];
                }
                return parent[p];
            }
            void merge(int p, int q) {
                int rp = find(p), rq = find(q);
                parent[rp] = rq;
            }
    };
    int regionsBySlashes(vector<string>& grid) {
        int len = grid.size();
        UnionFind* uf = new UnionFind(4*len*len);
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                int start = 4*(i*len+j);
                if(grid[i][j] == ' ') {
                    uf->merge(start, start+1);
                    uf->merge(start+2, start+3);
                    uf->merge(start, start+2);
                } else if(grid[i][j] == '/') {
                    uf->merge(start, start+3);
                    uf->merge(start+1, start+2);
                } else if(grid[i][j] == '\\') {
                    uf->merge(start, start+1);
                    uf->merge(start+2, start+3);
                }
                if(i > 0) {
                    uf->merge(start, start-4*len+2);
                }
                if(j > 0) {
                    uf->merge(start+3, start-3);
                }
            }
        }
        int count = 0;
        for(int i=0; i<uf->parent.size(); i++) {
            if(i == uf->parent[i])
                count++;
        }
        return count;
    }
};