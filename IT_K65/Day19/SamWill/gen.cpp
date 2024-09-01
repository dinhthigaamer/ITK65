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
        n = ran(500, 1000);
        m = ran(1, min(n,800));
    }
    else 
    if(limit <= 40){
        n = 200000;
        m = 800;
    }
    cout<<n<<endl;

    for(int i=1;i<=n;++i)
    {
        int w = ran(0, 10000);
        int d = ran(0, 10000);
        cout<<w<<' '<<d<<'\n';
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