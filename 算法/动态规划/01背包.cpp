#include <iostream>
using namespace std;

int n, w;
int c[maxn], v[maxn];//c为费用，v为价值
int dp[maxn][maxw];

int main()
{
    scanf("%d %d", &w, &n);//w为最大费用，n为数量
    for(int i = 1;i <= n;i++)
    {
        scanf("%d %d", &c[i], &v[i]);//输入，注意这里的下标是从1开始的
    }
    memset(dp, 0, sizeof(dp));//若不涉及多组输入，这一步其实可以省略
    //如果下标从0开始，下面也需要稍作修改
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= w;j++)
        {
            if(c[i] > j)
                dp[i][j] = dp[i - 1][j];//状态转移，情况①
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + v[i]);//情况②
        }
    }
    printf("%d\n", dp[n][w]);
}

/* 空间优化
int c[maxn], v[maxn];//c为费用，v为价值
int dp[maxw];
//其余部分略
for(int i = 1;i <= n;i++)
{
    for(int j = w;j >= c[i];j--)
    //这里要反着更新，否则dp[j - c[i]]会比dp[j]先更新，而更新后它对应的就不是i - 1时的状态了
    {
        dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    }
}
*/