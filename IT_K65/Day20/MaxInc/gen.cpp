#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;
#define ll long long 
#define MAX 400010

int n,q;
vector<int> vec;

long long ran(long long L,long long R) 
{
    long long res = 0;
    for(int i=0;i<4;++i) 
        res = (res*(1<<15))^(rnd.next(0, 32767)&((1<<15)-1));

    return L + res%(R-L+1);
}

void Gen(int limit)
{
    int n,m;
    if(limit <= 20){
         n = ran(5, 1000);
         m = ran(5, 1000);
    }
    else 
    if(limit <= 36) {
        n = ran(2000, 100000);
        m = ran(2000, 100000);
    }
    else 
    if(limit <= 40){
        n = 100000;
        m = 100000;
    }
    cout<<n<<' '<<m<<endl;

    for(int i=1;i<=n;++i)
    {
        cout<<ran(0,1);
    }

    cout<<endl;

    for(int i=1;i<=m;++i)
    {
        int dice = ran(0,1);
        if(i==m) dice=1;

        if(dice==0)
        {
            cout<<"switch "<<ran(1,n)<<'\n';
        }
        else 
        {
            cout<<"count\n";
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