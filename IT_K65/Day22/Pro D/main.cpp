#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005

long long q[maxn];
int n,m;
pair<long long,pair<int,int> > line[maxn];

struct data
{
    long long  r[maxn];

    void getnew()
    {
        for(int i=1;i<=n;++i) r[i]=-1;
    }

    int getr(int u)
    {
        return r[u]<0?u:getr(r[u]);
    }

    void add(int u,int v,long long w)
    {
        if((u=getr(u))==(v=(getr(v)))) return;
        if(r[u]>r[v]) swap(u,v);
        q[w]+=r[u]*r[v];
        r[u]+=r[v];
        r[v]=u;
    }
}dsu;

int main()
{
    cin>>n>>m;
    for(int i=1;i<n;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        line[i]={w,{u,v}};
    }

    dsu.getnew();

    memset(q,0,sizeof(q));
    sort(line+1,line+n);
    for(int i=1;i<n;++i)
    {
        long long  w=line[i].first;
        int u=line[i].second.first;
        int v=line[i].second.second;
        dsu.add(u,v,w);
    }

    for(int i=1;i<=1e6;++i) q[i]+=q[i-1];

    for(int i=1;i<=m;++i)
    {
        int m1;
        cin>>m1;
        cout<<q[m1]<<" ";
    }
}