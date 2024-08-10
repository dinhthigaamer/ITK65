#include "testlib.h"

#define MAX 100010

int n, q;
int par[MAX];

int Find(int u)
{
    return (par[u] < 0)?u : (par[u] = Find(par[u]));
}

int match(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if(u == v) return 0;
    if(par[u] > par[v])
    {
        par[v] += par[u];
        par[u] = v;
    }
    else
    {
        par[u] += par[v];
        par[v] = u;
    }

    return 1;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    q = inf.readInt(1, 100000, "q");
    inf.readEoln();

    for(int i = 1; i <= n; ++i) par[i] = -1;
    for(int i = 1; i < n; ++i)
    {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");

        inf.readEoln();
        ensuref(match(u, v) == 1, "Not a tree");
    }   

    for(int i = 1; i <= q; ++i)
    {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readSpace();
        int t1 = inf.readInt(1, n, "t1");
        inf.readSpace();
        int t2 = inf.readInt(1, n, "t2");
        if(i < q) inf.readEoln();
    }

    inf.readEoln();
    inf.readEof();
}