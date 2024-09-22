#include<bits/stdc++.h>
using namespace std;

#define MAX 100010

int n,q;
int a[MAX];
vector<int> g[MAX];
int in[MAX],out[MAX],pos[MAX],cnt;
int id[MAX],root[MAX];
int b[MAX];
int res[MAX];

struct query
{
    int type,u;
};

query qry[MAX];

void File()
{
    freopen("file.inp","r",stdin);
    freopen("file.out","w",stdout);
}

void Inp()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>qry[i].type>>qry[i].u;
    }
}

void dfs(int u,int cha)
{
    in[u]=++cnt;
    pos[cnt]=u;

    for(int v:g[u]) if(v!=cha)
    {
        dfs(v,u);    
    }

    out[u]=cnt;
}

void reorder_query()
{
    set<pair<int,int>> s;

    for(int i=1;i<=q;++i)
    {
        int u=qry[i].u;//cout<<u<<' '<<in[u]<<endl;
        
        while(s.size())
        {
            set<pair<int,int>>::iterator v=s.lower_bound({in[u],0});
            if(v==s.end()) break;
            if((*v).first<=out[u])
            {
                s.erase(v);
                continue;
            }
            break;
        }
        s.insert({in[u],i});
    }

    int cnt=0;
    vector<query> vec;

    for(pair<int,int> it:s)
    {
        vec.push_back(qry[it.second]);    
    }
    for(auto it:vec)
    {
        qry[++cnt]=it;
        //cout<<qry[cnt].type<<' '<<qry[cnt].u<<endl;
    }
    q=cnt;
}

//u in subtree v ??
int check(int v,int u)
{
    return (in[v]<=in[u] && in[u]<=out[v]);
}

void Sort(int type,int u)
{
    sort(b+in[u],b+out[u]+1);

    if(type==1)
    {
        id[in[u]]=1;
        id[out[u]]=out[u]-in[u]+1;
    }
    else 
    {
        id[in[u]]=out[u]-in[u]+1;
        id[out[u]]=1;
    }
}

void Solve()
{
    cnt=0;
    dfs(1,1);
    for(int u=1;u<=n;++u) b[in[u]]=a[u];

    /*for(int i=1;i<=n;++i) cout<<in[i]<<' '<<out[i]<<endl;
    cout<<endl;*/

    reorder_query();
    vector<pair<int,int>> st;

    for(int i=1;i<=q;++i)
    {
        int type=qry[i].type , u=qry[i].u; 
        //cout<<type<<' '<<u<<endl;
        
        while(st.size() && !check(st.back().first,u)) st.pop_back();

        if(st.empty())
        {
            Sort(type,u);
            root[u]=u;
            st.push_back({u,type});
        }
        else 
        {   
            int typ = st.back().second;
            int v=st.back().first;

            if(typ==1 && type==1) continue;
            if(typ==2 && type==2) continue;

            root[u]=root[v];

            if(typ==1 && type==2)
            {
                id[in[u]]=id[in[v]]+in[u]-in[v];
                id[out[u]]=id[in[v]]+out[u]-in[v];
                swap(id[in[u]],id[out[u]]);
            }    
            else
            if(typ==2 && type==1)
            {
                id[in[u]]=id[in[v]]-(in[u]-in[v]);
                id[out[u]]=id[in[v]]-(out[u]-in[v]);
                swap(id[in[u]],id[out[u]]);
            }

            st.push_back({u,type});
        }
    }
    //cout<<endl;
    for(int i=q;i>=1;--i)
    {
        int u=qry[i].u;
        int v=root[u];
        if(v==0) continue;

        int add=0;

        if(id[in[u]]>id[out[u]]) add=-1;
        else add=1;

        int st=id[in[u]];

        for(int j=in[u];j<=out[u];++j)
        {   //cout<<j<<' ';
            if(!res[pos[j]]) 
            {   
                res[pos[j]]=b[in[v]+st-1];
                st+=add;
            }
            else 
            {
                int k=pos[j];
                st=id[in[k]]+add;
                j=out[k];
            }
        }//cout<<endl;
        //for(int j=1;j<=n;++j) cout<<res[j]<<' ';cout<<endl;
    }

    for(int u=1;u<=n;++u)
    {
        if(res[u]) cout<<res[u]<<' ';
        else 
        cout<<a[u]<<' ';
    }
    cout<<endl;
}

void Brute_Force()
{
    cnt=0;
    dfs(1,1);
    //for(int i=1;i<=n;++i) cout<<in[i]<<' '<<out[i]<<endl;
    for(int i=1;i<=n;++i) b[in[i]]=a[i];

    for(int i=1;i<=q;++i)
    {
        int type=qry[i].type , u=qry[i].u;
        if(type==1) sort(b+in[u],b+out[u]+1);
        else sort(b+in[u],b+out[u]+1,greater<int>());   
    }

    for(int u=1;u<=n;++u) cout<<b[in[u]]<<' ';
    cout<<endl;
}

int main()
{
    //File();
    Inp();
    //Brute_Force();
    Solve();

    return 0;
}