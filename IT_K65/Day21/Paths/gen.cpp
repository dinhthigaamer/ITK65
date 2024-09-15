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

void Gen(int limit)
{
    int n,m,p;
    if(limit <= 20){
         n = ran(5, 1500);
         m = ran(n,5000);
         p = ran(1, n);
    }
    else 
    if(limit <= 36) {
        n = ran(5, 1500);
        m = ran(n, 5000);
        p = ran(1, n);
    }
    else 
    if(limit <= 40){
        n = 1500;
        m = 5000;
        p = ran(1, n);
    }
    cout<<n<<' '<<m<<endl;

    for(int i=1;i<=m;++i)
    {
        int u = ran(1, n);
        int v = ran(1, n);
        while(u==v) v=ran(1,n);
        int p = ran(1, 10000);
        cout<<u<<' '<<v<<' '<<p<<'\n';
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