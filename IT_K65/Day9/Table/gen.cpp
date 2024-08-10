#include "testlib.h"
#include <iostream>

using namespace std;
#define ll long long 

int test;
int A,B,C,D;

void Gen(int limit)
{
    int n,m;
    n = rnd.next(1, 400);
    m = rnd.next(1, 400);

    if(limit==2) n=400, m=400;
    cout<<m<<' '<<n<<endl;

    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            char x = rnd.next('A', 'E');
            cout<<x;
        }
        if(i<m) cout<<'\n';
    }

    cout<<endl;
}

void File()
{
    
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    //File();
    int value_t = opt<int>("value_t"); 
    int order = opt<int>("order");

    Gen(value_t);
    //Gen(0);

    return 0;
}