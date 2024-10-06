#include<bits/stdc++.h>
using namespace std;

#define MAX 300001
#define ll long long
const int sqrtN = 550;

struct node
{
    ll val;
    node* child[26];

    node()
    {
        val = -1;
        for(int i=0;i<=25;++i) child[i]=NULL;
    }

    int valid(int u)
    {
        if(child[u]==NULL) return 0;
        return 1;
    }
};

int n,m;
string s[MAX];
int p[MAX];
ll val[100010], maxval[100010];
ll dp[MAX];
node* root;
vector<int> g[MAX];
vector<int> fat;

void upTrie(string S, ll val)
{
    node* u=root;
    for(int i=0;i<S.size();++i)
    {
        int ch=S[i]-'A';
        if(!u->valid(ch)) u->child[ch] = new node();
        u = u->child[ch];
    }
    u->val = max(u->val, val);
}

ll getTrie(string S)
{
    node* u=root;
    ll maxvalue=0;
    for(int i=0;i<(int)S.size()-1;++i)
    {
        int ch=S[i]-'A';
        if(!u->valid(ch)) break;
        u = u->child[ch];
        maxvalue = max(maxvalue, u->val);
    }
    return maxvalue;
}

void upPair(int u,ll value)
{
    if(value > val[u])
    {
        val[u] = value;
        for(int v:fat)
        {
            auto it = lower_bound(g[u].begin(), g[u].end(), v);
            if(it!=g[u].end() && (*it)==v)
            {
                maxval[v] = max(maxval[v], value);
            }
        }
    }
}

ll findPair(int u)
{
    if(g[u].size() >= sqrtN)
    {
        return maxval[u];
    }
    
    ll res=0;
    for(int v:g[u]) res=max(res, val[v]);
    return res;
}

void solve()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        cin>>p[i];
    }  

    root = new node();

    for(int u,v,i=1;i<=m;++i)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(u>v) swap(u,v);
    }

    for(int i=0;i<=100000;++i) 
    {
        sort(g[i].begin(), g[i].end());
        if(g[i].size() >= sqrtN) fat.push_back(i);
    }

    for(int i=n;i>=1;--i)
    {
        dp[i] = getTrie(s[i]); 
        dp[i] = max(dp[i], findPair(p[i]));
        //cout<<i<<' '<<getTrie(s[i])<<' '<<findPair(p[i])<<endl;
        dp[i] += p[i];

        upTrie(s[i], dp[i]);
        upPair(p[i], dp[i]);
    } 

    //for(int i=1;i<=n;++i) cout<<dp[i]<<' ';
    //cout<<endl;

    cout<<*max_element(dp+1,dp+n+1)<<endl;
}

int main() 
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    int test=1;
    //cin>>test;

    while(test--) 
    {
        solve();
    }

    return 0;
}
