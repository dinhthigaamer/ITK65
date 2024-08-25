#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 
#define MAX 200010

int n,q;
int x[MAX], y[MAX];

int ran(int L,int R) 
{
    int range = R-L+1;
    int k1 = rnd.next(0, (R-L));
    int k2 = rnd.next(0, (R-L));
    int k3 = rnd.next(0, 2*(R-L));
    return L + (1ll*k1*k2%range+k3)%range;
}

void Gen(int limit)
{
    int n,m;
    if(limit <= 20){
         n = ran(5, 5000);
         m = ran(5, 5000);
    }
    else 
    if(limit <= 36) {
        n = ran(5000, 100000);
        m = ran(5000, 100000);
    }
    else 
    if(limit <= 40){
        n = 100000;
        m = 100000;
    }
    cout<<n<<endl;
    
    x[0]=0;
    y[0]=0;

    for(int i=1;i<=n;++i) {
        x[i] = ran(x[i-1]+1, 1000000000-1-(n-i));
        y[i] = ran(y[i-1]+1, 1000000000-1-(n-i));
    }
    int dice = ran(0,1);
    for(int i=1;i<=n;++i) {
        int a = ran(0, 1ll*x[i]*y[n-i+1]%1000000000);
        if(dice == 0) cout<<x[i]<<' '<<y[n-i+1]<<' '<<a<<'\n';
        else cout<<y[n-i+1]<<' '<<x[i]<<' '<<a<<'\n';
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