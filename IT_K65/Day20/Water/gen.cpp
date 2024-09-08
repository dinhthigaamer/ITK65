#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 200010

int n,q;

long long ran(long long L,long long R) 
{
    long long res = 0;
    for(int i=0;i<4;++i) 
        res = (res*(1<<15))^(rnd.next(0, 32627)&((1<<15)-1));

    return L + res%(R-L+1);
}

void Gen(int limit)
{
    int n,m;
    if(limit <= 20){
         n = ran(5, 1000);
         m = ran(1, min(n,800));
    }
    else 
    if(limit <= 36) {
        n = ran(2000, 1000000);
        m = ran(1, min(n,800));
    }
    else 
    if(limit <= 40){
        n = 1000000;
        m = 800;
    }
    cout<<n<<endl;

    for(int i=1;i<=n;++i)
    {
        ll x = ran(1, 1000000000);
        cout<<x;
        if(i<n) cout<<' ';
    }
    cout<<endl;
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