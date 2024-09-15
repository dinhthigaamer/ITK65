#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1e9+7;

int n,m;
vector<int> g[1505];
int res[5005];
ll f[1505][1505],cnt_A[1505],cnt_B[1505];
int topo[100010],p1;
int used[1505];

struct Edge
{
   int u,v,w;
}edges[5005];

void dijkstra(int id)
{
    p1=0;
    for(int i=1;i<=n;++i) f[id][i]=1e9;
    f[id][id]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,id});

    while(q.size())
    {
        int u=q.top().second;
        int lab=q.top().first;
        q.pop();
        if(lab!=f[id][u]) continue;
        topo[++p1]=u;
        for(int i:g[u])
        {
            int v=edges[i].v;
            int w=edges[i].w;
            if(f[id][v]>f[id][u]+w)
            {
                f[id][v]=f[id][u]+w;
                q.push({f[id][v],v});
            }
        }
    }
}

void solve()
{
    for(int u=1;u<=n;++u)
    {
        memset(cnt_A,0,sizeof(cnt_A));
        memset(cnt_B,0,sizeof(cnt_B));
        dijkstra(u);

        for(int i=1;i<=n;++i) cnt_B[i]=1;
        for(int i=1;i<=p1;++i)
        {
            int x=topo[i];
            if(x==u) cnt_A[x]=1;
            for(int id:g[x])
            {
                int v=edges[id].v , w=edges[id].w;
                if(f[u][v]==f[u][x]+w)
                {
                    cnt_A[v]=(cnt_A[x]+cnt_A[v])%mod;
                }
            }
        }

        for(int i=p1;i>=1;--i)
        {
            int x=topo[i];
            //if(x==u) cnt_B[x]=1;
            for(int id:g[x])
            {
                int v=edges[id].v , w=edges[id].w;
                if(f[u][v]==f[u][x]+w)
                {
                    cnt_B[x]=(cnt_B[x]+cnt_B[v])%mod;
                }
            }
        }

        /*for(int i=1;i<=p1;++i) cout<<topo[i]<<' ';cout<<endl;
        for(int i=1;i<=n;++i) cout<<cnt_A[i]<<' ';cout<<endl;
        for(int i=1;i<=n;++i) cout<<cnt_B[i]<<' ';cout<<endl<<endl;*/
        for(int i=1;i<=m;++i)
        {
            int u1=edges[i].u , v1=edges[i].v , w=edges[i].w;
            if(f[u][v1]==f[u][u1]+w)
            {
                res[i]=(res[i]+cnt_A[u1]*cnt_B[v1]%mod)%mod;
            }
        }
    }
    for(int i=1;i<=m;++i) cout<<res[i]<<'\n';
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,w};
        g[u].push_back(i);
    }

    solve();
    return 0;
}