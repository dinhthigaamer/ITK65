#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 200010

int n,q;

int new_ran(int L,int R) 
{
    int range = R-L+1;
    int k1 = rnd.next(0, R-L);
    int k2 = rnd.next(0, R-L);
    return (int)(L + 1ll*k1*k2%range);
}

void Gen(int limit)
{
    int n;
    long long m;
    if(limit <= 20){
         n = new_ran(5, 1000);
         m = rnd.next(1ll, 1000000000000);
    }
    else 
    if(limit <= 36) {
        n = new_ran(5000, 250000);
        m = rnd.next(1ll, 1000000000000);
    }
    else 
    if(limit <= 40){
        n = 250000;
        m = rnd.next(1ll, 1000000000000);
    }
    cout<<n<<' '<<m<<endl;

    int tmp=0;
    for(int i=1;i<=n;++i) {
        int x = new_ran(tmp+1, 1000000-(n-i));
        tmp = x;
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