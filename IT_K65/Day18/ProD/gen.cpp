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
    if(limit <= 8){
         n = ran(5, 1000);
    }
    else 
    if(limit <= 20) {
        n = ran(2000, 10000);
    }
    else 
    if(limit <= 37){
        n = ran(10000, 1000000);
    }
    else {
        n = 1000000;
    }
    cout<<n<<endl;

    int a,b,c;

    a = ran(-5, -1);
    b = ran(-10000000, 10000000);
    c = ran(-10000000, 10000000);

    cout<<a<<' '<<b<<' '<<c<<endl;

    for(int i=1;i<=n;++i) {
        int x = ran(1, 100);
        cout<<x;
        if(i<n) cout<<' ';    
    }
    cout<<'\n';
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