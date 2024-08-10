#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 100010

int n,q;
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

int Find_vertex(int u,int depth)
{
    if(depth == 0) return u;
    for(int v:g[u]) if(v != par[u][0])
    {
        Find_vertex(v, depth - 1);
        break;
    }

    return u;
}

int Find(int u)
{
    int ran = rnd.next(0,1);
    if(ran == 0)
    {
        int height = rnd.next(0, h[u]);
        for(int i = 17; i >= 0; --i) if(height >= (1<<i))
        {
            u = par[u][i];
            height -= (1<<i);
        }
    }
    else 
    {
        int low = rnd.next(0, 15);
        u = Find_vertex(u, low);
    }
    return u;
}

void Gen(int limit)
{
    if(limit == 1) n = rnd.next(2, 1000), q = rnd.next(1, 1000);
    else 
    if(limit == 2) n = 1000, q = 1000;
    else 
    if(limit == 3) n = rnd.next(5000, 100000), q = rnd.next(5000, 100000);
    else 
    n = 100000, q = 100000;

    cout << n << ' ' << q << '\n';

    vector<int> v1, v2;

    v1.push_back(1);
    for(int i = 2; i <= n; ++i) v2.push_back(i);

    for(int i = 1; i < n; ++i)
    {
        int u = v1[rnd.next(0, (int)v1.size() - 1)];
        int v = v2.back();

        cout << u << ' ' << v << '\n';

        v1.push_back(v2.back());
        v2.pop_back();

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1);
    make_rmq();

    for(int i = 1; i <= q; ++i)
    {
        int u, v, t1, t2;
        u = rnd.next(1, n);
        v = rnd.next(1, n);
        t1 = Find(u);
        t2 = Find(v);

        cout << u << ' ' << v << ' ' << t1 << ' ' << t2 << '\n';
    }
}

void File()
{
    freopen("file.inp","w",stdout);
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    //File();
    int value_t = opt<int>("value_t"); 
    int order = opt<int>("order");

    Gen(value_t);
    

    return 0;
}