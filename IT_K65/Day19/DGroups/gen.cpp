#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 200010

int n,q;

int ran(int L,int R) 
{
    int range = R-L+1;
    int k1 = rnd.next(0, R-L);
    int k2 = rnd.next(0, R-L);
    return L + 1ll*k1*k2%range;
}

void Gen(int limit)
{
    int n,m;
    if(limit <= 20){
         n = ran(5, 100);
         m = ran(1, min(n,800));
    }
    else 
    if(limit <= 36) {
        n = ran(500, 4000);
        m = ran(1, min(n,800));
    }
    else 
    if(limit <= 40){
        n = 4000;
        m = 800;
    }
    cout<<n<<' '<<m<<endl;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int x=ran(0,9);
            if(i==j) cout<<0;
            else cout<<x;
            if(j<n) cout<<' ';
        }
        cout<<'\n';
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