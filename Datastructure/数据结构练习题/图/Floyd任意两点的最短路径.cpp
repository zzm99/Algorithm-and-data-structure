void floyd(vector<vector<int>> &graph, int N){
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            //前两层for循环用于穷举graph[i][j],任意两点i、j之间的距离
            for (int k = 1; k <= N; ++k){
                //第三层for循环用于穷举中间稀疏节点
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
