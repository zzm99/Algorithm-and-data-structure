class Solution {
public:
    void dfs(vector<vector<int>>& M, int i, int j){
        M[i][j] = 0;
        for(int z=0; z<M[0].size(); z++){
            if(M[j][z] == 1) dfs(M, j, z);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans = 0;
        for(int i=0; i<M.size(); i++){
            for(int j=0; j<M[0].size(); j++){
                if(M[i][j] == 0) continue;
                ans++;
                dfs(M, i, j);
            }
        }
        return ans;
    }
};
