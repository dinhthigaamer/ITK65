#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define fi first
#define se second

int n,m;
int num[MAX],low[MAX],Time;
stack<int> st;
vector<int> g[MAX];
pair<int,int> E[MAX];
int tplt,type[MAX];
int par[MAX];
int f[MAX];
int used[MAX];

void dfs1(int u,int cha)
{
    st.push(u);
    num[u]=low[u]=++Time;
    for(int i:g[u]) if(!used[i])
    {
        used[i]=1;
        int v=E[i].fi+E[i].se-u;
        if(num[v])
        {
            low[u]=min(low[u],num[v]);
            continue;
        }
        dfs1(v,u);
        low[u]=min(low[u],low[v]);
    }

    if(low[u]==num[u])
    {
        ++tplt;
        int v=st.top();
        do
        {
            v=st.top();
            type[v]=tplt;
            st.pop();
        }while(v!=u);
    }
}

void dfs2(int u,int cha)
{
    for(int v:g[u]) if(v!=cha)
    {
        par[v]=u;
        dfs2(v,u);
        f[u]+=f[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        E[i]={u,v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    Time=0;
    for(int i=1;i<=n;++i) if(!num[i]) dfs1(i,i);
    //for(int i=1;i<=n;++i) cout<<type[i]<<' ';cout<<endl;
    for(int i=1;i<=n;++i) g[i].clear();

    for(int i=1;i<=m;++i)
    {
        int u=E[i].fi , v=E[i].se;
        u=type[u] ; v=type[v];
        if(u!=v)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    memset(par,0,sizeof(par));
    int q;
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        int u,v;
        cin>>u>>v;
        if(type[u]==type[v]) continue;
        u=type[u] ; v=type[v];
        f[u]+=1; f[v]-=1;
    }
    for(int i=1;i<=tplt;++i) if(!par[i]) dfs2(i,i);

    for(int i=1;i<=m;++i)
    {
        int u=E[i].fi , v=E[i].se;
        u=type[u] ; v=type[v];
        if(u==v) cout<<"B";
        else
        {
            if(par[u]==v)
            {
                if(f[u]==0) cout<<"B";
                else
                if(f[u]>0) cout<<"R";
                else
                cout<<"L";
            }
            else
            {
                if(f[v]==0) cout<<"B";
                else
                if(f[v]>0) cout<<"L";
                else
                cout<<"R";
            }
        }
    }
    return 0;
}