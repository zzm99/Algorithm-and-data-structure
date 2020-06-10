/*
题目描述
在一个长方形框子里，最多有N（0≤N≤6）个相异的点，在其中任何一个点上放一个很小的油滴，那么这个油滴会一直扩展，直到接触到其他油滴或者框子的边界。必须等一个油滴扩展完毕才能放置下一个油滴。那么应该按照怎样的顺序在这N个点上放置油滴，才能使放置完毕后所有油滴占据的总体积最大呢？（不同的油滴不会相互融合）

注：圆的面积公式V=pi*r*r，其中r为圆的半径。

输入格式
第1行一个整数N。

第2行为长方形边框一个顶点及其对角顶点的坐标，x,y,x’,y’。

接下去N行，每行两个整数xi,yi，表示盒子的N个点的坐标。

以上所有的数据都在[-1000，1000]内。

输出格式
一行，一个整数，长方形盒子剩余的最小空间（结果四舍五入输出）
*/

// dfs

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=10;
const double PI=3.1415926535;
bool s[maxn];
double x[maxn],y[maxn],r[maxn],xa,ya,xb,yb,ansmax;
int n;
double cal(int i)
{
    double s1=min(abs(x[i]-xa),abs(x[i]-xb));
    double s2=min(abs(y[i]-ya),abs(y[i]-yb));
    double ans=min(s1,s2);
    for(int j=1;j<=n;j++)
    if(i!=j&&s[j])
    {
        double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        ans=min(ans,max(d-r[j],0.0));
    }
    return ans;
}
void dfs(int k,double sum)
{
    if(k>n)
    {
        ansmax=max(ansmax,sum);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!s[i])
        {
            r[i]=cal(i);
            s[i]=1;
            dfs(k+1,sum+r[i]*r[i]*PI);
            s[i]=0;
        }
    }
}
int main()
{
    double ss;
    scanf("%d",&n);
    scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
    ss=abs(xa-xb)*abs(ya-yb); 
    for(int i=1;i<=n;i++)
    scanf("%lf%lf",&x[i],&y[i]);
    dfs(1,0);
    printf("%d",int(ss-ansmax+0.5));
    return 0;
}