#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define MAX 400010

int n,q;
vector<int> vec;
int nt[MAX];

long long ran(long long L,long long R) 
{
    long long res = 0;
    for(int i=0;i<4;++i) 
        res = (res*(1<<15))^(rnd.next(0, 32767)&((1<<15)-1));

    return L + res%(R-L+1);
}

void snt()
{
    vec.push_back(1);
    for(int i=2;i<=400000;++i) if(nt[i]==0)
    {
        vec.push_back(i);
        for(int j=i*2;j<=400000;j+=i) nt[j]=1;
    }
}

void Gen(int limit)
{
    int n,m;
    if(limit <= 20){
         n = ran(5, 1000);
         m = ran(1, min(n,800));
    }
    else 
    if(limit <= 36) {
        n = ran(2000, 300000);
        m = ran(1, min(n,800));
    }
    else 
    if(limit <= 40){
        n = 300000;
        m = 800;
    }
    cout<<n<<endl;

    snt();

    for(int i=1;i<=n;++i)
    {
        int x=1;
        int sln = ran(1,20);
        int pos = vec.size()-1;

        for(int j=1;j<=sln;++j)
        {
            while(vec[pos]>(n/x)) --pos;
            if(pos==0) break;
            x*=vec[ran(0, pos)];
        } 

        cout<<x;
        if(i<n) cout<<' ';
    }

    cout<<endl;
    cout<<ran(1,n)<<' '<<ran(1,n)<<endl;
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