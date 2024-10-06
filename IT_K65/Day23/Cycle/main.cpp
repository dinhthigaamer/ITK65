#include<bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> Edge[6006];
int cnt[3005],f[3005];
vector<int> g[3005];

void bfs(int banned)
{
    queue<int> q;
    for(int i=1;i<=n;++i) if(f[i]==1) q.push(i);
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int id:g[u]) if(id!=banned)
        {
            int v=Edge[id].first+Edge[id].second-u;
            if(f[v]>f[u]+1)
            {
                f[v]=f[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }
            else
            if(f[v]==f[u]+1) cnt[v]+=cnt[u];
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int u,v,i=1;i<=m;++i)
    {
        cin>>u>>v;
        Edge[i]={u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    int minlen=n , res=0;
    for(int i=1;i<=m;++i)
    {
        int u=Edge[i].first , v=Edge[i].second;
        for(int j=1;j<=n;++j) f[j]=1e9 , cnt[j]=0;
        cnt[u]=1; f[u]=1;
        bfs(i);
        if(f[v]<minlen)
        {
            minlen=f[v];
            res=cnt[v];
        }
        else
        if(f[v]==minlen)
        {
            res+=cnt[v];
        }
    }
    cout<<res/minlen<<endl;
    return 0;
}