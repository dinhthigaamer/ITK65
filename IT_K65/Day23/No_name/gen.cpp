#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;
#define ll long long 
#define MAX 200010

string S[300010];

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
         n = ran(5, 100);
         m = ran(5, 100);
         p = ran(1, n);
    }
    else 
    if(limit <= 36) {
        n = ran(5000, 300000);
        m = 0;
        p = ran(1, n);
    }
    else 
    if(limit <= 40){
        n = 300000;
        m = 300000;
        p = ran(1, n);
    }
    
    cout<<n<<endl;

    vector<int> vec;
    for(int i=1;i<=n;++i) {
        int x = ran(0, 1e5);
        vec.push_back(x);
    }
    
    vector<int> par = {0};
    int maxlen;

    if(limit<=20) maxlen = 100 - (n-1);
    else maxlen = 1e6 - (n-1);

    for(int i=1; i<=n; ++i) {
        int x = par[ran(0, par.size()-1)];
        int len = 0;

        if(x==0) {
            string s = "";
            len = ran(1, maxlen);
            for(int j=1; j<=len; ++j) {
                s += (char)ran('A', 'Z');
            }
            S[i] = s;
        }
        else {
            len = ran(1, max(S[x].size()-1, maxlen));
            for(int j=0; j<len; ++j) {
                S[i] += S[x][j];
            }
        }

        maxlen = maxlen - len + 1;
        par.push_back(i);
        par.push_back(0);
    }

    for(int i=1;i<=n;++i) cout<<S[i]<<'\n'<<vec[ran(0, n-1)]<<'\n';

    cout<<m<<endl;

    for(int i=1;i<=m;++i) {
        int x = vec[ran(0, n-1)];
        int y = vec[ran(0, n-1)];
        cout<<x<<' '<<y<<'\n';
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