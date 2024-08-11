#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 200010

int n,q;
int a[MAX];

int ran(int L,int R) 
{
    int range = R-L+1;
    int k1 = rnd.next(0, R-L);
    int k2 = rnd.next(0, R-L);
    return L + 1ll*k1*k2%range;
}

struct sinhcay
{
    void solve(int N,int weight = 0)
    {
        vector<int> v1={},v2={};
        v1={1};
        for(int i=2;i<=N;++i) v2.push_back(i);

        shuffle(v2.begin(),v2.end());

        for(int i=1;i<N;++i)
        {
            int p1=ran(0,(int)v1.size()-1);
            int p2=ran(0,(int)v2.size()-1);
            int w=ran(1,1000000000);
            
            //g[v1[p1]].push_back(v2[p2]);
            //g[v2[p2]].push_back(v1[p1]);
            if(weight) cout<<i<<' '<<i+1;
            else 
            cout<<v1[p1]<<' '<<v2[p2];
            //if(weight) cout<<' '<<w;

            cout<<'\n';

            v1.push_back(v2[p2]);
            swap(v2[p2],v2.back());
            v2.pop_back();
        }
    }
}sc;

vector<int> save;

void qr(int type, int n, int m) {
    if(type == 1) {
        int x = ran(0, (int)save.size()-1);
        cout << "D " << save[x] << '\n';

        swap(save[x], save.back());
        save.pop_back();
    }
    else {
        int u = ran(1, n);
        int x = ran(-1000000000, 1000000000);

        cout<<"C "<<u<<' '<<x<<'\n';
    }
}

void Gen(int limit)
{
    int n,m,q;
    if(limit <= 6){
         n = ran(1, 1000);
         m = ran(n, 1000);
         q = ran(1, 1000);
    }
    else 
    if(limit <= 17){
        n = ran(1, 100000);
        m = ran(n, 100000);
        q = ran(1, 100000);
    }
    else {
        n = 100000;
        m = 100000;
        q = 100000;
    }
    cout<<n<<' '<<m<<' '<<q<<endl;

    for(int i=1;i<=m;++i) save.push_back(i);

    for(int i=1;i<=n;++i) {
        a[i] = ran(-1000000000, 1000000000);
        cout<<a[i];
        if(i<n) cout<<' ';
    }
    cout<<endl;
    sc.solve(n);
    for(int i=1;i<=m-n+1;++i) {
        int L = ran(1,n);
        int R = ran(1,n);
        while(R == L) R = ran(1,n);
        cout<<L<<' '<<R<<'\n'; 
    }

    for(int i=1;i<=q;++i) {
        int type;
        if(limit <= 6) {
            if(save.size()) qr(ran(0,1), n, m);
            else 
            qr(0, n, m);
        }
        else 
        if(limit <= 12){
            qr(0, n, m);
        }
        else {
            if(save.size()) qr(ran(0,1), n, m);
            else
            qr(0, n, m);
        }
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