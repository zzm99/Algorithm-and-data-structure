#include <iostream>
#include <vector>
#include <algorithm>
#define Inf 0x7fffffff
using namespace std;
struct node
{
    int u,v;
    int w;
    node(int a,int b,int x):u(a),v(b),w(x){}
};
vector<node> edge;
int vn,an;
int pa[1000];
bool cmp(const node &a,const node &b)
{
    return a.w<b.w;
}
int find(int x)
{
    return x==pa[x]?x:pa[x]=find(pa[x]);
}
int kruskal()
{
    int sumw=0,cnt=0;
    for(int i=1;i<=vn;++i) pa[i]=i;
    for(int i=0;i<an;++i)
    {
        int x=find(edge[i].u),y=find(edge[i].v);
        if(x!=y)
        {
            pa[x]=y;
            sumw+=edge[i].w;
            ++cnt;
        }
        if(cnt==vn-1) break;
    }
    return sumw;
}
int main()
{
    cin>>vn>>an;
    for(int i=0;i<an;++i)
    {
        int a,b,x;
        cin>>a>>b>>x;
        edge.push_back(node(a,b,x));
    }
    sort(edge.begin(),edge.end(),cmp);
    cout<<kruskal();
    return 0;
}