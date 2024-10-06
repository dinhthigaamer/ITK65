#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
int n;
vector<int> g[MAX];
int f1[MAX],f2[MAX];
pair<int,int> best[MAX];

void dfs1(int u,int cha)
{
    f1[u]=1;
    for(int v:g[u]) if(v!=cha)
    {
        dfs1(v,u);

        if(f1[v]+1>best[u].first) {swap(best[u].first,best[u].second); best[u].first=f1[v]+1;}
        else
        best[u].second=max(best[u].second,f1[v]+1);
        f1[u]=best[u].first;
    }

}

void dfs2(int u,int cha)
{
    for(int v:g[u]) if(v!=cha)
    {
        f2[v]=max(best[v].second,f2[u]+1);
        if(f1[v]+1==f1[u]) f2[v]=max(f2[v],best[u].second+1);
        else
        f2[v]=max(f2[v],f1[u]+1);
        dfs2(v,u);
    }
}

int main()
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    cin>>n;
    for(int u,v,i=1;i<n;++i)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i) best[i]={1,1};
    f2[1]=1;
    dfs1(1,1);
    dfs2(1,1);
    //for(int i=1;i<=n;++i) cout<<f1[i]<<' '<<f2[i]<<endl;
    int res=1e9;
    for(int i=1;i<=n;++i) res=min(res,max(f1[i],f2[i]));

    vector<int> vec;
    for(int i=1;i<=n;++i) if(max(f1[i],f2[i])==res) vec.push_back(i);
    cout<<vec.size()<<endl;
    sort(vec.begin(),vec.end());
    for(int it:vec) cout<<it<<' ';
    return 0;
}