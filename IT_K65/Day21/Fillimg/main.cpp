#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
#define ll long long

constexpr int mod=1e9+7;
int n,k;
int f[MAX];
vector<int> g[MAX];
int low[MAX],num[MAX],Time;
int m,p;
stack<int> st;
int ok[MAX],dd[MAX];
int res;

void dfs(int u,int cha)
{
    st.push(u);
    low[u]=num[u]=++Time;

    for(int v:g[u]) if(!dd[v])
    {
        if(num[v])
        {
            low[u]=min(low[u],num[v]);
            continue;
        }
        dfs(v,u);
        low[u]=min(low[u],low[v]);
    }
    if(low[u]==num[u])
    {
        int cnt=0;
        int v;
        do
        {
            v=st.top();//cout<<v<<' ';
            dd[v]=1;
            ++cnt;
            st.pop();
        }while(v!=u);//cout<<endl;

        if(cnt==1)
        {
            if(ok[u]) res=1ll*res*k%mod;
            else res=1ll*res*(k-1)%mod;
        }
        else
            res=1ll*res*f[cnt]%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin>>n>>k;

    f[1]=k; f[2]=1ll*k*(k-1)%mod;
    int tg=k-1;

    for(int i=3;i<=n;++i)
    {
        tg=1ll*tg*(k-1)%mod;
        f[i]=1ll*k*tg%mod - f[i-1];
        if(f[i]<0) f[i]+=mod;
    }
    for(int i=1;i<=n;++i)
    {
        int u;
        cin>>u;
        ok[i]=(u==i);
        if(u==i) continue;
        g[i].push_back(u);
    }

    res=1;
    for(int i=1;i<=n;++i) if(!num[i])
    {
        dfs(i,i);
    }
    cout<<res<<endl;
    return 0;
}