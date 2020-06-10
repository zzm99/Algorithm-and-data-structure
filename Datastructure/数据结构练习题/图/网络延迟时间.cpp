class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> gh(N+1, vector<int>(N+1, 9999999));
        for(auto& t: times){
            gh[t[0]][t[1]] = t[2];
        }
        vector<bool> visited(N+1, false);
        vector<int> distostart = gh[K];
        visited[K] = true;
        for(int i=1; i<N; i++){
            int minDis = 9999999, minIndex = 0;
            for(int j=1; j<=N; j++){
                if(!visited[j] && distostart[j] < minDis){
                    minDis = distostart[j];
                    minIndex = j;
                }
            }
            visited[minIndex] = true;
            for(int j=1; j<=N; j++){
                if(distostart[j] > distostart[minIndex] + gh[minIndex][j]){
                    distostart[j] = distostart[minIndex] + gh[minIndex][j];
                }
            }
        }
        int ans = 0;
        for(int i=1; i<distostart.size(); i++){
            if(ans < distostart[i] && i != K) ans = distostart[i];
        }
        if(ans == 9999999) return -1;
        return ans;
    }
};