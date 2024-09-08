#include<bits/stdc++.h>
using namespace std;

#define MAX 600010
#define ll long long 
const int add=300000;

int n;
int a[MAX];
int s,t;
int dis[MAX];
vector<pair<int,int>> g[MAX];
int trace[MAX];
int appear[MAX];

void Trace()
{
    vector<int> vec;
    int u=a[t]+add;

    while(u>0)
    {
        if(u>add) vec.push_back(appear[u-add]);
        u=trace[u];
    }

    reverse(vec.begin(),vec.end());
    vec[0]=s;
    vec.back()=t;

    cout<<vec.size()<<endl;
    for(int i:vec) cout<<i<<' ';
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(!appear[a[i]]) appear[a[i]]=i;
    }
    cin>>s>>t;
    
    if(s==t)
    {
        cout<<1<<endl;
        return ;
    }
    if(a[s]==1 || a[t]==1)
    {
        puts("-1");
        return ;
    }
    if(a[s]==a[t] && s!=t)
    {
        cout<<2<<endl;
        return ;
    }
    memset(dis,-1,sizeof(dis));

    for(int i=2;i<=300000;++i)
    {
        for(int j=i;j<=300000;j+=i) if(appear[j])
        {
            int u=j+add;
            int v=i;

            g[u].push_back({v,0});
            g[v].push_back({u,1});
        }
    }
    
    deque<int> dq;
    dis[a[s]+add]=0;

    dq.push_back(a[s]+add);

    while(dq.size())
    {
        int u=dq.front();
        dq.pop_front();

        for(auto it:g[u])
        {
            int v=it.first, w=it.second;

            if(w==0)
            {
                if(dis[v]==-1 || dis[v]>dis[u])
                {
                    dis[v]=dis[u];
                    trace[v]=u;
                    dq.push_front(v);
                }
            }
            else 
            {
                if(dis[v]==-1 || dis[v]>dis[u]+1)
                {
                    dis[v]=dis[u]+1;
                    trace[v]=u;
                    dq.push_back(v);
                }
            }
        }
    }

    if(dis[a[t]+add]==-1)
    {
        puts("-1");
        return ;
    }
    else 
    cout<<dis[a[t]+add]+1<<endl;
    //cout<<dis[a[t]+add]<<endl;
}

void File()
{
    freopen("file.inp","r",stdin);
    freopen("file.out","w",stdout);
}

int main()
{
    //File();

    int test=1;
    //cin>>test;

    while(test--)
    {
        solve();
    }

    return 0;
}