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
         n = ran(5, 3000);
         m = ran(5,3000);
         p = ran(1, n);
    }
    else 
    if(limit <= 36) {
        n = ran(5000, 100000);
        m = ran(5, 100000);
        p = ran(1, n);
    }
    else 
    if(limit <= 40){
        n = 100000;
        m = 100000;
        p = ran(1, n);
    }
    
    cout<<n<<' '<<m<<endl;

    vector<int> vec;
    for(int i=1;i<=n;++i) {
        int x = ran(0, 2e9) - 1e9;
        vec.push_back(x);
    }
    
    for(int i=1;i<=n;++i) {
        int x = vec[ran(0, n-1)];
        cout<<x;
        if(i<n) cout<<' ';
    }

    cout<<endl;
    for(int i=1;i<=m;++i) {
        int dis = ran(0, n-1);
        int L = ran(1, n - dis);
        int R = L + dis;

        cout<<L<<' '<<R<<'\n';
    }

    // vector<pair<int,int>> vec(s.begin(), s.end());
    // for(int i=n;i<=m;++i) {
    //     int pos = ran(0, vec.size()-1);
    //     cout<<vec[pos].first<<' '<<vec[pos].second<<'\n';

    //     swap(vec[pos], vec.back());
    //     vec.pop_back();
    // }
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