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
    if(limit <= 6){
         n = ran(5, 500);
         m = ran(5, 500);
    }
    else 
    if(limit <= 12) {
        n = ran(510, 2000);
        m = ran(1, 500000);
    }
    else 
    if(limit <= 17){
        n = ran(3000, 100000);
        m = ran(1, 500000);
    }
    else {
        n = 100000;
        m = 100000;
    }
    cout<<n<<endl;

    for(int i=1;i<=n+1;++i) {
        int x = ran(-1000000000, 1000000000);
        int y = ran(-1000000000, 1000000000);
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