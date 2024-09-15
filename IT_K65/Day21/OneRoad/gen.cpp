#include "testlib.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long 
#define MAX 200010

int n,q;
vector<int> g[MAX], save;
int d[MAX];

long long ran(long long L,long long R) 
{
    long long res = 0;
    for(int i=0;i<4;++i) 
        res = (res*(1<<15))^(rnd.next(0, 32627)&((1<<15)-1));

    return L + res%(R-L+1);
}

void dfs(int u)
{
    queue<int> q;
    q.push(u);
    d[u] = 1;

    while(q.size())
    {
        int v=q.front();
        save.push_back(v);
        q.pop();
        for(int k:g[v]) if(d[k]==0)
        {
            d[k] = d[v]+1;
            q.push(k);
        }
    }
}

void Gen(int limit)
{
    int n,m,p;
    if(limit <= 20){
         n = ran(5, 1000);
         m = ran(n,1000);
         p = ran(1, n);
    }
    else 
    if(limit <= 36) {
        n = ran(2000, 100000);
        m = ran(n, 100000);
        p = ran(1, n);
    }
    else 
    if(limit <= 40){
        n = 100000;
        m = 100000;
        p = ran(1, n);
    }
    cout<<n<<' '<<m<<endl;

    for(int i=1;i<=m;++i)
    {
        int u = ran(1, n);
        int v = ran(1, n);
        cout<<u<<' '<<v<<'\n';
    }
    cout<<p<<'\n';

    while(p>0)
    {
        for(int v=1;v<=n;++v) d[v] = 0;
        int u = ran(1,n);
        for(int v:save) d[v]=0;
        dfs(u);

        for(int v:save)
        {
            if(p==0) break;
            cout<<u<<' '<<v<<'\n';
            --p;
        }  
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