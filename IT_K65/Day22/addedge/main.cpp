#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define MAX 200005

int n,m;
vector<pair<int,int> > g[MAX];
int Time;
stack<int> st;
int low[MAX],num[MAX];
int type[MAX];
int cnt;

void dfs(int u,int cha)
{
   st.push(u);
   low[u]=num[u]=++Time;
   for(auto i:g[u])
   {
       int v=i.fi;
       int xx=i.se;
       if(v==cha || type[v]) continue;
       if(num[v]) low[u]=min(low[u],num[v]);
       else
       {
           if(xx==1) dfs(v,0);
           else dfs(v,u);
           low[u]=min(low[u],low[v]);
       }
   }
   if(low[u]==num[u])
   {
       ++cnt;
       int v=0;
       while(v!=u)
       {
           v=st.top(); st.pop();
           type[v]=cnt;
       }
   }
}

int la;
vector<int> vec[MAX];
int used[MAX];

void dfs2(int u)
{
    la+=(vec[u].size()==1);
    used[u]=1;
    for(int v:vec[u]) if(!used[v]) dfs2(v);
}

pair<int,int> U[MAX];

int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;++i)
    {
        cin>>U[i].fi>>U[i].se;
        if(U[i].fi==U[i].se) {--i ; --m; continue;}
        if(U[i].fi>U[i].se) swap(U[i].fi,U[i].se);
    }

    sort(U+1,U+m+1) ; U[0]=U[m+1]={0,0};

    for(int i=1;i<=m;++i) if(U[i]!=U[i-1])
    {
        if(U[i]==U[i+1])
        {
            g[U[i].fi].push_back({U[i].se,1});
            g[U[i].se].push_back({U[i].fi,1});
        }
        else
        {
            g[U[i].fi].push_back({U[i].se,0});
            g[U[i].se].push_back({U[i].fi,0});
        }
    }

    for(int i=1;i<=n;++i) if(!num[i]) dfs(i,0);

    for(int i=1;i<=m;++i) if(type[U[i].fi]!=type[U[i].se])
    {
        int u=type[U[i].fi] , v=type[U[i].se];
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int res=0;
    for(int i=1;i<=cnt;++i) if(!used[i])
    {
        la=0;
        dfs2(i);
        res+=(la+1)/2;
    }
    cout<<res<<endl;
    return 0;
}