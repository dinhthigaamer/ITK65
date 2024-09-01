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
         n = ran(5, 1000);
         m = ran(5, 1000);
    }
    else 
    if(limit <= 36) {
        n = ran(5000, 50000);
        m = ran(5000, 50000);
    }
    else 
    if(limit <= 40){
        n = 50000;
        m = 50000;
    }
    cout<<n<<endl;

    int lmao = min(10000, n);
    int tmpx=0, tmpy=1000001;

    for(int i=1;i<=lmao;++i)
    {
        int x = ran(tmpx+1,ran(tmpx+1, 1000000-(n-i)));
        int y = ran(n-i, ran(n-i, tmpy-1));
        tmpx=x; tmpy=y;
        cout<<x<<' '<<y<<'\n';
    }
    for(int i=1;i<=n-lmao;++i) {
        int x = ran(1, ran(1, 1e4));
        int y = ran(1, ran(1, 1e4));
        cout<<x<<' '<<y<<'\n';
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