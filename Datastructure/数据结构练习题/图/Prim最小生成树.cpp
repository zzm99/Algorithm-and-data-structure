#include <iostream>
#include <vector>
#define Inf 0x7fffffff
using namespace std;
int main()
{
    int n,m;//节点个数和边数
    cin>>n>>m;//输入节点个数和边数;
    vector<vector<int>> v(n+1,vector<int>(n+1,Inf));//邻接矩阵
    for(int i=0;i<m;++i)
    {
        int s,e,w;
        cin>>s>>e>>w;
        v[s][e]=v[e][s]=w;
    }
    int s=1,sumcost=0;//开始收录的节点,累计最小花费
    vector<int> cost=v[s];
    vector<bool> vis(n+1,false);//是否已经收录
    vis[s]=true;
    for(int k=1;k<n;++k)
    {
        int mincost=Inf,u=-1;
        for(int i=1;i<=n;++i) if(!vis[i]&&cost[i]<mincost) mincost=cost[u=i];
        sumcost+=mincost;
        vis[u]=true;
        for(int i=1;i<=n;++i) if(!vis[i]&&cost[i]>v[i][u]) cost[i]=v[i][u];
    }
    cout<<sumcost;
    return 0;
}