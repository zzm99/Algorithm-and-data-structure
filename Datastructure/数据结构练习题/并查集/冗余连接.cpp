class Solution {
public:
    const static int MAXN = 1001;
    int parent[MAXN+1];
    int size[MAXN+1];

    void UF(int n){ 
        for(int i=0; i<=n+1; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int p){
        while(parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return parent[p];
    }

    void myunion(int p, int q){
        int pp = find(p);
        int pq = find(q);
        // 因为这个集合实质上是用树实现的，为了避免树过于不平衡，因此将节点少的树加入到节点多的树中
        if(size[pp] > size[pq]){
            parent[pq] = parent[pp];
            size[pp] += size[pq];
        }else{
            parent[pp] = parent[pq];
            size[pq] += size[pp];
        }
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int a, b;
        UF(n);
        for(int i=0; i<n; i++){
            a = edges[i][0];
            b = edges[i][1];
            if(connected(a, b)) return {a, b};
            myunion(a, b);
        }
        return {};  // 这一步实际不会执行 
    }
};