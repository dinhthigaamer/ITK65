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
         m = ran(n,6000);
         p = ran(1, n);
    }
    else 
    if(limit <= 36) {
        n = ran(2000, 3000);
        m = ran(n, 6000);
        p = ran(1, n);
    }
    else 
    if(limit <= 40){
        n = 3000;
        m = 6000;
        p = ran(1, n);
    }
    cout<<n<<' '<<m<<endl;

    set<pair<int,int>> s;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j) s.insert({i,j});
    }

    vector<int> v1={1}, v2;
    for(int i=2;i<=n;++i) v2.push_back(i);

    for(int i=1;i<n;++i)
    {
        int x=ran(0, v1.size()-1);
        int y=ran(0, v2.size()-1);

        cout<<v1[x]<<' '<<v2[y]<<'\n';
        s.erase({min(v1[x], v2[y]), max(v1[x], v2[y])});

        swap(v2[y], v2.back());
        v1.push_back(v2.back());
        v2.pop_back();
    }

    vector<int> vec(s);
    for(int i=n;i<=m;++i) {
        int pos = ran(0, vec.size()-1);
        cout<<vec[pos].first<<' '<<vec[pos].second<<'\n';

        swap(vec[pos], vec.back());
        vec.pop_back();
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