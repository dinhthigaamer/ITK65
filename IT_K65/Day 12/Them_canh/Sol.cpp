#include<bits/stdc++.h>
using namespace std;

#define MAX 100010
int n, q;
vector<int> g[MAX];
int h[MAX];
int par[MAX][18];

void dfs(int u, int cha)
{
    for(int v:g[u]) if(v!=cha)
    {
        h[v] = h[u]+1;
        par[v][0] = u;
        dfs(v, u);
    }
}

void make_rmq()
{
    for(int i = 1; i <= 17; ++i)
    {
        for(int u = 1; u <= n; ++u)
        {
            par[u][i] = par[par[u][i-1]][i-1];
        }
    }
}

int getLca(int u, int v)
{
    if(h[u] > h[v]) swap(u, v);
    int tmp = h[v] - h[u];

    for(int i = 17; i >= 0; --i) if(tmp >= (1<<i))
    {
        tmp -= (1<<i);
        v = par[v][i];
    }

    for(int i = 17; i >= 0; --i) if(par[u][i] != par[v][i])
    {
        u = par[u][i];
        v = par[v][i];
    }

    while(u != v) u = par[u][0], v = par[v][0];

    return u;
}

int getDist(int u, int v)
{
    int p = getLca(u, v);
    return (h[u] + h[v] - 2*h[p]);
}

int main()
{
    //freopen("file.inp", "r", stdin);
    //freopen("file.out", "w", stdout);
    cin >> n >> q;

    for(int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    make_rmq();

    for(int i = 1; i <= q; ++i)
    {
        int u, v, t1, t2;
        cin >> u >> v >> t1 >> t2;

        int D1 = getDist(u, v);
        int D2 = getDist(u, t1) + getDist(v, t2) + 1;
        int D3 = getDist(u, t2) + getDist(v, t1) + 1;

        cout << min({D1, D2, D3}) << '\n';
    }
    return 0;
}