#include<bits/stdc++.h>
using namespace std;

#define MAX 200010
#define ll long long 
int n,m;
int a[MAX];
vector<int> lmao;
set<int> ms;
unordered_map<int,vector<int>> adj;
unordered_map<int,int> in, in2, dp;

void ghi(int x)
{
    cout<<(char)(x+'a');
}

void find_mex(int id)
{
    vector<int> mex;

    lmao.push_back(-1);
    sort(lmao.begin(), lmao.end());
    lmao.push_back((int)2e9);

    for(int i=0;i<lmao.size() && mex.size()<2; ++i)
    {
        if(lmao[i]+1<lmao[i+1]) mex.push_back(lmao[i]+1);
        if(lmao[i]+2<lmao[i+1]) mex.push_back(lmao[i]+2);
    }
    
    ms.insert(mex[0]);

    adj[mex[1]].push_back(mex[0]);
    in[mex[0]]++;
    in2[mex[0]]++;
}

void reset()
{
    ms.clear();
    in.clear(); in2.clear();
    dp.clear();
    adj.clear();
}

void dp_on_dag()
{
    stack<int> st;

    for(auto it:adj) if(in.find(it.first) == in.end())
    {
        st.push(it.first);
    }

    while(st.size())
    {
        int u = st.top();
        st.pop();
        dp[u]=max(dp[u], u);

        for(int v:adj[u])
        {
            dp[v] = max(dp[v],dp[u]);
            --in[v];
            if(in[v]==0) st.push(v);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int l,i=1; i<=n; ++i)
    {
        cin>>l;
        for(int j=1;j<=l;++j) {
            int x;
            cin>>x;
            lmao.push_back(x);
        }
        find_mex(i);
        lmao.clear();
    }

    dp_on_dag();

    ms.insert(m+1);
    
    int max_mex0 = 0;
    for(auto it:in2) 
    {
        int u = it.first;
        if(in2[u]==1) max_mex0 = max(max_mex0, u);
        else 
        max_mex0 = max(max_mex0, dp[u]);
    }

    ll res = 0;
    ll tmp = -1;

    for(auto it:ms) 
    {
        int L = tmp+1;
        int R = min(m, it-1);
        
        //cout<<L<<' '<<R<<endl;
        if(L<=R)
        {
            if(max_mex0 < L) 
            {
                res += 1ll*(R+L)*(R-L+1)/2; //cout<<L<<' '<<R<<endl;
            }
            else 
            if(max_mex0 < R)
            {
                res += 1ll*(max_mex0-L+1)*max_mex0;
                res += 1ll*(max_mex0+1+R)*(R-max_mex0)/2;
            }
            else 
            {
                res += 1ll*(R-L+1)*max_mex0;
            }
        }
        
        //cout<<res<<endl;
        if(it<=m) res += max({dp[it], max_mex0, it});
        tmp = it;
    }

    //for(int i=1;i<=n;++i) cout<<mex[i][0]<<' '<<mex[i][1]<<endl;
    //for(auto it:dp) cout<<it.first<<' '<<it.second<<endl;
    //cout<<max_mex0<<' ';
    cout<<res<<'\n';

    reset();
}

int main() 
{
    //freopen("file.inp","r",stdin);
    //freopen("file.out","w",stdout);
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    int test;
    cin>>test;

    while(test--) 
    {
        solve();
    }

    return 0;
}