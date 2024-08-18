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
         n = ran(5, 100);
         m = ran(5, 100);
    }
    else 
    if(limit <= 12) {
        n = ran(5, 100);
        m = ran(5, 100);
    }
    else 
    if(limit <= 17){
        n = ran(4, 100);
        m = ran(5, 100);
    }
    else {
        n = 100;
        m = 100;
    }
    cout<<n<<endl;

    for(int i=1;i<=n;++i) {
        int x = ran(-5000, 5000);
        int y = ran(-5000, 5000);
        cout<<x<<' '<<y<<'\n';
    }

    cout<<m<<endl;
    cout<<"-10000 -10000"<<endl;
    cout<<"-10000 10000"<<endl;
    cout<<"10000 10000"<<endl;
    cout<<"10000 -10000"<<endl;
    for(int i=1;i<=m-1;++i) {
        int x = ran(-10000, 10000);
        int y = ran(-10000, 10000);
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