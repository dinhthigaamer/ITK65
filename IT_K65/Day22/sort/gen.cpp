#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;
#define ll long long 
#define MAX 200010

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
         n = ran(5, 1000);
         m = ran(n,1000);
         p = ran(1, n);
    }
    else 
    if(limit <= 36) {
        n = ran(2000, 100000);
        m = ran(n, 100000);
        p = ran(1, n);
    }
    else 
    if(limit <= 40){
        n = 100000;
        m = 100000;
        p = ran(1, n);
    }
    cout<<n<<endl;
    for(int i=1;i<=n;++i) {
        cout<<ran(1,1e9);
        if(i<n) cout<<' ';
    }
    cout<<endl;

    if(limit==40)
    {
        for(int i=1;i<n;++i) cout<<i<<' '<<i+1<<'\n';
        cout<<m<<endl;
        for(int i=1;i<=m;++i) cout<<1<<' '<<1<<'\n';
        return ;
    }

    vector<int> v1={1}, v2;
    for(int i=2;i<=n;++i) v2.push_back(i);

    for(int i=1;i<n;++i)
    {
        int x=ran(0, v1.size()-1);
        int y=ran(0, v2.size()-1);

        cout<<v1[x]<<' '<<v2[y]<<'\n';
        swap(v2[y], v2.back());
        v1.push_back(v2.back());
        v2.pop_back();
    }

    cout<<m<<endl;
    for(int i=1;i<=m;++i) {
        cout<<ran(0,1)<<' '<<ran(1,n)<<'\n';
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