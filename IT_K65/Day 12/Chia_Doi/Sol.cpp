#include<bits/stdc++.h>
using namespace std;

#define MAX 50005
int n, m;
int U[MAX], V[MAX];
vector<int> g[MAX];
vector<int> arr;
int color[MAX];
bitset<50001> dp;
int cnt1, cnt2;

int check_bipartile(int u)
{
    if(color[u] == 1) ++cnt1;
    else ++cnt2;

    for(int v:g[u])
    {
        if(color[v] == 0)
        {
            color[v] = 3 - color[u];
            if(check_bipartile(v) == 0) return 0;
        }
        else 
        if(color[v] != color[u]) continue;
        else 
        if((color[v] == color[u])) return 0;
    }

    return 1;
}

int check(int k)
{
    arr.clear();

    for(int i = 1; i <= n; ++i)
    {
        g[i].clear();
        color[i] = 0;
    }

    for(int i = 1; i <= k; ++i)
    {
        g[U[i]].push_back(V[i]);
        g[V[i]].push_back(U[i]);
    }

    for(int i = 1; i <= n; ++i) if(color[i] == 0)
    {
        color[i] = 1;
        cnt1 = 0; cnt2 = 0;
        if(check_bipartile(i) == 0) return 0;
        arr.push_back(cnt1);
        arr.push_back(cnt2);
    }
    
    dp &= 0;
    dp.set(0);
    
    int sum = 0;

    //cout << k << endl;
    //for(int u : arr) cout << u << ' ';
    //cout << endl;
    for(int u : arr)
    {
        sum += u;
        dp |= (dp << u);
    }

    //for(int i = 0; i <= 6; ++i) cout << dp[i] << ' ';
    //cout << endl;

    for(int i = n/2; i >= 0; --i) if((dp[i] == 1) && (sum - i <= n/2))
    {
        return 1;
    }

    return 0;
}

int main()
{
    //freopen("file.inp", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> U[i] >> V[i];
    }

    int low = 1, high = m, ans = 0;

    //check(3);

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(check(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << ans << endl;

    return 0;
}