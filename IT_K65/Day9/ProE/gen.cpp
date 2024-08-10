#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 200010

int n,q;

void Gen(int limit)
{
    int n = rnd.next(2e0,2e5);
    int m = rnd.next(1e0,2e5);

    cout<<n<<' '<<m<<endl;

    for(int i=1;i<=m;++i)
    {
        int l = rnd.next(1,n);
        int r = rnd.next(l,n);
        int p = rnd.next(-1e9,1e9);
        cout<<l<<' '<<r<<' '<<p;
        
        if(i<m) cout<<'\n';
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